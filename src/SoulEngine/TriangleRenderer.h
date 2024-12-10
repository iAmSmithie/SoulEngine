#include "Component.h"
#include <GL/glew.h>
#pragma once

namespace SoulEngine
{
	struct Texture;
	struct Model;
	struct triangleRender : Component
	{
	public:
		void set_texture(std::shared_ptr<Texture> tex);
		void set_model(std::shared_ptr<Model> mod);
	private:
		void on_initalize();
		void on_render();

		std::shared_ptr<Texture> m_tex;
		std::shared_ptr<Model> m_mod;
	};

}