cmake_minimum_required(VERSION 3.15)
project(DodgeTheCubes)

set(CMAKE_CXX_STANDARD 17)


include_directories(${CMAKE_SOURCE_DIR}/src)

# Define the executable
add_executable(DodgeTheCubes
        src/main.cpp
        src/Renderer/Renderer.cpp src/Renderer/Renderer.h
        src/Game/Game.cpp src/Game/Game.h
        src/Player/Player.cpp src/Player/Player.h
        src/Input/Input.cpp src/Input/Input.h
        src/Cube/Cube.h
        src/Cube/Cube.cpp
)

# Link against DirectX 11 libraries
target_link_libraries(DodgeTheCubes
        d3d11
        dxgi
        d3dcompiler
)
