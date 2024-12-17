#include "Component.h"

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
		return m_Entity.lock();
	}
}