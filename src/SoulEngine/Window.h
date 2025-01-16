#include <Rendy/Rend.h>

namespace SoulEngine
{
	struct Core;
	struct Window
	{
		//window constructor and destructor
		Window();
		~Window();

	private:
		friend struct SoulEngine::Core;
		//window initialization and shutdown
		SDL_Window* m_window;
		SDL_GLContext m_context;

		Window(const Window& _copy);
		Window& operator=(const Window& _assign);
	};
}