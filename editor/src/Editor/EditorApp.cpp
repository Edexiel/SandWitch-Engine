#include "Editor/EditorApp.hpp"
#include "Editor/Editor.hpp"

void EditorApp::OnInit()
{
    _editor = std::make_unique<Editor>();
}

void EditorApp::OnUpdate(float deltaTime)
{
    // TODO: poll window events and call Stop() when the window requests close
    (void)deltaTime;
}

void EditorApp::OnRender()
{
    _editor->Draw();
}

void EditorApp::OnShutdown()
{
    _editor.reset();
}
