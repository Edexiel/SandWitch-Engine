#include "Scene/Entity.hpp"

Entity::Entity(entt::entity handle, Scene* scene)
    : _handle(handle)
    , _scene(scene)
{
}