#include "Assets/AssetManager.hpp"

AssetManager& AssetManager::Instance()
{
    static AssetManager instance;
    return instance;
}