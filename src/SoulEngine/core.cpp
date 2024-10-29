#include "core.h"
#include "entity.h"
#include "Window.h"
#include <SoulEngine/SoulEngine.h>
#include <iostream>

namespace SoulEngine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
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
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				for (size_t ei = 0; ei < m_entities.size(); ei++)
				{
					m_entities[ei]->tick();
				}
			}
		}



	}
}