#include <SoulEngine/SoulEngine.h>
#include <iostream>

using namespace SoulEngine;

struct Player : Component
{
	void on_initialize()
	{
		std::cout << "Player initialized" << std::endl;
	}
	void on_tick()
	{
		//std::cout << "Player ticked" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	std::shared_ptr<Core> c = Core::initialize();
	std::shared_ptr<Entity> ent = c->add_entity();
	std::shared_ptr<Entity> ent2 = c->add_entity();
	std::shared_ptr<Player> p = ent->add_component<Player>();
	std::shared_ptr<triangleRender> t = ent->add_component<triangleRender>();
	std::shared_ptr<triangleRender> t2 = ent2->add_component<triangleRender>();

	std::shared_ptr<Texture> tex = c->get_resources()->load<Texture>("textures/OIAEEE");
	std::shared_ptr<Model> mod = c->get_resources()->load<Model>("models/OIAE/source/OIAEE");

	std::shared_ptr<Texture> tex2 = c->get_resources()->load<Texture>("textures/dingus");
	std::shared_ptr<Model> mod2 = c->get_resources()->load<Model>("models/maxwell/source/smolcat");

	std::shared_ptr<Audio> audio = c->get_resources()->load<Audio>("audio/oiia");
	std::shared_ptr<AudioSource> audioSource = ent->add_component<AudioSource>();
	audioSource->set_audio(audio);


	t->set_texture(tex);
	t->set_model(mod);
	t2->set_texture(tex2);
	t2->set_model(mod2);

	ent->get_component<Transform>()->set_position(glm::vec3(0, 0, -50));
	ent2->get_component<Transform>()->set_position(glm::vec3(-2, -3, -8));

	c->start();

	return 0;
}