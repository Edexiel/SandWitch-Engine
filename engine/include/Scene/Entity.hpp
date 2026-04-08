#pragma once

// #include <entt/entt.hpp>

class Scene;

class Entity
{
public:
    Entity() = default;
    // Entity(entt::entity handle, Scene* scene);

    template<typename T, typename... Args>
    T& AddComponent(Args&&... args);

    template<typename T>
    T& GetComponent();

    template<typename T>
    bool HasComponent() const;

    template<typename T>
    void RemoveComponent();

    // bool         IsValid()    const { return _handle != entt::null; }
    // entt::entity GetHandle()  const { return _handle; }

private:
    // entt::entity _handle{entt::null};
    Scene*       _scene{nullptr};
};

#include "Scene/Scene.hpp"

// template<typename T, typename... Args>
// T& Entity::AddComponent(Args&&... args)
// {
//     return _scene->Registry().emplace<T>(_handle, std::forward<Args>(args)...);
// }
//
// template<typename T>
// T& Entity::GetComponent()
// {
//     return _scene->Registry().get<T>(_handle);
// }
//
// template<typename T>
// bool Entity::HasComponent() const
// {
//     return _scene->Registry().all_of<T>(_handle);
// }
//
// template<typename T>
// void Entity::RemoveComponent()
// {
//     _scene->Registry().erase<T>(_handle);
// }