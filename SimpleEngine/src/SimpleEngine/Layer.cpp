#include "sepch.h"
#include "Layer.h"

namespace SimpleEngine
{
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}
}