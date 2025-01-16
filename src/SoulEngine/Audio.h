#include "Resource.h"    
#include "AudioSource.h"  
#include <memory>       
#include <string>    

namespace SoulEngine
{
    struct Audio : Resource
    {
        //load audio resource
        void on_load();

        //destroy audio resource
        void on_destroy();

    private:
        //access audio source
        friend struct SoulEngine::AudioSource;

        //audio resource ID
        ALuint id = 0;
    };
}

