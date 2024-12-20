#include "TriangleRenderer.h"
#include <glm/glm.hpp>
#include <stdio.h>
#include <Rendy/Rend.h>
#include "Texture.h"
#include "Model.h"
#include "entity.h"
#include "Transform.h"

namespace SoulEngine
{
	void triangleRender::set_texture(std::shared_ptr<Texture> tex)
	{
		m_tex = tex;
	}
	void SoulEngine::triangleRender::set_model(std::shared_ptr<Model> mod)
	{
		m_mod = mod;
	}
	void triangleRender::on_render()
	{
		Rendy::Mesh mesh;
		Rendy::Face face;
		Rendy::Shader shader;


		float angle = 0;
		angle++;

		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 1000.0f);
		glm::mat4 view(1.0f);
		glm::mat4 model(glm::translate(glm::mat4(1.0f), glm::vec3(0, -20, -100)));
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0, 0, 1));

		//glm::mat4 model = get_entity()->get_transform()->get_model();

		shader.uniform("u_Projection", projection);
		shader.uniform("u_Model", model);
		shader.uniform("u_View", view);

		glUseProgram(shader.id());
		//glBindVertexArray(mesh.vao_id());
		glBindVertexArray(m_mod->m_model->vao_id());
		glBindTexture(GL_TEXTURE_2D, m_tex->m_texture->id());
		glDrawArrays(GL_TRIANGLES, 0, m_mod->m_model->vertex_count());
		//printf("Render meeeeeee");
	}
}
