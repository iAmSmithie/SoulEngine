#include "core.h"
#include "entity.h"
#include <iostream>

namespace SoulEngine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;
		return rtn;
	}
	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_Core = m_self;
		m_entities.push_back(rtn);

		std::cout << rtn->m_Core.lock().get() << std::endl;

		return rtn;
	}
	void Core::start()
	{
		//for(size_t i = 0; i < 25)
	}
}