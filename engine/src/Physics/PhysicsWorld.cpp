#include "Physics/PhysicsWorld.hpp"

namespace Physics
{
    PhysicsWorld::PhysicsWorld()  = default;
    PhysicsWorld::~PhysicsWorld() { Shutdown(); }

    void PhysicsWorld::Init()
    {
        // TODO: initialize Jolt Physics
    }

    void PhysicsWorld::Step(float /*deltaTime*/)
    {
        // TODO: step Jolt simulation
    }

    void PhysicsWorld::Shutdown()
    {
        // TODO: cleanup Jolt Physics
    }
}