#include <glm/glm.hpp>

namespace Hazel {

    struct CameraProps
    {
        glm::vec3 m_pos; // camera position
        glm::vec3 m_up;
        glm::vec3 m_front;
        float m_near, m_far;
        float m_aspectRatio;
        float m_fov;
    }

    class Camera
    {
    public:
        enum class CameraType
        {
            Perspective = 0, Orthographic = 1
        }
    public:
        Camera(const glm::vec3& pos, const glm::vec3& up, const glm::vec3& front, float near, float far, float aspectRatio, float fov) {}
        virtual ~Camera() = default;
        glm::vec3& GetPos() { return  m_pos; }
        virtual glm::mat4& GetProjectionMatrix() = 0;
        glm::mat4& GetViewMatrix() { return glm::lookAt(m_pos, m_pos + m_front, m_up); }

        static Camera* Create(const CameraProps& props);
    private:
        CameraProps* m_props;
    private:
        static CameraType m_type;
    }

}