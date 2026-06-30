#include "Hazel/Renderer/Camera.h"

namespace {

    class PerspectiveCamera : public Camera
    {
    public:
        virtual glm::mat4& GetProjectionMatrix() override;
    }

}