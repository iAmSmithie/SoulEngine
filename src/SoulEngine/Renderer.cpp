#include "Renderer.h"
#include <glm/glm.hpp>
#include <stdio.h>
#include <Rendy/Rend.h>
#include "Texture.h"
#include "Model.h"
#include "entity.h"
#include "Transform.h"
#include "core.h"
#include "Component.h"

namespace SoulEngine
{
	//set the texture to tex
	void triangleRender::set_texture(std::shared_ptr<Texture> tex)
	{
		m_tex = tex;
	}
	//set the model to mod
	void SoulEngine::triangleRender::set_model(std::shared_ptr<Model> mod)
	{
		m_mod = mod;
	}

	void triangleRender::on_render()
	{
		//grab mesh, face and shader from rendy
		Rendy::Mesh mesh;
		Rendy::Face face;
		Rendy::Shader shader;

		//set projection, view and model matrix
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 1000.0f);
		glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 model = get_entity()->get_component<Transform>()->updateModelMatrix();
		static float angle = 0;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0, 0, 1));

		//set shader uniforms
		shader.uniform("u_Projection", projection);
		shader.uniform("u_Model", model);
		shader.uniform("u_View", view);

		//use the shader.id, set the vertex array to the model vao_id, bind the texture to the texture id, draw the models onto the screen
		glUseProgram(shader.id());
		glBindVertexArray(m_mod->m_model->vao_id());
		glBindTexture(GL_TEXTURE_2D, m_tex->m_texture->id());
		glDrawArrays(GL_TRIANGLES, 0, m_mod->m_model->vertex_count());
		//model render debug
		//std::cout << "Model Rendered" << std::endl;
	}
}
