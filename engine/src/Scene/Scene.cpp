#include "Scene/Scene.hpp"
#include "Scene/Entity.hpp"

Scene::Scene(std::string name)
    : _name(std::move(name))
{
}

Entity Scene::CreateEntity(const std::string& /*name*/)
{
    entt::entity handle = _registry.create();
    return Entity(handle, this);
}

void Scene::DestroyEntity(Entity entity)
{
    _registry.destroy(entity.GetHandle());
}

void Scene::OnUpdate(float /*deltaTime*/)
{
    // Systems will be dispatched here
}