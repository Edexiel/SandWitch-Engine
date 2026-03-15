#include "Assets/TextureLoader.hpp"

#include <cstdlib>

namespace Assets
{
    TextureData TextureLoader::Load(const std::string& /*path*/)
    {
        // TODO: implement (e.g. using stb_image)
        return TextureData{};
    }

    void TextureLoader::Free(TextureData& data)
    {
        std::free(data.data);
        data.data = nullptr;
    }
}