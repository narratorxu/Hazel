#include "hzpch.h"
#include "Camera.h"

namespace Hazel {

    Camera::CameraType Camera::m_type = Camera::CameraType::Orthographic;

    Camera::Create()
    {
        switch (m_type)
        {
            case: CameraType::Orthographic:
            case: CameraType::Perspective:
        }
    }

}