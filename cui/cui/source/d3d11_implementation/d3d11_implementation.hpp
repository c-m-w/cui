/// d3d11_implementation.hpp

#pragma once

#include "cui.hpp"
#include "shader.hpp"

#include <d3d11.h>
#include <d3dx11.h>

#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib, "d3dx11.lib" )

namespace cui
{
	class d3d11_renderer: public i_renderer,
						  public singleton< d3d11_renderer >
	{
	private:

		IDXGISwapChain * sc = nullptr;
		ID3D11Device * dev = nullptr;
		ID3D11DeviceContext * ctx = nullptr;
		ID3D11RenderTargetView * backbuffer = nullptr;
		ID3D11VertexShader * vs = nullptr;
		ID3D11PixelShader * ps = nullptr;

	public:

		void init( window & w ) override;
		void cleanup( ) override;
		void begin_frame( ) override;
		void present_frame( ) override;
	};

	inline void d3d11_renderer::init( window & w )
	{
		auto scd = DXGI_SWAP_CHAIN_DESC { };
		ID3D11Texture2D * backbuffer_texture = nullptr;
		auto viewport = D3D11_VIEWPORT { };

		scd.BufferCount = 1;
		scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.OutputWindow = w;
		scd.SampleDesc.Count = 4;
		scd.Windowed = TRUE;

		D3D11CreateDeviceAndSwapChain( nullptr,
									   D3D_DRIVER_TYPE_HARDWARE,
									   nullptr,
									   NULL,
									   nullptr,
									   NULL,
									   D3D11_SDK_VERSION,
									   &scd,
									   &sc,
									   &dev,
									   nullptr,
									   &ctx );

		sc->GetBuffer( 0,
					   __uuidof( ID3D11Texture2D ),
					   reinterpret_cast< void ** >( &backbuffer_texture ) );
		dev->CreateRenderTargetView( backbuffer_texture,
									 nullptr,
									 &backbuffer );
		backbuffer_texture->Release( );
		ctx->OMSetRenderTargets( 1,
								 &backbuffer,
								 nullptr );

		viewport.TopLeftX = viewport.TopLeftY = 0;
		viewport.Width = viewport.Height = 400;

		ctx->RSSetViewports( 1,
							 &viewport );

		ID3DBlob * vs_blob = nullptr;
		ID3DBlob * ps_blob = nullptr;

		D3DX11CompileFromMemory( SHADER,
								 strlen( SHADER ),
								 "shader.hpp",
								 nullptr,
								 nullptr,
								 "VShader",
								 "vs_4_0",
								 0,
								 0,
								 0,
								 &vs_blob,
								 nullptr,
								 nullptr );

		D3DX11CompileFromMemory( SHADER,
								 strlen( SHADER ),
								 "shader.hpp",
								 nullptr,
								 nullptr,
								 "PShader",
								 "ps_4_0",
								 0,
								 0,
								 0,
								 &ps_blob,
								 nullptr,
								 nullptr );

		dev->CreateVertexShader( vs_blob->GetBufferPointer( ),
								 vs_blob->GetBufferSize( ),
								 nullptr,
								 &vs );
		dev->CreatePixelShader( ps_blob->GetBufferPointer( ),
								ps_blob->GetBufferSize( ),
								nullptr,
								&ps );

		ctx->VSSetShader( vs,
						  nullptr,
						  0 );
		ctx->PSSetShader( ps,
						  nullptr,
						  0 );
	}

	inline void d3d11_renderer::cleanup( )
	{
		sc->Release( );
		dev->Release( );
		ctx->Release( );
		backbuffer->Release( );
		vs->Release( );
		ps->Release( );
	}

	inline void d3d11_renderer::begin_frame( )
	{
		float color[ ] = { 1.f, 0.f, 0.f, 1.f };

		ctx->ClearRenderTargetView( backbuffer,
									color );
		sc->Present( 0,
					 0 );
	}

	inline void d3d11_renderer::present_frame( )
	{
		
	}

	inline void init_renderer( window & w )
	{
		( i_renderer::r = &d3d11_renderer::get( ) )->init( w );
	}
}
