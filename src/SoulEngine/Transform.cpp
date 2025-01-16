#include "Transform.h"
#include "SDL2/SDL.h"

namespace SoulEngine
{
    static void input(const SDL_Event& event, SoulEngine::Transform& transform)
    {
        //set move and rotation speed
        float moveSpeed = 2.0f;
        float rotateSpeed = 10.0f;
        //get the state of the keyboard
        const Uint8* keyState = SDL_GetKeyboardState(nullptr);

        //Movement, all movement keys have debug couts
        if (keyState[SDL_SCANCODE_W])
        {
            //move the object forward
            transform.set_position(transform.get_position() + glm::vec3(0.0f, 0.0f, -moveSpeed));
            //std::cout << "W" << std::endl;
        }
        if (keyState[SDL_SCANCODE_S])
        {
            //move the object backward
            transform.set_position(transform.get_position() + glm::vec3(0.0f, 0.0f, moveSpeed));
            //std::cout << "S" << std::endl;
        }
        if (keyState[SDL_SCANCODE_A])
        {
            //move the object left
            transform.set_position(transform.get_position() + glm::vec3(-moveSpeed, 0.0f, 0.0f));
            //std::cout << "A" << std::endl;
        }
        if (keyState[SDL_SCANCODE_D])
        {
            //move the object right
            transform.set_position(transform.get_position() + glm::vec3(moveSpeed, 0.0f, 0.0f));
            //std::cout << "D" << std::endl;
        }
        if (keyState[SDL_SCANCODE_SPACE])
        {
            //move the object up
            transform.set_position(transform.get_position() + glm::vec3(0.0f, moveSpeed, 0.0f));
            //std::cout << "R" << std::endl;
        }
        if (keyState[SDL_SCANCODE_LSHIFT])
        {
            //move the object down
            transform.set_position(transform.get_position() + glm::vec3(0.0f, -moveSpeed, 0.0f));
            //std::cout << "F" << std::endl;
        }

        //Rotation
        if (keyState[SDL_SCANCODE_Q])
        {
            //rotate the object left
            transform.set_rotation(transform.get_rotation() + glm::vec3(0.0f, -rotateSpeed, 0.0f));
            //std::cout << "Q" << std::endl;
        }
        if (keyState[SDL_SCANCODE_E])
        {
            //rotate the object right
            transform.set_rotation(transform.get_rotation() + glm::vec3(0.0f, rotateSpeed, 0.0f));
            //std::cout << "E" << std::endl;
        }

        //Scale
        if (keyState[SDL_SCANCODE_Z])
        {
            //scale the object up
            transform.set_scale(transform.get_scale() + glm::vec3(0.1f));
            //std::cout << "Z" << std::endl;
        }
        if (keyState[SDL_SCANCODE_X])
        {
            //scale the object down
            transform.set_scale(transform.get_scale() - glm::vec3(0.1f));
            //std::cout << "X" << std::endl;
        }
    }
}
