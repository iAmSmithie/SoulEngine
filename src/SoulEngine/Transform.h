#include "TriangleRenderer.h"
#include "Component.h"
#include <Rendy/Rend.h>
#pragma once

namespace SoulEngine
{
	struct Transform : Component
	{
		glm::vec3 position = glm::vec3(0.0f);
		glm::vec3 rotation = glm::vec3(0.0f);
		glm::vec3 scale = glm::vec3(1.0f);
		glm::mat4 model;

		glm::mat4 updateModelMatrix()
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model, position);
			model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
			model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
			model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
			model = glm::scale(model, scale);
			return model;
		}
		glm::vec3 get_position() const 
		{ 
			return position; 
		}
		glm::vec3 get_rotation() const 
		{ 
			return rotation; 
		}
		glm::vec3 get_scale() const
		{ 
			return scale;
		}
		void set_position(const glm::vec3& pos) 
		{
			position = pos;
			updateModelMatrix();
		}
		void set_rotation(const glm::vec3& rot)
		{
			rotation = rot;
			updateModelMatrix();
		}
		void set_scale(const glm::vec3& sca)
		{
			scale = sca;
			updateModelMatrix();
		}
	};
}