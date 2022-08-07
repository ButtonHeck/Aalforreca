cmake_minimum_required(VERSION 3.13)

project(alrcTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES "src/tests.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories("../include/Aalforreca")

target_include_directories(${PROJECT_NAME}
    PRIVATE vendor/GLFW/include
    PRIVATE vendor/Glad/include
    PRIVATE vendor/ImGui
    PRIVATE vendor/ImGuizmo
    PRIVATE vendor/assimp/include
    PRIVATE vendor/doctest
    PRIVATE vendor/entt/include
    PRIVATE vendor/glm
    PRIVATE vendor/qu3e/src
    PRIVATE vendor/spdlog/include
    PRIVATE vendor/stb_image
    PRIVATE vendor/yaml-cpp/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE vendor/GLFW/src
    PRIVATE vendor/Glad/src
    PRIVATE vendor/ImGui
    PRIVATE vendor/ImGuizmo
    PRIVATE vendor/assimp/lib
    PRIVATE vendor/doctest/parts
    PRIVATE vendor/qu3e/src
    PRIVATE vendor/spdlog
    PRIVATE vendor/stb_image
    PRIVATE vendor/yaml-cpp/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw
    PRIVATE glad
    PRIVATE assimp
    PRIVATE doctest
    PRIVATE qu3e
    PRIVATE spdlog
    PRIVATE yaml-cpp
)
