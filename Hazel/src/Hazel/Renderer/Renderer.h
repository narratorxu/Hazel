#pragma once

#include "RenderCommand.h"
#include "Camera.h"

namespace Hazel {

	class Renderer
	{
	public:
		static void BeginScene(const std::shared_ptr<Camera>& camera, std::shared_ptr<UniformBuffer>& uniformBuffer);
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}