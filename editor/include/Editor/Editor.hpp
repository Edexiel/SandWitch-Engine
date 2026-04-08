#ifndef QUACKENGINE_EDITOR_HPP
#define QUACKENGINE_EDITOR_HPP

#include <cstdint>
#include <vector>
#include <memory>
#include <string>

#include "CameraEditor.hpp"

class Editor
{
private:
    std::vector<std::unique_ptr<class Widget>> m_widgets;
    std::unique_ptr<class Widget> m_menuBar;

    class Engine &m_engine;

    void InitWidgets();
    static void InitImGui(struct GLFWwindow *window);
    static void SetStyle();
    static void SetIo();

public:
    std::int32_t selectedEntity = 0;
    bool showProperties{true};
    std::string assetName;
    CameraEditor camera = CameraEditor(1280, 720, 5000.f, 0.01f, 3.1415f * 60 / 180.f);

    explicit Editor();
    ~Editor();
    void Draw();
    Engine &GetEngine() const;
};

inline Engine &Editor::GetEngine() const
{
    return m_engine;
}

#endif //QUACKENGINE_EDITOR_HPP
