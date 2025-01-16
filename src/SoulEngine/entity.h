#include <memory>
#include <vector>
#include "Transform.h"

namespace SoulEngine
{
    struct Core;
    struct Component;

    //entity struct that holds components and a transform
    struct Entity
    {
        //add component to the entity and returns it
        template <typename T>
        std::shared_ptr<T> add_component()
        {
            std::shared_ptr<T> rtn = std::make_shared<T>();

            rtn->m_Entity = m_self;  //sets the entity reference in the component
            rtn->on_initialize();    //initializes the component
            m_Components.push_back(rtn); //adds the component to the entity's list

            return rtn;
        }

        //get specific component from the entity
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

        //gets the core the entity belongs to
        std::shared_ptr<Core> get_core() const
        {
            return m_Core.lock();
        }

    private:
        friend struct SoulEngine::Core;

        std::weak_ptr<Core> m_Core; //weak reference to the core to avoid circular dependencies
        std::weak_ptr<Entity> m_self; //weak reference to itself to avoid circular dependencies
        std::vector<std::shared_ptr<Component> > m_Components; //vector of components

        Transform transform; //entity transform

        void tick(); //updates the entity
        void render(); //renders the entity

    public:
        //gets the transform of the entity
        std::shared_ptr<Transform> get_transform();
    };
}
