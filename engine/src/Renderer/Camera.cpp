#include "Renderer/Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace Renderer
{
    Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip) : near_clip_(nearClip)
    {
        _projection = glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
        RecalculateView();
    }

    glm::mat4 Camera::GetViewProjection() const
    {
        return _projection * _view;
    }

    void Camera::SetPosition(const glm::vec3& position)
    {
        _position = position;
        RecalculateView();
    }

    void Camera::SetRotation(const glm::vec3& eulerAngles)
    {
        _rotation = eulerAngles;
        RecalculateView();
    }

    void Camera::RecalculateView()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), _position);
        transform = glm::rotate(transform, _rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, _rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
        _view = glm::inverse(transform);
    }
}