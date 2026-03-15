#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Components
{
    struct Transform
    {
        glm::vec3 position{0.0f};
        glm::quat rotation{glm::identity<glm::quat>()};
        glm::vec3 scale{1.0f};

        glm::mat4 GetMatrix() const;
    };
}