#pragma once

#include "SimpleEngine/Layer.h"

#include "SimpleEngine/Events/Event.h"
#include "SimpleEngine/Events/ApplicationEvent.h"
#include "SimpleEngine/Events/KeyEvent.h"
#include "SimpleEngine/Events/MouseEvent.h"

namespace SimpleEngine
{
	class SE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}