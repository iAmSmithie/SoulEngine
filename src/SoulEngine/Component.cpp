#include "Component.h"
#include "Transform.h"
#include "Entity.h"

namespace SoulEngine
{
	void Component::on_initialize() { }
	void Component::on_tick() { }
	void Component::on_render() { }

	void Component::tick()
	{
		on_tick();
	}
	void Component::render()
	{
		on_render();
	}
	std::shared_ptr<Entity> Component::get_entity() const
	{
		auto entity = m_Entity.lock();
		if (!entity)
		{
			throw std::runtime_error("Component's entity is null");
		}
		return entity;
	}
	std::shared_ptr<Transform> Component::get_transform()
	{
		auto entity = get_entity();
		if (!entity) {
			throw std::runtime_error("Entity is null in getTransform()");
		}
		auto transform = entity->get_component<Transform>();
		if (!transform) 
		{
			throw std::runtime_error("Transform component is missing in getTransform()");
		}
		return transform;
	}
}