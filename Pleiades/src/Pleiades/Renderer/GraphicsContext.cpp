#include "pepch.h"
#include "Pleiades/Renderer/GraphicsContext.h"
#include "Pleiades/Renderer/Renderer.h"

// OpenGL context
#include "Platform/OpenGL/OpenGLContext.h"

namespace Pleiades {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}