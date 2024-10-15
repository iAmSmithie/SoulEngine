#include <memory>

namespace SoulEngine
{

	struct Entity;

	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();
	private:
		friend struct SoulEngine::Entity;

		std::weak_ptr<Entity> m_Entity;
		void tick();
	};
}