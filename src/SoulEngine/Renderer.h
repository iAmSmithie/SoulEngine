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
		//sets the texture and model to render
		void set_texture(std::shared_ptr<Texture> tex);
		void set_model(std::shared_ptr<Model> mod);
	private:
		//renders in the textures and models
		void on_render();

		std::shared_ptr<Texture> m_tex;
		std::shared_ptr<Model> m_mod;
	};

}