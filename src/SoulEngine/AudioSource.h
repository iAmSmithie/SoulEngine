#include "Component.h"
#include <vector>
#pragma once

namespace SoulEngine
{
	struct Audio;
	struct AudioSource : Component
	{
	public:
		//void load_ogg(const std::string&, std::vector<unsigned char>&, ALenum&, ALsizei&);
		void set_audio(std::shared_ptr<Audio> audio);
	private:
		std::shared_ptr<Audio> m_audio;
	};
}