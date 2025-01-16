#include <AL/al.h>
#include <AL/alc.h>
#include <stdexcept>
#include "AudioSource.h"
#include "Audio.h"
#include <vector>

namespace SoulEngine
{
    //intialise the audiosource
    void AudioSource::on_initialize()
    {
        alGenSources(1, &id);
    }
    //set the audio source to play
    void SoulEngine::AudioSource::set_audio(std::shared_ptr<Audio> audio)
	{
        m_audio = audio;
        alSourcei(id, AL_BUFFER, audio->id);
        //Noises
        alSourcePlay(id);

	}
}
