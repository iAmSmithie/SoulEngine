#include "Component.h"
#include <GL/glew.h>
#pragma once

namespace SoulEngine
{
	struct Texture;
	struct triangleRender : Component
	{
	public:
		void set_texture(std::shared_ptr<Texture> tex);
	private:
		void on_initalize();
		void on_render();

		std::shared_ptr<Texture> m_tex;
	};

}