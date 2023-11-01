#pragma once

#include "Pleiades/Core/Layer.h"
#include "Pleiades/Events/ApplicationEvent.h"
#include "Pleiades/Events/KeyEvent.h"
#include "Pleiades/Events/MouseEvent.h"

namespace Pleiades {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}