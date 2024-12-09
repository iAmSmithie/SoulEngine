#include <string>

namespace SoulEngine
{
	struct Resources;
	struct Resource
	{
		virtual void on_load() = 0;
		std::string getPath() const;

	private:
		friend struct SoulEngine::Resources;
		std::string m_path;

		void load();
	};
}