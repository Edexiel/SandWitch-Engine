#pragma once

#include <glm/glm.hpp>

namespace Renderer
{
    struct Material
    {
        glm::vec4 albedo{1.0f};
        float metallic{0.0f};
        float roughness{0.5f};
    };
}