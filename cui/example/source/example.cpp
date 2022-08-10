/// example.cpp

#define CGUI_D3D11

#include "cui.hpp"

void main( )
{
	auto window = cui::window( L"main" );

	window.show( );

	init_renderer( window );

	return;
}
