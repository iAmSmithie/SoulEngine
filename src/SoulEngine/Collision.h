#include "Component.h"
#include <glm/glm.hpp>

namespace SoulEngine
{
	struct BoxCollider : Component
	{
		//detects if this collider is colliding with another collider
		bool colliding(const BoxCollider& _other);
		//runs every tick
		void on_tick();

		//returns the size of the collider
		void set_size(const glm::vec3& size)
		{
			m_size = size;
		}
	private:
		//size of the collider
		glm::vec3 m_size;
	};
}