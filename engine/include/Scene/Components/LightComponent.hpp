#pragma once

#include <glm/glm.hpp>

namespace Components
{
    enum class LightType { Directional, Point, Spot };

    struct LightComponent
    {
        LightType type{LightType::Point};
        glm::vec3 color{1.0f};
        float     intensity{1.0f};
    };
}