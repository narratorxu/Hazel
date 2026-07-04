#include "hzpch.h"

#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"

namespace Hazel {

	OrthographicCamera::OrthographicCamera(const CameraProps& props)
		: m_props(props)
	{
	}
	const glm::vec3& OrthographicCamera::GetPos() const
	{
		return m_props.Position;
	}

	const glm::mat4& OrthographicCamera::GetViewMatrix() const
	{
		return glm::lookAt(
			m_props.Position,
			m_props.Position + m_props.Front,
			glm::normalize(glm::cross(glm::normalize(glm::cross(m_props.Front, glm::vec3(0.0f, 1.0f, 0.0f))), m_props.Front))
		);
	}

	const glm::mat4& OrthographicCamera::GetProjectionMatrix() const
	{
		float  halfHeight = m_props.Far * tan(glm::radians(m_props.VFov * 0.5f));
		float  halfWidth = halfHeight * m_props.AspectRatio;
		return glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, m_props.Near, m_props.Far);
	}

}