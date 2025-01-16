#include "Texture.h"

//get the texture from file
void SoulEngine::Texture::on_load()
{
	m_texture = std::make_shared<Rendy::Texture>(getPath() + ".png");
}
