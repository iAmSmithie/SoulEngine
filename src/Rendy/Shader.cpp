#include "Shader.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Rendy
{
    Shader::Shader()
        : m_id(0)
    { }

    std::string Shader::loadShaderFromFile(const std::string& filePath)
    {
        std::ifstream shaderFile(filePath);
        std::string shaderCode((std::istreambuf_iterator<char>(shaderFile)),
            std::istreambuf_iterator<char>());
        shaderFile.close();
        return shaderCode;
    }


    GLuint Shader::id()
    {
        if (!m_id)
        {
            //Load vertex shader from file
            std::string vertexShaderSrc = loadShaderFromFile("../assets/shaders/vertex_shader.glsl.txt");

            //Compile vertex shader
            GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
            const char* vertexShaderCode = vertexShaderSrc.c_str();
            glShaderSource(vertexShaderId, 1, &vertexShaderCode, NULL);
            glCompileShader(vertexShaderId);
            GLint success = 0;
            glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                throw std::exception();
            }

            //load fragment shader from file
            std::string fragmentShaderSrc = loadShaderFromFile("../assets/shaders/fragment_shader.glsl.txt");

            //compile fragment shader
            GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
            const char* fragmentShaderCode = fragmentShaderSrc.c_str();
            glShaderSource(fragmentShaderId, 1, &fragmentShaderCode, NULL);
            glCompileShader(fragmentShaderId);
            glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                throw std::exception();
            }

            //define and Compile Shaders...
            GLuint programId = glCreateProgram();
            glAttachShader(programId, vertexShaderId);
            glAttachShader(programId, fragmentShaderId);

            //bind attribute locations
            glBindAttribLocation(programId, 1, "a_TexCoord");
            glBindAttribLocation(programId, 0, "a_Position");

            //link program
            glLinkProgram(programId);
            glGetProgramiv(programId, GL_LINK_STATUS, &success);
            if (!success)
            {
                throw std::exception();
            }

            //detach and delete shader objects
            glDetachShader(programId, vertexShaderId);
            glDeleteShader(vertexShaderId);
            glDetachShader(programId, fragmentShaderId);
            glDeleteShader(fragmentShaderId);

            m_id = programId;

        }
        return m_id;
    }

    void Shader::uniform(const std::string& _name, const glm::mat4& _value)
    {
        GLint loc = glGetUniformLocation(id(), _name.c_str());

        glUseProgram(id());
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(_value));
        glUseProgram(0);
    }

    void Shader::uniform(const std::string& _name, const glm::vec3& _value)
    {
        GLint loc = glGetUniformLocation(id(), _name.c_str());

        glUseProgram(id());
        glUniformMatrix3fv(loc, 1, GL_FALSE, glm::value_ptr(_value));
        glUseProgram(0);
    }
}