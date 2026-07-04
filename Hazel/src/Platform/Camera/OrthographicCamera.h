#pragma once

#include "Hazel/Renderer/Camera.h"

namespace Hazel {

    class OrthographicCamera : public Camera
    {
    public:
		OrthographicCamera(const CameraProps& props);

        virtual const glm::vec3& GetPos() const override;
        virtual const glm::mat4& GetViewMatrix() const override;
        virtual const glm::mat4& GetProjectionMatrix() const override;
    private:
        CameraProps m_props;
    };

}