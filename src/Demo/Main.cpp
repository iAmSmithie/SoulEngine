#include <SoulEngine/SoulEngine.h>
#include <iostream>

using namespace SoulEngine;

struct Player : Component
{
	void on_initialize()
	{
		//check if player has been initialised
		std::cout << "Player initialised" << std::endl;
		std::cout << "For Movement: W for forward, A for left, S for backwards and D for right, Space for up, Left Shift for down, Z to make model bigger, X to make model smaller" << std::endl;
	}
	void on_tick()
	{
		//check if the player is being ticked
		//std::cout << "Player ticked" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	//initialise the core. add entities and components
	std::shared_ptr<Core> c = Core::initialize();
	std::shared_ptr<Entity> ent = c->add_entity();
	std::shared_ptr<Entity> ent2 = c->add_entity();
	std::shared_ptr<Player> p = ent->add_component<Player>();
	std::shared_ptr<triangleRender> t = ent->add_component<triangleRender>();
	std::shared_ptr<triangleRender> t2 = ent2->add_component<triangleRender>();

	//get the model, texture and add a box collider to the entity
	std::shared_ptr<Texture> tex = c->get_resources()->load<Texture>("textures/OIAEEE");
	std::shared_ptr<Model> mod = c->get_resources()->load<Model>("models/OIAE/source/OIAEE");
	std::shared_ptr<BoxCollider> box = ent->add_component<BoxCollider>();

	//get the model, texture and add a box collider to the other entity
	std::shared_ptr<Texture> tex2 = c->get_resources()->load<Texture>("textures/dingus");
	std::shared_ptr<Model> mod2 = c->get_resources()->load<Model>("models/maxwell/source/smolcat");
	std::shared_ptr<BoxCollider> box2 = ent2->add_component<BoxCollider>();

	//add audio and audio source to the entity
	std::shared_ptr<Audio> audio = c->get_resources()->load<Audio>("audio/oiia");
	std::shared_ptr<AudioSource> audioSource = ent->add_component<AudioSource>();
	audioSource->set_audio(audio);

	//set the size of the box colliders for the models
	box->set_size(glm::vec3(50, 50, 50));
	box2->set_size(glm::vec3(50, 50, 50));

	//set the position of the entities
	ent->get_transform()->set_position(glm::vec3(0, 0, 0));
	ent2->get_transform()->set_position(glm::vec3(0, -20, -150));

	//set the texture and model for the entities
	t->set_texture(tex);
	t->set_model(mod);
	t2->set_texture(tex2);
	t2->set_model(mod2);

	//set the position and rotation of the entities
	ent->get_component<Transform>()->set_position(glm::vec3(0, 0, -50));
	ent2->get_component<Transform>()->set_rotation(glm::vec3(5, -35, 0));
	ent2->get_component<Transform>()->set_position(glm::vec3(0, -20, -150));

	//start the core
	c->start();

	return 0;
}