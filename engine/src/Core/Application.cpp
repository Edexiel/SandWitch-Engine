#include "Core/Application.hpp"

#include <chrono>

void Application::Run()
{
    _running = true;
    OnInit();

    using Clock    = std::chrono::steady_clock;
    auto lastTime  = Clock::now();

    while (_running)
    {
        auto  now       = Clock::now();
        float deltaTime = std::chrono::duration<float>(now - lastTime).count();
        lastTime        = now;

        OnUpdate(deltaTime);
        OnRender();
    }

    OnShutdown();
}