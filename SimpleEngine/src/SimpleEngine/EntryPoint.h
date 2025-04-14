#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SimpleEngine::Application* SimpleEngine::CreateApplication();

int main(int argc, char** argv)
{
	SimpleEngine::Log::Init();
	SE_CORE_WARN("Log!");

	auto app = SimpleEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
