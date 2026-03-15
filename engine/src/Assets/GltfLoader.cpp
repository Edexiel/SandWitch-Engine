#include "Assets/GltfLoader.hpp"

namespace Assets
{
    std::optional<Renderer::Mesh> GltfLoader::Load(const std::string& /*path*/)
    {
        // TODO: implement using fastgltf
        return std::nullopt;
    }
}