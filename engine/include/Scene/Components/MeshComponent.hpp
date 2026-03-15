#pragma once

#include "Renderer/Mesh.hpp"
#include "Renderer/Material.hpp"

namespace Components
{
    struct MeshComponent
    {
        Renderer::Mesh*    mesh{nullptr};
        Renderer::Material material{};
    };
}