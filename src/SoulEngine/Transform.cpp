#include "Transform.h"
#include "SDL2/SDL.h"

namespace SoulEngine
{
    static void input(const SDL_Event& event, SoulEngine::Transform& transform)
    {
        float moveSpeed = 2.0f;
        float rotateSpeed = 10.0f;
        const Uint8* keyState = SDL_GetKeyboardState(nullptr);

        //Movement
        if (keyState[SDL_SCANCODE_W])
        {
            transform.set_position(transform.get_position() + glm::vec3(0.0f, 0.0f, -moveSpeed));
            std::cout << "W" << std::endl;
        }
        if (keyState[SDL_SCANCODE_S])
        {
            transform.set_position(transform.get_position() + glm::vec3(0.0f, 0.0f, moveSpeed));
            std::cout << "S" << std::endl;
        }
        if (keyState[SDL_SCANCODE_A])
        {
            transform.set_position(transform.get_position() + glm::vec3(-moveSpeed, 0.0f, 0.0f));
            std::cout << "A" << std::endl;
        }
        if (keyState[SDL_SCANCODE_D])
        {
            transform.set_position(transform.get_position() + glm::vec3(moveSpeed, 0.0f, 0.0f));
            std::cout << "D" << std::endl;
        }
        if (keyState[SDL_SCANCODE_SPACE])
        {
            transform.set_position(transform.get_position() + glm::vec3(0.0f, moveSpeed, 0.0f));
            std::cout << "R" << std::endl;
        }
        if (keyState[SDL_SCANCODE_LSHIFT])
        {
            transform.set_position(transform.get_position() + glm::vec3(0.0f, -moveSpeed, 0.0f));
            std::cout << "F" << std::endl;
        }

        //Rotation
        if (keyState[SDL_SCANCODE_Q])
        {
            transform.set_rotation(transform.get_rotation() + glm::vec3(0.0f, -rotateSpeed, 0.0f));
            std::cout << "Q" << std::endl;
        }
        if (keyState[SDL_SCANCODE_E])
        {
            transform.set_rotation(transform.get_rotation() + glm::vec3(0.0f, rotateSpeed, 0.0f));
            std::cout << "E" << std::endl;
        }

        //Scale
        if (keyState[SDL_SCANCODE_Z])
        {
            transform.set_scale(transform.get_scale() + glm::vec3(0.1f));
            std::cout << "Z" << std::endl;
        }
        if (keyState[SDL_SCANCODE_X])
        {
            transform.set_scale(transform.get_scale() - glm::vec3(0.1f));
            std::cout << "X" << std::endl;
        }
    }
}
