#pragma once

#include <vector>
#include <cstdint>
#include <glm/glm.hpp>

namespace Renderer
{
    struct Vertex
    {
        glm::vec3 position{};
        glm::vec3 normal{};
        glm::vec2 texCoord{};
    };

    class Mesh
    {
    public:
        Mesh() = default;
        Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices);

        const std::vector<Vertex>&   GetVertices() const { return _vertices; }
        const std::vector<uint32_t>& GetIndices()  const { return _indices; }

    private:
        std::vector<Vertex>   _vertices;
        std::vector<uint32_t> _indices;

        uint32_t _vao{0};
        uint32_t _vbo{0};
        uint32_t _ebo{0};
    };
}