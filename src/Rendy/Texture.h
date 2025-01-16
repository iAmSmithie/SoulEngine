#pragma once
#include <GL/glew.h>
#include <vector>
#include <string>

namespace Rendy
{
	struct Texture
	{
		//texture from data and path
		Texture(const std::string& _path);
		GLuint id();

	private:
		GLuint m_id;

		//texture data
		int m_width;
		int m_height;
		bool m_dirty;

		std::vector<unsigned char> m_data;
	};
}
