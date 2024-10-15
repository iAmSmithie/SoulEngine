#include "Component.h"

namespace SoulEngine
{
	void Component::on_initialize() { }
	void Component::on_tick() { }

	void Component::tick()
	{
		on_tick();
	}
}