#pragma once

#include <string>

enum class WINDOW_MODE
{
    WINDOWED,
    FULLSCREEN,
    WINDOWED_FULLSCREEN,
};

struct EngineSettings
{
    std::string windowTitle{};
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
