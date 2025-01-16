#include "Renderer.h"
#include "Component.h"
#include <Rendy/Rend.h>
#pragma once

namespace SoulEngine
{
	struct Transform : Component
	{
		//set position, rotation, scale
		glm::vec3 position = glm::vec3(0.0f);
		glm::vec3 rotation = glm::vec3(0.0f);
		glm::vec3 scale = glm::vec3(1.0f);
		//model matrix
		glm::mat4 model;

		//update model matrix with new rotation and scale then return it
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
		//get position and return it
		glm::vec3 Transform::get_position() const 
		{ 
			return position; 
		}
		//get rotation and return it
		glm::vec3 get_rotation() const 
		{ 
			return rotation; 
		}
		//get scale and return it
		glm::vec3 get_scale() const
		{ 
			return scale;
		}
		//set position and update model matrix
		void set_position(const glm::vec3& pos) 
		{
			position = pos;
			updateModelMatrix();
		}
		//set rotation and update model matrix
		void set_rotation(const glm::vec3& rot)
		{
			rotation = rot;
			updateModelMatrix();
		}
		//set scale and update model matrix
		void set_scale(const glm::vec3& sca)
		{
			scale = sca;
			updateModelMatrix();
		}
	};
}