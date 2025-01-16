#include "Component.h"
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
#pragma once

namespace SoulEngine
{
	//forward declare audio.h
	struct Audio;
	struct AudioSource : Component
	{
	public:
		//intialisation
		void on_initialize();
		//set the audio source to play music
		void set_audio(std::shared_ptr<Audio> audio);
	private:
		//audio source id
		ALuint id = 0;
		std::shared_ptr<Audio> m_audio;
	};
}