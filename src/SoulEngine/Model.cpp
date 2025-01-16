#include "Model.h"

//load model from file
void SoulEngine::Model::on_load()
{
	m_model = std::make_shared<Rendy::Model>(getPath() + ".obj");
}
