#include "Core/Application.hpp"

void Application::Tick()
{
    using Clock     = std::chrono::steady_clock;
    auto  now       = Clock::now();
    float deltaTime = std::chrono::duration<float>(now - _lastTime).count();
    _lastTime       = now;

    OnUpdate(deltaTime);
    OnRender();
}

void Application::Run()
{
    _running  = true;
    _lastTime = std::chrono::steady_clock::now();
    OnInit();

    while (_running)
    {
        Tick();
    }

    OnShutdown();
}