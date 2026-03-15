#include "Scene/Components/Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace Components
{
    glm::mat4 Transform::GetMatrix() const
    {
        glm::mat4 t = glm::translate(glm::mat4(1.0f), position);
        glm::mat4 r = glm::mat4_cast(rotation);
        glm::mat4 s = glm::scale(glm::mat4(1.0f), scale);
        return t * r * s;
    }
}