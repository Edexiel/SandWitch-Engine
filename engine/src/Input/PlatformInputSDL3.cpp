#include "Input/include/PlatformInputSDL3.hpp"

namespace Input
{

void PlatformInputSDL3::PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT: {
                if (windowCloseCallback)
                {
                    windowCloseCallback();
                }
                break;
            }
            case SDL_EVENT_KEY_DOWN:
            case SDL_EVENT_KEY_UP: {
                const Key key = MapScancode(event.key.scancode);
                if (key != Key::KEY_COUNT && keyEvent)
                {
                    const Action action = event.key.repeat ? Action::REPEAT : (event.key.down ? Action::PRESS : Action::RELEASE);
                    keyEvent(action, key);
                }
                break;
            }
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            case SDL_EVENT_MOUSE_BUTTON_UP: {
                if (MouseButtonEvent)
                {
                    const Action action = event.button.down ? Action::PRESS : Action::RELEASE;
                    MouseButtonEvent(action, MapMouseButton(event.button.button));
                }
                break;
            }
            case SDL_EVENT_MOUSE_MOTION: {
                if (UpdateMousePosition)
                {
                    UpdateMousePosition(event.motion.x, event.motion.y);
                }
                break;
            }
            default:
                break;
        }
    }
}

void PlatformInputSDL3::UpdateCursorPosition(MousePosition& mousePosition)
{
    mousePosition.prevPos = mousePosition.pos;
    float x{0.0f};
    float y{0.0f};
    SDL_GetMouseState(&x, &y);
    mousePosition.pos = {x, y};
}

Key PlatformInputSDL3::MapScancode(SDL_Scancode scancode)
{
    switch (scancode)
    {
        case SDL_SCANCODE_SPACE:
            return Key::KEY_SPACE;
        case SDL_SCANCODE_APOSTROPHE:
            return Key::KEY_APOSTROPHE;
        case SDL_SCANCODE_COMMA:
            return Key::KEY_COMMA;
        case SDL_SCANCODE_MINUS:
            return Key::KEY_MINUS;
        case SDL_SCANCODE_PERIOD:
            return Key::KEY_PERIOD;
        case SDL_SCANCODE_SLASH:
            return Key::KEY_SLASH;
        case SDL_SCANCODE_0:
            return Key::KEY_0;
        case SDL_SCANCODE_1:
            return Key::KEY_1;
        case SDL_SCANCODE_2:
            return Key::KEY_2;
        case SDL_SCANCODE_3:
            return Key::KEY_3;
        case SDL_SCANCODE_4:
            return Key::KEY_4;
        case SDL_SCANCODE_5:
            return Key::KEY_5;
        case SDL_SCANCODE_6:
            return Key::KEY_6;
        case SDL_SCANCODE_7:
            return Key::KEY_7;
        case SDL_SCANCODE_8:
            return Key::KEY_8;
        case SDL_SCANCODE_9:
            return Key::KEY_9;
        case SDL_SCANCODE_SEMICOLON:
            return Key::KEY_SEMICOLON;
        case SDL_SCANCODE_EQUALS:
            return Key::KEY_EQUAL;
        case SDL_SCANCODE_A:
            return Key::KEY_A;
        case SDL_SCANCODE_B:
            return Key::KEY_B;
        case SDL_SCANCODE_C:
            return Key::KEY_C;
        case SDL_SCANCODE_D:
            return Key::KEY_D;
        case SDL_SCANCODE_E:
            return Key::KEY_E;
        case SDL_SCANCODE_F:
            return Key::KEY_F;
        case SDL_SCANCODE_G:
            return Key::KEY_G;
        case SDL_SCANCODE_H:
            return Key::KEY_H;
        case SDL_SCANCODE_I:
            return Key::KEY_I;
        case SDL_SCANCODE_J:
            return Key::KEY_J;
        case SDL_SCANCODE_K:
            return Key::KEY_K;
        case SDL_SCANCODE_L:
            return Key::KEY_L;
        case SDL_SCANCODE_M:
            return Key::KEY_M;
        case SDL_SCANCODE_N:
            return Key::KEY_N;
        case SDL_SCANCODE_O:
            return Key::KEY_O;
        case SDL_SCANCODE_P:
            return Key::KEY_P;
        case SDL_SCANCODE_Q:
            return Key::KEY_Q;
        case SDL_SCANCODE_R:
            return Key::KEY_R;
        case SDL_SCANCODE_S:
            return Key::KEY_S;
        case SDL_SCANCODE_T:
            return Key::KEY_T;
        case SDL_SCANCODE_U:
            return Key::KEY_U;
        case SDL_SCANCODE_V:
            return Key::KEY_V;
        case SDL_SCANCODE_W:
            return Key::KEY_W;
        case SDL_SCANCODE_X:
            return Key::KEY_X;
        case SDL_SCANCODE_Y:
            return Key::KEY_Y;
        case SDL_SCANCODE_Z:
            return Key::KEY_Z;
        case SDL_SCANCODE_LEFTBRACKET:
            return Key::KEY_LEFT_BRACKET;
        case SDL_SCANCODE_BACKSLASH:
            return Key::KEY_BACKSLASH;
        case SDL_SCANCODE_RIGHTBRACKET:
            return Key::KEY_RIGHT_BRACKET;
        case SDL_SCANCODE_GRAVE:
            return Key::KEY_GRAVE_ACCENT;
        case SDL_SCANCODE_NONUSBACKSLASH:
            return Key::KEY_WORLD_1;
        case SDL_SCANCODE_NONUSHASH:
            return Key::KEY_WORLD_2;
        case SDL_SCANCODE_ESCAPE:
            return Key::KEY_ESCAPE;
        case SDL_SCANCODE_RETURN:
            return Key::KEY_ENTER;
        case SDL_SCANCODE_TAB:
            return Key::KEY_TAB;
        case SDL_SCANCODE_BACKSPACE:
            return Key::KEY_BACKSPACE;
        case SDL_SCANCODE_INSERT:
            return Key::KEY_INSERT;
        case SDL_SCANCODE_DELETE:
            return Key::KEY_DELETE;
        case SDL_SCANCODE_RIGHT:
            return Key::KEY_RIGHT;
        case SDL_SCANCODE_LEFT:
            return Key::KEY_LEFT;
        case SDL_SCANCODE_DOWN:
            return Key::KEY_DOWN;
        case SDL_SCANCODE_UP:
            return Key::KEY_UP;
        case SDL_SCANCODE_PAGEUP:
            return Key::KEY_PAGE_UP;
        case SDL_SCANCODE_PAGEDOWN:
            return Key::KEY_PAGE_DOWN;
        case SDL_SCANCODE_HOME:
            return Key::KEY_HOME;
        case SDL_SCANCODE_END:
            return Key::KEY_END;
        case SDL_SCANCODE_CAPSLOCK:
            return Key::KEY_CAPS_LOCK;
        case SDL_SCANCODE_SCROLLLOCK:
            return Key::KEY_SCROLL_LOCK;
        case SDL_SCANCODE_NUMLOCKCLEAR:
            return Key::KEY_NUM_LOCK;
        case SDL_SCANCODE_PRINTSCREEN:
            return Key::KEY_PRINT_SCREEN;
        case SDL_SCANCODE_PAUSE:
            return Key::KEY_PAUSE;
        case SDL_SCANCODE_F1:
            return Key::KEY_F1;
        case SDL_SCANCODE_F2:
            return Key::KEY_F2;
        case SDL_SCANCODE_F3:
            return Key::KEY_F3;
        case SDL_SCANCODE_F4:
            return Key::KEY_F4;
        case SDL_SCANCODE_F5:
            return Key::KEY_F5;
        case SDL_SCANCODE_F6:
            return Key::KEY_F6;
        case SDL_SCANCODE_F7:
            return Key::KEY_F7;
        case SDL_SCANCODE_F8:
            return Key::KEY_F8;
        case SDL_SCANCODE_F9:
            return Key::KEY_F9;
        case SDL_SCANCODE_F10:
            return Key::KEY_F10;
        case SDL_SCANCODE_F11:
            return Key::KEY_F11;
        case SDL_SCANCODE_F12:
            return Key::KEY_F12;
        case SDL_SCANCODE_F13:
            return Key::KEY_F13;
        case SDL_SCANCODE_F14:
            return Key::KEY_F14;
        case SDL_SCANCODE_F15:
            return Key::KEY_F15;
        case SDL_SCANCODE_F16:
            return Key::KEY_F16;
        case SDL_SCANCODE_F17:
            return Key::KEY_F17;
        case SDL_SCANCODE_F18:
            return Key::KEY_F18;
        case SDL_SCANCODE_F19:
            return Key::KEY_F19;
        case SDL_SCANCODE_F20:
            return Key::KEY_F20;
        case SDL_SCANCODE_F21:
            return Key::KEY_F21;
        case SDL_SCANCODE_F22:
            return Key::KEY_F22;
        case SDL_SCANCODE_F23:
            return Key::KEY_F23;
        case SDL_SCANCODE_F24:
            return Key::KEY_F24;
        // SDL3 has no SDL_SCANCODE_F25 — KEY_F25 is unmappable
        case SDL_SCANCODE_KP_0:
            return Key::KEY_KP_0;
        case SDL_SCANCODE_KP_1:
            return Key::KEY_KP_1;
        case SDL_SCANCODE_KP_2:
            return Key::KEY_KP_2;
        case SDL_SCANCODE_KP_3:
            return Key::KEY_KP_3;
        case SDL_SCANCODE_KP_4:
            return Key::KEY_KP_4;
        case SDL_SCANCODE_KP_5:
            return Key::KEY_KP_5;
        case SDL_SCANCODE_KP_6:
            return Key::KEY_KP_6;
        case SDL_SCANCODE_KP_7:
            return Key::KEY_KP_7;
        case SDL_SCANCODE_KP_8:
            return Key::KEY_KP_8;
        case SDL_SCANCODE_KP_9:
            return Key::KEY_KP_9;
        case SDL_SCANCODE_KP_PERIOD:
            return Key::KEY_KP_DECIMAL;
        case SDL_SCANCODE_KP_DIVIDE:
            return Key::KEY_KP_DIVIDE;
        case SDL_SCANCODE_KP_MULTIPLY:
            return Key::KEY_KP_MULTIPLY;
        case SDL_SCANCODE_KP_MINUS:
            return Key::KEY_KP_SUBTRACT;
        case SDL_SCANCODE_KP_PLUS:
            return Key::KEY_KP_ADD;
        case SDL_SCANCODE_KP_ENTER:
            return Key::KEY_KP_ENTER;
        case SDL_SCANCODE_KP_EQUALS:
            return Key::KEY_KP_EQUAL;
        case SDL_SCANCODE_LSHIFT:
            return Key::KEY_LEFT_SHIFT;
        case SDL_SCANCODE_LCTRL:
            return Key::KEY_LEFT_CONTROL;
        case SDL_SCANCODE_LALT:
            return Key::KEY_LEFT_ALT;
        case SDL_SCANCODE_LGUI:
            return Key::KEY_LEFT_SUPER;
        case SDL_SCANCODE_RSHIFT:
            return Key::KEY_RIGHT_SHIFT;
        case SDL_SCANCODE_RCTRL:
            return Key::KEY_RIGHT_CONTROL;
        case SDL_SCANCODE_RALT:
            return Key::KEY_RIGHT_ALT;
        case SDL_SCANCODE_RGUI:
            return Key::KEY_RIGHT_SUPER;
        case SDL_SCANCODE_APPLICATION:
            return Key::KEY_MENU;
        default:
            return Key::KEY_COUNT;
    }
}

MouseButton PlatformInputSDL3::MapMouseButton(Uint8 sdlButton)
{
    switch (sdlButton)
    {
        case SDL_BUTTON_LEFT:
            return MouseButton::MOUSE_BUTTON_LEFT;
        case SDL_BUTTON_RIGHT:
            return MouseButton::MOUSE_BUTTON_RIGHT;
        case SDL_BUTTON_MIDDLE:
            return MouseButton::MOUSE_BUTTON_MIDDLE;
        case SDL_BUTTON_X1:
            return MouseButton::MOUSE_BUTTON_4;
        case SDL_BUTTON_X2:
            return MouseButton::MOUSE_BUTTON_5;
        default:
            return MouseButton::MOUSE_BUTTON_LEFT;
    }
}

} // namespace Input
