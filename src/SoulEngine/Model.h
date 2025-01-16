#include "Resource.h"
#include <Rendy/Rend.h>
#include <memory>

namespace SoulEngine
{
	struct triangleRender;
	struct Model : Resource
	{
		//function for loading the model
		void on_load();
	private:
		//friend class for accessing triangleRender
		friend struct SoulEngine::triangleRender;
		//model
		std::shared_ptr<Rendy::Model> m_model;
	};
}