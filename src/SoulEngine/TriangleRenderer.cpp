#include "TriangleRenderer.h"
#include <glm/glm.hpp>
#include <stdio.h>
#include <Rendy/Rend.h>
#include "Texture.h"

namespace SoulEngine
{
	void triangleRender::set_texture(std::shared_ptr<Texture> tex)
	{
		m_tex = tex;
	}
	void triangleRender::on_render()
	{
		Rendy::Mesh mesh;
		Rendy::Face face;
		Rendy::Shader shader;

		face.a.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face.b.position = glm::vec3(-1.0f, -1.0f, 0.0f);
		face.c.position = glm::vec3(1.0f, -1.0f, 0.0f);
		mesh.addFaces(face);


		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
		glm::mat4 view(1.0f);
		glm::mat4 model(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3)));

		shader.uniform("u_Projection", projection);
		shader.uniform("u_Model", model);
		shader.uniform("u_View", view);

		glUseProgram(shader.id());
		glBindVertexArray(mesh.vao_id());
		glBindTexture(GL_TEXTURE_2D, m_tex->m_texture->id());
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//printf("Render meeeeeee");
	}
}
