#pragma once

#include <string>
#include <optional>
#include "Renderer/Mesh.hpp"

namespace Assets
{
    class GltfLoader
    {
    public:
        static std::optional<Renderer::Mesh> Load(const std::string& path);
    };
}