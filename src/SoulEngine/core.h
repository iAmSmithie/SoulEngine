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
		static std::shared_ptr<Core> initialize();
		void start();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Resources> get_resources();
		std::vector<std::shared_ptr<Entity>>& get_entities() { return m_entities; }


	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Audio> m_audio;

		std::vector<std::shared_ptr<Entity> > m_entities;

		std::weak_ptr<Core> m_self;
		
		std::shared_ptr<Window> get_window() { return m_window; }
	};
}