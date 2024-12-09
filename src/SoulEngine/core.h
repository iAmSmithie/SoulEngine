#include <memory>
#include <vector>

namespace SoulEngine
{
	struct Entity;
	struct Window;
	struct Resource;
	struct Resources;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		void start();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Resources> get_resources();

	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;

		std::vector<std::shared_ptr<Entity> > m_entities;

		std::weak_ptr<Core> m_self;
		
		std::shared_ptr<Window> get_window() { return m_window; }
	};
}