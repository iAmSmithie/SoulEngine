#include <SoulEngine/SoulEngine.h>
#include <iostream>

using namespace SoulEngine;

struct Test
{
	int m_temp;
};

int main()
{
  std::shared_ptr<Core> c = Core::initialize();

  std::shared_ptr<Entity> ent = c->add_entity();
  ent->add_component<Test>();

  //Core->start();




  return 0;
}