#pragma once

#include <chrono>

class Application
{
public:
    virtual ~Application() = default;

    virtual void OnInit()                      {}
    virtual void OnUpdate(float /*deltaTime*/) {}
    virtual void OnRender()                    {}
    virtual void OnShutdown()                  {}

    void Run();
    void Stop() { _running = false; }

    void Tick();

protected:
    bool _running{false};

private:
    std::chrono::steady_clock::time_point _lastTime{};
};