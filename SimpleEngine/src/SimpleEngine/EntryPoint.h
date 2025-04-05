#pragma once


#ifdef  SE_PLATFORM_WINDOWS

extern SimpleEngine::Application* SimpleEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = SimpleEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
