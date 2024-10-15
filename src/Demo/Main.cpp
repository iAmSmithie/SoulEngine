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

int main()
{
  std::shared_ptr<Core> c = Core::initialize();

  std::shared_ptr<Entity> ent = c->add_entity();
  std::shared_ptr<Player> p = ent->add_component<Player>();
  ent->add_component<Player>();

  Core::initialize()->start();




  return 0;
}