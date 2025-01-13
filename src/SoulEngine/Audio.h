#include "Resource.h"
#include "AudioSource.h"
#include <memory>
#include <string>

namespace SoulEngine
{
    struct Audio : Resource
    {
        Audio(const std::string& path) : m_path(path) {}
        void on_load();
    private:
        friend struct SoulEngine::AudioSource;
        std::string m_path;
        std::shared_ptr<SoulEngine::Audio> m_audio;
    };
}
