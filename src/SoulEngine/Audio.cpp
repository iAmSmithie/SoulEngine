#include "Audio.h"
#include <AL/al.h>
#include <AL/alc.h>

void SoulEngine::Audio::on_load()
{
	m_audio = std::make_shared<SoulEngine::Audio>(getPath() + ".ogg");
}

