#pragma once

#include "SimpleEngine/Core.h"
#include "SimpleEngine/Window.h"
#include "SimpleEngine/Events/Event.h"
#include "SimpleEngine/Events/ApplicationEvent.h"
#include "SimpleEngine/LayerStack.h"
#include "SimpleEngine/ImGui/ImGuiLayer.h"

namespace SimpleEngine
{
	class SE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}

