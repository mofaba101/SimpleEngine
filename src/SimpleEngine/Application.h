#pragma once

#include "Core.h"

namespace SimpleEngine
{
	class SIMPLEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined by client
	Application* CreateApplication();
}

