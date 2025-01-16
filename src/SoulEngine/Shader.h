#include "Resource.h"
#include <Rendy/Rend.h>
#include <memory>

namespace SoulEngine
{
	struct Shader : Resource
	{
		//load shader from file
		void onLoad();
	private:
		//shader object
		std::shared_ptr<Rendy::Shader> m_shader;
	};
}