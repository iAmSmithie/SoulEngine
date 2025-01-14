#include "Resource.h"
#include "AudioSource.h"
#include <memory>
#include <string>

namespace SoulEngine
{
    struct Audio : Resource
    {
        void on_load();
		void on_destroy();
    private:
        friend struct SoulEngine::AudioSource;
        ALuint id;
    };
}
