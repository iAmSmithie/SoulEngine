#include "Audio.h"

void SoulEngine::Audio::on_load()
{
	m_audio = std::make_shared<SoulEngine::Audio>(getPath() + ".ogg");
}
