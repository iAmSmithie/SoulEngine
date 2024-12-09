#include <Rendy/Rend.h>

namespace SoulEngine
{
	struct Core;
	struct Window
	{
		Window();
		~Window();

	private:
		friend struct SoulEngine::Core;
		SDL_Window* m_window;
		SDL_GLContext m_context;

		Window(const Window& _copy);
		Window& operator=(const Window& _assign);
	};
}