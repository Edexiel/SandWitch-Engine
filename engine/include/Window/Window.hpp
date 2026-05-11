#pragma once

#include <SDL3/SDL.h>
#include <string>

class Window
{
public:
    Window() = default;
    ~Window() = default;

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    bool Init(const std::string& title, int width, int height, bool fullscreen);
    void Shutdown();
    void SwapBuffers();

    bool ShouldClose() const { return m_shouldClose; }
    void Close() { m_shouldClose = true; }
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }

    SDL_Window* GetSDLWindow() const { return m_window; }
    SDL_GLContext GetGLContext() const { return m_glContext; }

private:
    SDL_Window* m_window{nullptr};
    SDL_GLContext m_glContext{nullptr};
    int m_width{0};
    int m_height{0};
    bool m_shouldClose{false};
};
