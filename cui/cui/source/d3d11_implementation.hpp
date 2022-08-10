/// d3d11_implementation.hpp

#pragma once

#include "cui.hpp"

namespace cui
{
	class d3d11_renderer: public i_renderer,
						  public singleton< d3d11_renderer >
	{
	private:

	public:

		void init( window & w ) override;
	};

	inline void d3d11_renderer::init( window & w )
	{
		
	}

	inline void init_renderer( window & w )
	{
		( i_renderer::r = &d3d11_renderer::get( ) )->init( w );
	}
}
