# SandWitch Engine

A C++17 game engine and editor built with SDL3, OpenGL, and a modular architecture.

## Prerequisites

### All Platforms
- [CMake](https://cmake.org/) ≥ 3.31.6
- A C++17-capable compiler
- Git (to fetch dependencies via CPM)

### Linux
- GCC ≥ 11 or Clang ≥ 13
- Development libraries required by SDL3:
  ```sh
  # Ubuntu / Debian
  sudo apt install build-essential libx11-dev libxext-dev libxrandr-dev \
      libxcursor-dev libxi-dev libxinerama-dev libgl1-mesa-dev \
      libpulse-dev libudev-dev libdbus-1-dev
  ```

### Windows
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with the **Desktop development with C++** workload, or MinGW-w64

### Web (Emscripten)
- [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) ≥ 3.1

---

## Building

All dependencies are fetched automatically by [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) — no manual `vcpkg` or `conan` setup required.

### Linux

```sh
cmake -B cmake-build-release -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release
```

Debug build:
```sh
cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug
```

### Windows

**Command Prompt / PowerShell:**
```bat
cmake -B cmake-build-release -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release --config Release
```

**Visual Studio:** open the repo folder with *File → Open → CMake…* and select the root `CMakeLists.txt`. Visual Studio will configure the project automatically.

### Web (Emscripten)

Make sure `emcmake` is on your `PATH` (run `emsdk_env.sh` / `emsdk_env.bat` first):

```sh
emcmake cmake -B cmake-build-web -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-web --target SandwitchGame
```

Output files (`SandwitchGame.html`, `.js`, `.wasm`) will be in `cmake-build-web/game/`. Serve them with any static HTTP server:

```sh
python3 -m http.server 8080 --directory cmake-build-web/game
# then open http://localhost:8080/SandwitchGame.html
```

> **Note:** The editor target is not built for web.

---

## Project Structure

```
SandWitch/
├── engine/          # Core engine library (SandwitchEngine)
│   ├── include/     # Public headers
│   ├── src/         # Implementation
│   └── vendor/      # Third-party dependencies (fetched via CPM)
├── editor/          # Editor application (desktop only)
├── game/            # Game application
└── cmake/           # CMake helpers (CPM.cmake)
```

## Dependencies

| Library | Purpose |
|---|---|
| SDL3 | Windowing & input |
| OpenGL / glad | Rendering |
| ImGui | UI |
| JoltPhysics | 3D physics |
| Box2D | 2D physics |
| EnTT | Entity-Component-System |
| glm | Math |
| fmt | Formatting |
| ozz-animation | Skeletal animation |
| sol2 | Lua scripting |
| miniaudio | Audio |
| Taskflow | Task parallelism |
| fastgltf | glTF asset loading |
| Tracy | Profiling (desktop only) |