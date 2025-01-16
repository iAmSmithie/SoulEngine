#include "Resource.h"
#include <Rendy/Rend.h>
#include <memory>

namespace SoulEngine
{
	struct triangleRender;
	struct Texture : Resource
	{
		//load textures from file
		void on_load();
	private:
		//friend class for accessing triangleRender
		friend struct SoulEngine::triangleRender;
		//texture
		std::shared_ptr<Rendy::Texture> m_texture;
	};
}