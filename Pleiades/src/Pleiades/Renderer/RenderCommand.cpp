#include "pepch.h"
#include "Pleiades/Renderer/RenderCommand.h"


namespace Pleiades {
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}