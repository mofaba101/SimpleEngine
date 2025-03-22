#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SimpleEngine::Application* SimpleEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("SimpleEngine\n");
	auto app = SimpleEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // SE_PLATFORM_WINDOWS
