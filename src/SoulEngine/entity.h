#include <memory>
#include <vector>
#include "Transform.h"

namespace SoulEngine
{
	struct Core;
	struct Component;

	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> add_component()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_Entity = m_self;
			rtn->on_initialize();
			m_Components.push_back(rtn);

			return rtn;
		}
		template <typename T>
		std::shared_ptr<T> get_component()
		{
			for (auto& comp : m_Components)
			{
				if (std::dynamic_pointer_cast<T>(comp))
				{
					return std::dynamic_pointer_cast<T>(comp);
				}
			}
			return nullptr;
		}
	private:
		friend struct SoulEngine::Core;

		std::weak_ptr<Core> m_Core;
		std::weak_ptr<Entity> m_self;
		std::vector<std::shared_ptr<Component> > m_Components;

		Transform transform;

		void tick();
		void render();
	};
}