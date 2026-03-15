#pragma once

#include "Renderer/Camera.hpp"

namespace Components
{
    struct CameraComponent
    {
        Renderer::Camera camera{60.0f, 16.0f / 9.0f, 0.1f, 1000.0f};
        bool isPrimary{true};
    };
}