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
  std::shared_ptr<triangleRender> t = ent->add_component<triangleRender>();
  std::shared_ptr<Texture> tex = c->get_resources()->load<Texture>("textures/OIAEEE");
  //std::shared_ptr<Model> mod = c->get_resources()->load<Model>("models/maxwell/source/smolcat");
  std::shared_ptr<Model> mod = c->get_resources()->load<Model>("models/OIAE/source/OIAEE");
  t->set_texture(tex);
  t->set_model(mod);
  ent->add_component<Player>();


  

  c->start();

  return 0;
}