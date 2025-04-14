#include <SimpleEngine.h>

class ExampleLayer : public SimpleEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
	}

	void OnEvent(SimpleEngine::Event& event) override
	{
		SE_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public SimpleEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

SimpleEngine::Application* SimpleEngine::CreateApplication()
{
	return new Sandbox();
}