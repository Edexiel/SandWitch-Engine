#pragma once

class Scene;

namespace Renderer
{
    class RenderPipeline
    {
    public:
        virtual ~RenderPipeline() = default;

        virtual void Init()               = 0;
        virtual void Render(Scene& scene) = 0;
        virtual void Shutdown()           = 0;
    };
}