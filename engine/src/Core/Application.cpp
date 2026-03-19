#include "Core/Application.hpp"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

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

#ifdef __EMSCRIPTEN__
    // Browser controls the event loop — hand off one frame at a time via requestAnimationFrame.
    // simulate_infinite_loop=1 unwinds the stack via longjmp so Run() never returns.
    // OnShutdown() is not called automatically; hook emscripten_set_beforeunload_callback if needed.
    emscripten_set_main_loop_arg([](void* arg) {
        static_cast<Application*>(arg)->Tick();
    }, this, 0, 1);
#else
    while (_running)
    {
        Tick();
    }

    OnShutdown();
#endif
}