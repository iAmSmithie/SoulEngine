
#pragma once

#include <memory>

namespace SoulEngine
{

	struct Entity;


	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();
	private:
		friend struct SoulEngine::Entity;

		std::weak_ptr<Entity> m_Entity;
		void Component::tick();
		void render();
	};
}