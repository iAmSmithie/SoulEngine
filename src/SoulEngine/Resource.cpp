#include "Resource.h"

namespace SoulEngine
{
	//get the resource path
	std::string Resource::getPath() const
	{
		return m_path;
	}
	//load the resource
	void Resource::load()
	{
		on_load();
	}
}