#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Rendy
{
    class Shader
    {
    public:
        Shader();
        GLuint id();
        void uniform(const std::string& _name, const glm::mat4& _value);
        void uniform(const std::string& _name, const glm::vec3& _value);

    private:
        GLuint m_id;
        std::string loadShaderFromFile(const std::string& filePath);
    };
}