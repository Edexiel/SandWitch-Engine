#pragma once

#include "Core/Application.hpp"

#include <memory>

class Editor;

class EditorApp : public Application
{
public:
    void OnInit()                  override;
    void OnUpdate(float deltaTime) override;
    void OnRender()                override;
    void OnShutdown()              override;

private:
    std::unique_ptr<Editor> _editor;
};
