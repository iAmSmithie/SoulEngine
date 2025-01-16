#pragma once
#include <string>

namespace SoulEngine
{
	struct Resources;
	struct Resource
	{
		virtual void on_load() = 0;
		//gets the path of the resource
		std::string getPath() const;

	private:
		//friend struct Resources;
		friend struct SoulEngine::Resources;
		//path to the resource
		std::string m_path;
		//loads the resource
		void load();
	};
}