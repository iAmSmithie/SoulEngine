#include "Component.h"
#include "Transform.h"
#include "Entity.h"

namespace SoulEngine
{
	//functions for rendering, ticks and initialization
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
	//gets the entity that the component is attached to and checks if it is null
	std::shared_ptr<Entity> Component::get_entity() const
	{
		auto entity = m_Entity.lock();
		if (!entity)
		{
			throw std::runtime_error("Component's entity is null");
		}
		return entity;
	}
	//gets the transformation component of the entity that the component is attached to then checks if it is null
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