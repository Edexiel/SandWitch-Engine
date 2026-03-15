#pragma once

class RenderContext
{
public:
    RenderContext() = default;
    ~RenderContext() = default;

    void Init();
    void Shutdown();
    void BeginFrame();
    void EndFrame();
};