#pragma once

class Application
{
public:
    virtual ~Application() = default;

    virtual void OnInit()                  {}
    virtual void OnUpdate(float /*deltaTime*/) {}
    virtual void OnRender()                {}
    virtual void OnShutdown()              {}

    void Run();
    void Stop() { _running = false; }

protected:
    bool _running{false};
};