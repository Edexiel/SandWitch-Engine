#ifndef QUACKENGINE_SCENEWIDGET_HPP
#define QUACKENGINE_SCENEWIDGET_HPP

#include <glm/mat4x4.hpp>

#include "ImGuizmo.h"
#include "Widgets/Widget.hpp"

class SceneWidget : public Widget
{
private:
    bool _isCameraRotating = false;

    ImGuizmo::OPERATION _operation = ImGuizmo::OPERATION::TRANSLATE;
    ImGuizmo::MODE _mode = ImGuizmo::MODE::WORLD;

    void CameraUpdate();
    void MouseMovement();
    void ImGuizmoUpdate(const glm::mat4& view, const glm::mat4& projection);
    void SelectOperation();
    void ManipulateEntity(const glm::mat4& view, const glm::mat4& projection);

    glm::mat4 _mat;

public:
    SceneWidget(Editor& editor);

    void UpdateVisible() final;
};

#endif //QUACKENGINE_SCENEWIDGET_HPP
