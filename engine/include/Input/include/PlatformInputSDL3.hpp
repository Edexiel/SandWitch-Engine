#pragma once

#include <SDL3/SDL.h>
#include <functional>

#include "PlatformInput.hpp"

namespace Input
{
class PlatformInputSDL3 : public PlatformInput
{
public:
    PlatformInputSDL3() = default;
    ~PlatformInputSDL3() override = default;

    std::function<void()> windowCloseCallback;

    void PollEvents() override;
    void UpdateCursorPosition(MousePosition& mousePosition) override;

private:
    static Key MapScancode(SDL_Scancode scancode);
    static MouseButton MapMouseButton(Uint8 sdlButton);
};
} // namespace Input
