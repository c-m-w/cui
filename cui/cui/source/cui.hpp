/// cui.hpp

#pragma once

namespace cui
{
#if defined CGUI_D3D11

	class d3d11_renderer;
	using renderer_t = cui::d3d11_renderer;

#endif
}


#include "includes.hpp"
#include "singleton.hpp"
#include "window.hpp"
#include "renderer.hpp"

//#if defined CGUI_D3D11

#include "d3d11_implementation.hpp"

//#endif
