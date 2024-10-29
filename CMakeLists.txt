cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(SOULENGINE)

include_directories(
    src
    contrib/cl-windows-x86_64/include
)

link_directories(
 ${PROJECT_SOURCE_DIR}/contrib/cl-windows-x86_64/lib
)

add_library(Rendy
 src/Rendy/Mesh.h
 src/Rendy/Model.h
 src/Rendy/Shader.h
 src/Rendy/Texture.h
 src/Rendy/Mesh.cpp
 src/Rendy/Texture.cpp
 src/Rendy/Rend.h
)

target_link_libraries(Rendy SDL2 SDL2main glew32 OpenGL32)

add_library(SoulEngine
        src/SoulEngine/Component.h
        src/SoulEngine/entity.h
        src/SoulEngine/SoulEngine.h
        src/SoulEngine/core.cpp 
        src/SoulEngine/core.h
        src/SoulEngine/Entity.cpp
        src/SoulEngine/Component.cpp
        src/SoulEngine/Window.h
        src/SoulEngine/Window.cpp
)

target_link_libraries(SoulEngine Rendy)

add_executable(Demo
        src/Demo/Main.cpp
        src/Demo/Employee.cpp
        src/Demo/Employee.h
)


target_link_libraries(Demo Rendy SoulEngine)