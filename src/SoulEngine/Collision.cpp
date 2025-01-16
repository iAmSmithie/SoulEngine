#include "Collision.h"
#include "Component.h"
#include "Transform.h"
#include "entity.h"
#include "core.h"

namespace SoulEngine
{
    bool BoxCollider::colliding(const BoxCollider& _other)
    {
        glm::vec3 a = get_entity()->get_transform()->get_position();
        glm::vec3 b = _other.get_entity()->get_transform()->get_position();
        glm::vec3 ahs = m_size / 2.0f;
        glm::vec3 bhs = _other.m_size / 2.0f;

        // Check on the x-axis
        if (a.x + ahs.x < b.x - bhs.x || a.x - ahs.x > b.x + bhs.x)
            return false;

        // Check on the y-axis
        if (a.y + ahs.y < b.y - bhs.y || a.y - ahs.y > b.y + bhs.y)
            return false;

        // Check on the z-axis
        if (a.z + ahs.z < b.z - bhs.z || a.z - ahs.z > b.z + bhs.z)
            return false;

        return true;
    }

    void BoxCollider::on_tick()
    {
        //Iterate through all entities in the Core
        auto core = get_entity()->get_core();
        if (core) 
        {
            for (size_t i = 0; i < core->get_entities().size(); i++)
            {
                auto other_entity = core->get_entities()[i];
                //Dont do self collision
                if (other_entity == get_entity()) continue;

                //Check if the other entity has a BoxCollider
                auto other_collider = other_entity->get_component<BoxCollider>();
                if (other_collider) {
                    //Check if this collider collides with the other one
                    if (colliding(*other_collider)) 
                    {
                        std::cout << "Collision detected between "
                            << get_entity() << " and "
                            << other_entity << std::endl;
                    }
                }
            }
        }
    }
}