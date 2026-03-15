#pragma once

#include <cstdint>
#include <unordered_map>
#include <memory>

using AssetID = uint64_t;

template<typename T>
struct AssetHandle
{
    AssetID id{0};
    bool IsValid() const { return id != 0; }
};

class AssetManager
{
public:
    static AssetManager& Instance();

private:
    AssetManager() = default;

    std::unordered_map<AssetID, std::shared_ptr<void>> _cache;
};