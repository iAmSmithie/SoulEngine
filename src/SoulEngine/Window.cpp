#include "Window.h"
#include <Rendy/Rend.h>

namespace SoulEngine
{
	SoulEngine::Window::Window()
	{
		int WINDOW_WIDTH = 800;
		int WINDOW_HEIGHT = 600;

		m_window = SDL_CreateWindow("Soul Window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,  
			WINDOW_WIDTH, WINDOW_HEIGHT, 
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		//Check if OpenGL context creation failed
		if (!SDL_GL_CreateContext(m_window))
		{
			throw std::exception();
		}

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) 
		{
			std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		}

		//Initialize GLEW
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}
		m_context = SDL_GL_CreateContext(m_window);
	}
	SoulEngine::Window::~Window()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}
