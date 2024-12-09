#include "Resource.h"
#include <Rendy/Rend.h>
#include <memory>

namespace SoulEngine
{
	struct Model : Resource
	{
		void onLoad();
	private:
		std::shared_ptr<Rendy::Model> m_model;
	};
}