#pragma once

#include <glm/glm.hpp>

namespace Renderer
{
    class Camera
    {
    public:
        Camera(float fov, float aspectRatio, float nearClip, float farClip);

        const glm::mat4& GetView()       const { return _view; }
        const glm::mat4& GetProjection() const { return _projection; }
        glm::mat4        GetViewProjection() const;

        void SetPosition(const glm::vec3& position);
        void SetRotation(const glm::vec3& eulerAngles);

    private:
        void RecalculateView();

        glm::mat4 _view{1.0f};
        glm::mat4 _projection{1.0f};
        glm::vec3 _position{0.0f};
        glm::vec3 _rotation{0.0f};
        float near_clip_;
    };
}