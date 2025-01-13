#include <AL/al.h>
#include <AL/alc.h>
#include <stdexcept>
#include "AudioSource.h"
#include <vector>

namespace SoulEngine
{
	void SoulEngine::AudioSource::set_audio(std::shared_ptr<Audio> audio)
	{
        ALCdevice* device = alcOpenDevice(NULL);

        if (!device)
        {
            throw std::runtime_error("Failed to open audio device");
        }

        ALCcontext* context = alcCreateContext(device, NULL);

        if (!context)
        {
            alcCloseDevice(device);
            throw std::runtime_error("Failed to create audio context");
        }

        if (!alcMakeContextCurrent(context))
        {
            alcDestroyContext(context);
            alcCloseDevice(device);
            throw std::runtime_error("Failed to make context current");
        }

        alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

        ALenum format = 0;
        ALsizei freq = 0;
        std::vector<unsigned char> bufferData;

        ALuint bufferId = 0;
        alGenBuffers(1, &bufferId);

        alBufferData(bufferId, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);
        ALuint sourceId = 0;
        alGenSources(1, &sourceId);
        alSourcei(sourceId, AL_BUFFER, bufferId);
        alSourcePlay(sourceId);

        alDeleteSources(1, &sourceId);
        alDeleteBuffers(1, &bufferId);
        alcMakeContextCurrent(NULL);
        alcDestroyContext(context);
        alcCloseDevice(device);
		m_audio = audio;
	}
}
