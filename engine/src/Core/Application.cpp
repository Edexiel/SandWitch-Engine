#include "Core/Application.hpp"

void Application::Tick()
{
    const float deltaTime = _timer.getElapsedSeconds();
    _timer.start();

    OnUpdate(deltaTime);
    OnRender();
}

void Application::Run()
{
    _running = true;
    _timer.start();
    OnInit();

    while (_running)
    {
        Tick();
    }

    OnShutdown();
}