#include "Hazel/Renderer/Camera.h"

namespace {

    class OrthographicCamers : public Camera
    {
    public:
        virtual glm::mat4& GetProjectionMatrix() override;
    }

}