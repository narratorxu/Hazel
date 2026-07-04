#include  "hzpch.h"
#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>

namespace Hazel {

	void Renderer::BeginScene(const std::shared_ptr<Camera>& camera, std::shared_ptr<UniformBuffer>& uniformBuffer)
	{
		glm::mat4 viewMatrix = camera->GetViewMatrix();
		glm::mat4 projectionMatrix = camera->GetProjectionMatrix();
		uniformBuffer->Bind();
		uniformBuffer->SetData(0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
		uniformBuffer->SetData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
		uniformBuffer->Unbind();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}


}