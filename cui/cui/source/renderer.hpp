/// renderer_interface.hpp

#pragma once

#include "cui.hpp"

namespace cui
{
	class i_renderer
	{
	private:

	public:

		inline static i_renderer * r = nullptr;

		virtual void init( window& w ) = 0;
		virtual void cleanup( ) = 0;
		virtual void begin_frame( ) = 0;
		virtual void present_frame( ) = 0;
	};
}
