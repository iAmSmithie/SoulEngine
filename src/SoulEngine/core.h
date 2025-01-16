#include <memory>
#include <vector>

namespace SoulEngine
{
	struct Entity;
	struct Window;
	struct Resource;
	struct Resources;
	struct Audio;

	struct Core
	{
		//initialise core
		static std::shared_ptr<Core> initialize();
		//start the game loop
		void start();
		//add in entites and resrouces
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Resources> get_resources();
		//get and return entities
		std::vector<std::shared_ptr<Entity>>& get_entities() { return m_entities; }


	private:
		//window, resources and audio pointers
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Audio> m_audio;
		//vector of entities
		std::vector<std::shared_ptr<Entity> > m_entities;
		//weak pointer to core
		std::weak_ptr<Core> m_self;
		//get the window
		std::shared_ptr<Window> get_window() { return m_window; }
	};
}