#include "Audio.h"
#include <AL/al.h>
#include <AL/alc.h>

#include <stb_vorbis.c>

#include <stdexcept>

namespace SoulEngine
{

    void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer,
        ALenum& _format, ALsizei& _freq)
    {
        int channels = 0;
        int sampleRate = 0;
        short* output = NULL;

        size_t samples = stb_vorbis_decode_filename(_path.c_str(),
            &channels, &sampleRate, &output);

        if (samples == -1)
        {
            throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
        }

        //record the format required by OpenAL
        if (channels < 2)
        {
            _format = AL_FORMAT_MONO16;
        }
        else
        {
            _format = AL_FORMAT_STEREO16;
        }

        //copy the samples from the stb_vorbis output buffer to a vector
        _buffer.resize(samples * channels * sizeof(short));
        memcpy(&_buffer.at(0), output, _buffer.size());

        //record the sample rate required by OpenAL
        _freq = sampleRate;

        //clean up the data
        free(output);
    }

    void SoulEngine::Audio::on_load()
    {
        //create the Buffer
        ALenum format = 0;
        ALsizei freq = 0;
        std::vector<unsigned char> bufferData;
        load_ogg((getPath() + ".ogg").c_str(), bufferData, format, freq);

        alGenBuffers(1, &id);

        alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);
    }
    void Audio::on_destroy()
	{
        //clean up the buffer and source
		alDeleteBuffers(1, &id);
        alDeleteSources(1, &id);
        alcMakeContextCurrent(NULL);
    }
}