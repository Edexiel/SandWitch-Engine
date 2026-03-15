#pragma once

#include "Core/Application.hpp"

class GameApp : public Application
{
public:
    void OnInit()               override;
    void OnUpdate(float /*deltaTime*/) override;
    void OnRender()             override;
    void OnShutdown()           override;
};