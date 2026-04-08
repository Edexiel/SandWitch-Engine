#ifndef QUACKENGINE_CAMERAEDITOR_HPP
#define QUACKENGINE_CAMERAEDITOR_HPP

#include <glm/gtc/quaternion.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "Renderer/Framebuffer.hpp"

namespace Input
{
class InputManager;
};
class SceneWidget;
class CameraEditor
{
private:
    glm::vec3 m_position{0.0f, 0.0f, -5.0f};
    glm::quat m_rotation{glm::identity<glm::quat>()};

    Renderer::Framebuffer m_framebuffer;

    unsigned int m_width;
    unsigned int m_height;

    bool m_isPerspective{true};

    float m_far;
    float m_near;
    float m_fov;

    float m_rightScale = 0;
    float m_leftScale = 0;
    float m_forwardScale = 0;
    float m_backwardScale = 0;
    float m_upScale = 0;
    float m_downScale = 0;

    float m_yaw = 0;
    float m_pitch = 0;

    float m_speedTranslation = 5.0f;
    float m_speedRotation = 0.01f;

    void SetRightScale(float scale);
    void SetLeftScale(float scale);
    void SetForwardScale(float scale);
    void SetBackwardScale(float scale);
    void SetUpScale(float scale);
    void SetDownScale(float scale);

    void FreeFly();
    void MouseMovement(const glm::vec2& currentPos, const glm::vec2& oldPos);

    friend SceneWidget;

public:
    CameraEditor(unsigned int width, unsigned int height, float far, float near, float fov);

    void SetInput();
};

#endif //QUACKENGINE_CAMERAEDITOR_HPP
