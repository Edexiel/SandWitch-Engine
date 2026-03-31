#pragma once

#include "Timer/Timer.hpp"

class Application
{
public:
    virtual ~Application() = default;

    virtual void OnInit() {}
    virtual void OnUpdate(float deltaTime) = 0;
    virtual void OnRender() {}
    virtual void OnShutdown() {}

    void Run();
    void Stop() { _running = false; }
    void Tick();

protected:
    bool _running{false};

private:
    Timer _timer;
};