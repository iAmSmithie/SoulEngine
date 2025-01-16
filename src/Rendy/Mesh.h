#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace Rendy
{
    //vertex structure
    struct Vertex
    {
        Vertex();

        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texcoord;
    };

    //face structure
    struct Face
    {
        Vertex a;
        Vertex b;
        Vertex c;
    };

    //mesh class
    class Mesh
    {
    public:
        Mesh();
        void addFaces(Face _face);

        GLuint vao_id();
        GLsizei vertex_count() const;
    private:
        std::vector<Face> m_faces;
        GLuint m_vboid;
        GLuint m_vaoid;
        bool m_dirty = false;

    };
}
