#include "Component.h"
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
#pragma once

namespace SoulEngine
{
	struct Audio;
	struct AudioSource : Component
	{
	public:
		void on_initialize();
		void set_audio(std::shared_ptr<Audio> audio);
	private:
		ALuint id;
		std::shared_ptr<Audio> m_audio;
	};
}