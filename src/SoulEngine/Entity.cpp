#include "entity.h"
#include "component.h"

namespace SoulEngine
{
	//tick and render all components
	void Entity::tick()
	{
		for (size_t i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->tick();
		}	

	}
	void Entity::render()
	{
		for (size_t i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->render();
		}
	}
	//return the tranform component
	std::shared_ptr<Transform> Entity::get_transform()
	{
		return get_component<Transform>();
	}

}