#include <SoulEngine/SoulEngine.h>
#include <iostream>

using namespace SoulEngine;

struct Player : Component
{
	void on_initialize() //override
	{
		std::cout << "Player initialized" << std::endl;
	}
	void on_tick() //override
	{
		std::cout << "Player ticked" << std::endl;
	}
};

int main(int argc, char* argv[])
{
  std::shared_ptr<Core> c = Core::initialize();

  std::shared_ptr<Entity> ent = c->add_entity();
  std::shared_ptr<Player> p = ent->add_component<Player>();
  ent->add_component<Player>();

  Core::initialize()->start();

  int WINDOW_WIDTH = 800;
  int WINDOW_HEIGHT = 600;

  SDL_Window* window = SDL_CreateWindow("Window Desu",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      WINDOW_WIDTH, WINDOW_HEIGHT,
      SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

  // Check if OpenGL context creation failed
  if (!SDL_GL_CreateContext(window))
  {
      throw std::exception();
  }

  // Initialize GLEW
  if (glewInit() != GLEW_OK)
  {
      throw std::exception();
  }


  return 0;
}