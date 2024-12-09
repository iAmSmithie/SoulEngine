#pragma once
#include "Component.h"

namespace SoulEngine
{
	struct triangleRender : Component
	{
	private:
		void on_initalize();
		void on_render();
	};
}