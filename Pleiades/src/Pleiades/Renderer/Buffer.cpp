#include "pepch.h"
#include "Pleiades/Renderer/Buffer.h"
#include "Pleiades/Renderer/Renderer.h"

// OpenGL Buffer
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Pleiades {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		// Check API
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}