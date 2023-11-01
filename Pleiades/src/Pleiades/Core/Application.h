#pragma once

#include "Pleiades/Core/Core.h"
#include "Pleiades/Core/Window.h"
#include "Pleiades/Core/LayerStack.h"
#include "Pleiades/Events/Event.h"
#include "Pleiades/Events/ApplicationEvent.h"
#include "Pleiades/Core/Timestep.h"
#include "Pleiades/ImGui/ImGuiLayer.h"

namespace Pleiades {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// This will be defined in Client
	Application* CreateApplication();

}