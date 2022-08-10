/// window.hpp

#pragma once

#include "cui.hpp"

namespace cui
{
	class window
	{
	private:

		const wchar_t * id;
		HWND wnd = nullptr;

	public:

		static LRESULT __stdcall handle_event( HWND,
											   UINT,
											   WPARAM,
											   LPARAM );

		window( const wchar_t * id );
		~window( );

		void poll_events( );
		void show( ) const;
		void hide( ) const;

		operator HWND( ) const;
	};
}

inline cui::window::window( const wchar_t * id ):
	id { id }
{
	WNDCLASS wc = { };

	wc.lpfnWndProc = handle_event;
	wc.hInstance = GetModuleHandle(nullptr);
	wc.lpszClassName = id;

	RegisterClass(&wc);

	wnd = CreateWindowEx( 0,
						  id,
						  L"",
						  WS_OVERLAPPEDWINDOW,
						  CW_USEDEFAULT, 
						  CW_USEDEFAULT, 
						  CW_USEDEFAULT, 
						  CW_USEDEFAULT,
						  nullptr, 
						  nullptr,
						  GetModuleHandle(nullptr),
						  nullptr );

	if ( nullptr == wnd )
		throw std::runtime_error( "e" );
}

inline cui::window::~window( )
{
	DestroyWindow( wnd );
}

inline void cui::window::poll_events( )
{
	MSG message;

	while( PeekMessage( &message,
						nullptr, 
						0, 
						0, 
						PM_REMOVE ) )
	{
		TranslateMessage( &message );
		DispatchMessage( &message );
	}
}

inline LRESULT __stdcall cui::window::handle_event( HWND hwnd,
													UINT message,
													[[ maybe_unused ]] WPARAM wparam,
													[[ maybe_unused ]] LPARAM lparam)
{
	switch ( message )
	{
		case WM_NCCREATE:
		case WM_CREATE:
		{
			return TRUE;
		}
	}

	return DefWindowProc( hwnd, 
						  message,
						  wparam, lparam);
}

inline void cui::window::show( ) const
{
	ShowWindow( wnd,
				TRUE );
}

inline void cui::window::hide( ) const
{
	ShowWindow( wnd,
				FALSE );}

inline cui::window::operator HWND( ) const
{
	return wnd;
}
