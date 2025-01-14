#include "core.h"
#include "entity.h"
#include "Window.h"
#include "Resources.h"
#include "Transform.h"
#include <iostream>
#include "Transform.cpp"
#include <AL/al.h>
#include <AL/alc.h>

namespace SoulEngine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		ALCcontext* context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		rtn->m_window = std::make_shared<Window>();
		rtn->m_resources = std::make_shared<Resources>();
		rtn->m_self = rtn;
		return rtn;
	}
	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_Core = m_self;
		rtn->m_self = rtn;
		rtn->add_component<Transform>();
		m_entities.push_back(rtn);

		std::cout << rtn->m_Core.lock().get() << std::endl;

		return rtn;
	}
	std::shared_ptr<Resources> Core::get_resources()
	{
		return m_resources;
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
				if (e.type == SDL_KEYDOWN)
				{
					std::cout << "Key pressed: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
				}
			}
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				auto transform = m_entities[i]->get_component<Transform>();
				if (transform)
				{
					SoulEngine::input(e, *transform);
				}
				for (size_t ei = 0; ei < m_entities.size(); ei++)
				{
					m_entities[ei]->tick();
				}
			}

			

			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);

			for (size_t i = 0; i < m_entities.size(); i++)
			{
				for (size_t ei = 0; ei < m_entities.size(); ei++)
				{
					m_entities[ei]->render();
				}
			}

			SDL_GL_SwapWindow(m_window->m_window);

		}
	}
}