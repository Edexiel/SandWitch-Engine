#include "Widgets/SceneWidget.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Editor.hpp"
#include "Engine.hpp"
#include "GLFW/glfw3.h"
#include "Renderer/RendererInterface.hpp"
#include "Scene/Component/Transform.hpp"
#include "Scene/Core/World.hpp"

using namespace Renderer;
SceneWidget::SceneWidget(Editor& editor) : Widget(editor)
{
    _title = "Scene";
    _editor.camera.SetInput();
}

void SceneWidget::UpdateVisible()
{
    ImGui::BeginChild("ViewportRender");
    // Get the size of the child (i.e. the whole draw size of the windows).

    CameraUpdate();
    MouseMovement();

    ImGui::EndChild();
}

void SceneWidget::MouseMovement()
{
    ImGuiIO& io = ImGui::GetIO();
    GLFWwindow* window = _engine.GetWindow();

    if (ImGui::IsMouseClicked(1, true) && ImGui::IsItemHovered())
    {
        io.ConfigFlags |= ImGuiConfigFlags_NoMouse;
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        _isCameraRotating = true;
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2) == GLFW_RELEASE)
    {
        io.ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
        io.WantCaptureMouse = false;
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        _isCameraRotating = false;
    }
    if (_isCameraRotating)
    {
        Input::MousePosition mp = _engine.GetInputManager().mousePosition;
        _editor.camera.MouseMovement(glm::vec2(mp.pos), glm::vec2(mp.prevPos));
    }
}

void SceneWidget::CameraUpdate()
{
    const ImVec2 wsize = ImGui::GetWindowSize();

    _editor.camera.m_width = (unsigned int) wsize.x;
    _editor.camera.m_height = (unsigned int) wsize.y;

    _editor.camera.FreeFly();

    glm::mat4 projection = glm::perspective(_editor.camera.m_fov, (float) _editor.camera.m_width / (float) _editor.camera.m_height, _editor.camera.m_near, _editor.camera.m_far);
    glm::mat4 view = glm::inverse(glm::translate(glm::mat4(1.0f), _editor.camera.m_position) * glm::mat4_cast(_editor.camera.m_rotation) *
                                  glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, -1.0f)));

    //todo Add Back
    RendererInterface::UpdateSceneFramebufferEditor(projection, view, _editor.camera.m_framebuffer);
    ImGui::Image((ImTextureID) (size_t) _editor.camera.m_framebuffer.GetTexture(), wsize, ImVec2(0, 1), ImVec2(1, 0));

    ImGuizmoUpdate(view, projection);
}

void SceneWidget::ImGuizmoUpdate(const glm::mat4& view, const glm::mat4& projection)
{
    ImGuizmo::BeginFrame();
    SelectOperation();

    ImGuizmo::SetDrawlist();
    ImGuizmo::SetRect(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, (float) _editor.camera.m_width, (float) _editor.camera.m_height);
    //    ImGuizmo::DrawGrid(glm::value_ptr(view), glm::value_ptr(projection), glm::value_ptr(glm::mat4(1.0f)), 100.f);

    ManipulateEntity(view, projection);
}

void SceneWidget::SelectOperation()
{
    GLFWwindow* window = _engine.GetWindow();

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        _operation = ImGuizmo::OPERATION::TRANSLATE;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        _operation = ImGuizmo::OPERATION::ROTATE;
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        _operation = ImGuizmo::OPERATION::SCALE;
    }
}

void SceneWidget::ManipulateEntity(const glm::mat4& view, const glm::mat4& projection)
{
    if (!_engine.GetCurrentWorld().HasComponent<Component::Transform>(_editor.selectedEntity))
    {
        return;
    }

    auto& transform = _engine.GetCurrentWorld().GetComponent<Component::Transform>(_editor.selectedEntity);

    glm::vec3 eulerDeg = glm::eulerAngles(transform.rotation) * RadToDeg<float>();
    ImGuizmo::RecomposeMatrixFromComponents(glm::value_ptr(transform.position), glm::value_ptr(eulerDeg), glm::value_ptr(transform.scale), glm::value_ptr(_mat));

    ImGuizmo::Manipulate(glm::value_ptr(view), glm::value_ptr(projection), _operation, _mode, glm::value_ptr(_mat));

    glm::vec3 translation;
    glm::vec3 eulerRotation;
    glm::vec3 scale;
    ImGuizmo::DecomposeMatrixToComponents(glm::value_ptr(_mat), glm::value_ptr(translation), glm::value_ptr(eulerRotation), glm::value_ptr(scale));

    transform.position = translation;
    transform.rotation = glm::quat(eulerRotation * DegToRad<float>());
    transform.scale = scale;
}
