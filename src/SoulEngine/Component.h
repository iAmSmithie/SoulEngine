#pragma once
#include <memory>

namespace SoulEngine
{
    struct Entity;
    struct Transform;

    // Base class for components attached to entities
    struct Component
    {
        //Initalise the component
        virtual void on_initialize();

        //Called on each game tick
        virtual void on_tick();

        //Called on each render tick
        virtual void on_render();

        //Returns the entity
        std::shared_ptr<Entity> get_entity() const;

        //Returns the transform
        std::shared_ptr<Transform> get_transform();

    private:
        //Allows Entity to access private members
        friend struct SoulEngine::Entity;

        //Weak pointer to the entity to avoid circular references
        std::weak_ptr<Entity> m_Entity;

        //tick function
        void Component::tick();  
        //render function
        void render();          
    };
}
