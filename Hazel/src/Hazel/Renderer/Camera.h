#pragma once

#include <glm/glm.hpp>

namespace Hazel {

    struct CameraProps
    {
        glm::vec3 Position; // camera position
        // glm::vec3 Up;
		// glm::vec3 Right; // FPS 风格下可以由 Front 和 WorldUp 叉乘得到 Right
		// glm::vec3 WorldUp; // FPS 风格，假设固定为 (0, 1, 0)（OpenGL 坐标系）
        glm::vec3 Front;
		float VFov; // vertical filed-of-view in radians
        float AspectRatio;
        float Near, Far;
    };

    class Camera
    {
    public:
        enum class CameraType
        {
            Perspective = 0, Orthographic = 1
        };
    public:
        Camera() = default;
        virtual ~Camera() = default;
        virtual const glm::vec3& GetPos() const = 0;
        virtual const glm::mat4& GetViewMatrix() const = 0;
        virtual const glm::mat4& GetProjectionMatrix() const = 0;

        static Camera* Create(const CameraProps& props);

		inline static void SetCameraType(CameraType type) { m_type = type; }
		inline static CameraType GetCameraType() { return m_type; }
    private:
        static CameraType m_type;
    };

}