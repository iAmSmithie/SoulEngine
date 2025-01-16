#include "Component.h"
#include <glm/glm.hpp>

namespace SoulEngine
{
	struct BoxCollider : Component
	{
		bool colliding(const BoxCollider& _other);
		void on_tick();

		void set_size(const glm::vec3& size)
		{
			m_size = size;
		}
	private:
		glm::vec3 m_size;
	};
}