#pragma once

namespace Physics
{
    class PhysicsWorld
    {
    public:
        PhysicsWorld();
        ~PhysicsWorld();

        void Init();
        void Step(float deltaTime);
        void Shutdown();
    };
}