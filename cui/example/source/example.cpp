/// example.cpp

#define CGUI_D3D11

#include "cui.hpp"

//void test( int i )
//{
//	std::cout << i << std::endl;
//}
//
//template< typename... T >
//void test( int i, T... args )
//{
//	std::cout << i << std::endl;
//	test( args... );
//}

void main( )
{
	//test(1, 2, 3 );

	cui::vec2d t( 1, 2 );

	auto window = cui::window( L"main",
							   1200,
							   1200 );

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
