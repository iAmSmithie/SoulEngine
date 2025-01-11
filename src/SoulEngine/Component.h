
#pragma once

#include <memory>

namespace SoulEngine
{
	struct Entity;
	struct Transform;

	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();
		std::shared_ptr<Entity> get_entity() const;
		std::shared_ptr<Transform> get_transform();
	private:
		friend struct SoulEngine::Entity;

		std::weak_ptr<Entity> m_Entity;
		void Component::tick();
		void render();
	};
}