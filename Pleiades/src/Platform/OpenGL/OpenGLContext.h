#pragma once

#include "Pleiades/Renderer/GraphicsContext.h"

// for the glfw window
struct GLFWwindow;

namespace Pleiades {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}