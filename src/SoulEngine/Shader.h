#include "Resource.h"
#include <Rendy/Rend.h>
#include <memory>

namespace SoulEngine
{
	struct Shader : Resource
	{
		void onLoad();
	private:
		std::shared_ptr<Rendy::Shader> m_shader;
	};
}