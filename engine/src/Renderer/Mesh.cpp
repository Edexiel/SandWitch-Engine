#include "Renderer/Mesh.hpp"

namespace Renderer
{
    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices)
        : _vertices(std::move(vertices))
        , _indices(std::move(indices))
    {
    }
}