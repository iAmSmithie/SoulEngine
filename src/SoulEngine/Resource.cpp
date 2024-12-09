#include "Resource.h"

namespace SoulEngine
{
	std::string Resource::getPath() const
{
	return m_path;
}

void Resource::load()
{
	on_load();
}
}