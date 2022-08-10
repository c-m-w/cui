/// example.cpp

#define CGUI_D3D11

#include "cui.hpp"

void main( )
{
	auto window = cui::window( L"main" );

	window.show( );

	init_renderer( window );

	while( true )
	{
		window.poll_events( );
		cui::i_renderer::r->begin_frame( );
		cui::i_renderer::r->present_frame( );
	}

	return;
}
