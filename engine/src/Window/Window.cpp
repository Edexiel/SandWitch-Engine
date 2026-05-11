#include "Window/Window.hpp"

#include "Debug/Log.hpp"

bool Window::Init(const std::string& title, int width, int height, bool fullscreen)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Log_Error("SDL_Init failed: {}", SDL_GetError());
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (m_window == nullptr)
    {
        Log_Error("SDL_CreateWindow failed: {}", SDL_GetError());
        SDL_Quit();
        return false;
    }

    if (fullscreen)
    {
        SDL_SetWindowFullscreen(m_window, true);
    }

    m_glContext = SDL_GL_CreateContext(m_window);
    if (m_glContext == nullptr)
    {
        Log_Error("SDL_GL_CreateContext failed: {}", SDL_GetError());
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
        SDL_Quit();
        return false;
    }

    SDL_GL_SetSwapInterval(1);
    m_width = width;
    m_height = height;
    return true;
}

void Window::Shutdown()
{
    if (m_glContext != nullptr)
    {
        SDL_GL_DestroyContext(m_glContext);
        m_glContext = nullptr;
    }
    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
}

void Window::SwapBuffers()
{
    SDL_GL_SwapWindow(m_window);
}
