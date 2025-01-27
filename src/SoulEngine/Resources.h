#include <string>
#include <memory>
#include <vector>

namespace SoulEngine
{
	struct Resource;
	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			//search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				//Return it if found
				if (m_resources.at(i)->getPath() == _path)
				{
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			//create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = "../assets/" + _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}
	private:
		//List of all resources
		std::vector<std::shared_ptr<Resource> > m_resources;
	};
}
