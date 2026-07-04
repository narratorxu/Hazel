#include "hzpch.h"
#include "Camera.h"

#include "Platform/Camera/OrthographicCamera.h"
#include "Platform/Camera/PerspectiveCamera.h"

namespace Hazel {

    Camera::CameraType Camera::m_type = Camera::CameraType::Orthographic;

    Camera*  Camera::Create(const CameraProps& props)
    {
        switch (Camera::GetCameraType())
        {
            case CameraType::Orthographic:
            {
                // Create and return an orthographic camera
                return new OrthographicCamera(props);
            }
            case CameraType::Perspective:
            {
                // Create and return a perspective camera
                return new PerspectiveCamera(props);
            }
        }
    }

}