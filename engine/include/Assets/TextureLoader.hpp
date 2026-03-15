#pragma once

#include <string>
#include <cstdint>

namespace Assets
{
    struct TextureData
    {
        int      width{0};
        int      height{0};
        int      channels{0};
        uint8_t* data{nullptr};
    };

    class TextureLoader
    {
    public:
        static TextureData Load(const std::string& path);
        static void        Free(TextureData& data);
    };
}