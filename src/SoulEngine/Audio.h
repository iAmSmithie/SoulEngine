#include "Resource.h"
#include <memory>

namespace SoulEngine
{
	struct Audio : Resource
	{
		void on_load();
	private:
		std::shared_ptr<SoulEngine::Audio> m_audio;
	};
}