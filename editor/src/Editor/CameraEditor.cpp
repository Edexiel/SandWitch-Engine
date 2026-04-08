#include "Editor/CameraEditor.hpp"

#include <algorithm>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/vec2.hpp>

#include "Engine.hpp"
#include "Input/InputManager.hpp"
#include "Renderer/RendererPlatform.hpp"

CameraEditor::CameraEditor(unsigned int width, unsigned int height, float far, float near, float fov)
    : m_width{width}, m_height{height}, m_far{far}, m_near{near}, m_fov{fov}, m_isPerspective{true}, m_framebuffer{Renderer::RendererPlatform::CreateFramebuffer(width, height)}
{
}

void CameraEditor::SetRightScale(float scale)
{
    m_rightScale = scale;
}

void CameraEditor::SetLeftScale(float scale)
{
    m_leftScale = scale;
}

void CameraEditor::SetForwardScale(float scale)
{
    m_forwardScale = scale;
}

void CameraEditor::SetBackwardScale(float scale)
{
    m_backwardScale = scale;
}

void CameraEditor::SetUpScale(float scale)
{
    m_upScale = scale;
}

void CameraEditor::SetDownScale(float scale)
{
    m_downScale = scale;
}

void CameraEditor::SetInput()
{
    Input::InputManager& inputManager = Engine::Instance().GetInputManager();
    inputManager.RegisterEventAxis("CameraEditorMovementForward", this, &CameraEditor::SetForwardScale);
    inputManager.RegisterEventAxis("CameraEditorMovementBackward", this, &CameraEditor::SetBackwardScale);
    inputManager.RegisterEventAxis("CameraEditorMovementRight", this, &CameraEditor::SetRightScale);
    inputManager.RegisterEventAxis("CameraEditorMovementLeft", this, &CameraEditor::SetLeftScale);
    inputManager.RegisterEventAxis("CameraEditorMovementUp", this, &CameraEditor::SetUpScale);
    inputManager.RegisterEventAxis("CameraEditorMovementDown", this, &CameraEditor::SetDownScale);
}

void CameraEditor::FreeFly()
{
    glm::vec3 forward = m_rotation * glm::vec3(0.0f, 0.0f, -1.0f) * (m_forwardScale + m_backwardScale);
    glm::vec3 right = m_rotation * glm::vec3(1.0f, 0.0f, 0.0f) * (m_rightScale + m_leftScale);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f) * (m_upScale + m_downScale);
    glm::vec3 combined = forward + right + up;
    glm::vec3 direction = glm::length(combined) > 0.0f ? glm::normalize(combined) : glm::vec3(0.0f);
    m_position += direction * m_speedTranslation * Engine::Instance().GetTimeManager().GetDeltaTime();
}

void CameraEditor::MouseMovement(const glm::vec2& currentPos, const glm::vec2& oldPos)
{
    glm::vec2 delta = currentPos - oldPos;
    m_yaw += delta.x * m_speedRotation;
    m_pitch = std::clamp(m_pitch + delta.y * m_speedRotation, -glm::half_pi<float>(), glm::half_pi<float>());
    m_rotation = glm::angleAxis(m_yaw, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::angleAxis(m_pitch, glm::vec3(1.0f, 0.0f, 0.0f));
}
