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
	};
}
