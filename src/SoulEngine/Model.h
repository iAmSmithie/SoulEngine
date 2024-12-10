#include "Resource.h"
#include <Rendy/Rend.h>
#include <memory>

namespace SoulEngine
{
	struct triangleRender;
	struct Model : Resource
	{
		void on_load();
	private:
		friend struct SoulEngine::triangleRender;
		std::shared_ptr<Rendy::Model> m_model;
	};
}