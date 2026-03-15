#pragma once

#include <string_view>

struct EngineSettings
{
    std::string_view windowTitle{};
    int windowSize[2];
    WINDOW_MODE mode{};
    int monitor = 0;
    bool debug;
};

class Engine
{
private:
public:
    Engine(EngineSettings& engine_settings);
    ~Engine();
};
