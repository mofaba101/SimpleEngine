#include <SimpleEngine.h>

class Sandbox : public SimpleEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

SimpleEngine::Application* SimpleEngine::CreateApplication()
{
	return new Sandbox();
}