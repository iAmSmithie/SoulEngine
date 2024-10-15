cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(SOULENGINE)

include_directories(
    src 
)

add_library(SoulEngine
        src/SoulEngine/Component.h
        src/SoulEngine/entity.h
        src/SoulEngine/SoulEngine.h
        src/SoulEngine/core.cpp 
        src/SoulEngine/core.h
)

add_executable(Demo
        src/Demo/Main.cpp
        src/Demo/Employee.cpp
        src/Demo/Employee.h
)
target_link_libraries(Demo SoulEngine)