#pragma once

#include <string>
#include <entt/entt.hpp>

class Entity;

class Scene
{
public:
    Scene() = default;
    explicit Scene(std::string name);
    ~Scene() = default;

    Entity CreateEntity(const std::string& name = "Entity");
    void   DestroyEntity(Entity entity);

    void OnUpdate(float deltaTime);

    entt::registry& Registry() { return _registry; }

private:
    std::string    _name;
    entt::registry _registry;
};