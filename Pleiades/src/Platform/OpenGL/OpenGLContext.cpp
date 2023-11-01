#include "pepch.h"
#include "Platform/OpenGL/OpenGLContext.h"

// glfw
#include <GLFW/glfw3.h>

// glad
#include <glad/glad.h>
#include <GL/GL.h>

namespace Pleiades {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PE_CORE_ASSERT(status, "Failed to initialize Glad!");

		PE_CORE_INFO("OpenGL Info:");
		PE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		PE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		PE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

#ifdef PE_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		// For checking the OpenGL version
		PE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Pleiades requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}