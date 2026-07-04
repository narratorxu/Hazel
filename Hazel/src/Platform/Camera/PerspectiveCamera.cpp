#include "hzpch.h"
#include "PerspectiveCamera.h"
// #include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Hazel {

	PerspectiveCamera::PerspectiveCamera(const CameraProps& props)
		: m_props(props)
	{
	}

	const glm::vec3& PerspectiveCamera::GetPos() const
	{
		return m_props.Position;
		 //return const_cast<glm::vec3&>(m_props.Position);
	}

	const glm::mat4& PerspectiveCamera::GetViewMatrix() const
	{
		return glm::lookAt(
			m_props.Position,
			m_props.Position + m_props.Front,
			glm::normalize(glm::cross(glm::normalize(glm::cross(m_props.Front, glm::vec3(0.0f, 1.0f, 0.0f))), m_props.Front))
		);
	}

	const glm::mat4& PerspectiveCamera::GetProjectionMatrix() const
	{
		return glm::perspective(glm::radians(m_props.VFov), m_props.AspectRatio, m_props.Near, m_props.Far);
	}

}