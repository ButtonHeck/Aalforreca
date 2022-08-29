cmake_minimum_required(VERSION 3.16)

project(AalforrecaEngine VERSION 0.1)

configure_file(AalforrecaEngineConfig.h.in AalforrecaEngineConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
unset("QT_QMAKE_EXECUTABLE")


# Sources and includes
include_directories(
    "${PROJECT_SOURCE_DIR}/include/Aalforreca"
    "${PROJECT_SOURCE_DIR}/src"
    ${PROJECT_BINARY_DIR}
)
set(HEADER_FILES
    "${PROJECT_SOURCE_DIR}/include/Aalforreca/Core/application.h"
    "${PROJECT_SOURCE_DIR}/include/Aalforreca/Core/entry_point.h"
)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/src/Core/application.cpp"
)
set(PCH_SOURCE_FILE "${PROJECT_SOURCE_DIR}/src/alrcpch.cpp")
set(IMGUI_IMPL_DIR "${PROJECT_SOURCE_DIR}/vendor/ImGui/backends")

aux_source_directory(vendor/ImGui IMGUI_SRC)
aux_source_directory(vendor/ImGuizmo IMGUIZMO_SRC)
aux_source_directory(vendor/stb_image STB_IMAGE_SRC)


# Target
add_library(${PROJECT_NAME} STATIC
    ${HEADER_FILES}
    ${PCH_SOURCE_FILE}
    ${SOURCE_FILES}
    ${IMGUI_SRC}
    ${IMGUIZMO_SRC}
    ${IMGUI_IMPL_DIR}/imgui_impl_opengl3.cpp
    ${IMGUI_IMPL_DIR}/imgui_impl_glfw.cpp
    ${STB_IMAGE_SRC}
)


# Aalforreca options
option(AALFORRECA_BUILD_TESTS ON)
if(AALFORRECA_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(COMMAND target_precompile_headers)
    target_precompile_headers(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src/alrcpch.h")
endif()


# Download all the submodules
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/../.git")
    # update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" OFF)
    if (GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()


# check all the submodules
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/GLFW/CMakeLists.txt")
    message(FATAL_ERROR "GLFW submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/assimp/CMakeLists.txt")
    message(FATAL_ERROR "assimp submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/doctest/CMakeLists.txt")
    message(FATAL_ERROR "doctest submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/freetype/CMakeLists.txt")
    message(FATAL_ERROR "freetype submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/glm/CMakeLists.txt")
    message(FATAL_ERROR "glm submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/openal-soft/CMakeLists.txt")
    message(FATAL_ERROR "openal-soft submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/qu3e/CMakeLists.txt")
    message(FATAL_ERROR "qu3e submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/spdlog/CMakeLists.txt")
    message(FATAL_ERROR "spdlog submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/yaml-cpp/CMakeLists.txt")
    message(FATAL_ERROR "yaml-cpp submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()


# 3rd-party stuff
option(GLFW_BUILD_DOCS OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(ASSIMP_INSTALL OFF)
option(SPDLOG_BUILD_TESTING OFF)
option(YAML_CPP_BUILD_TOOLS OFF)
option(ALSOFT_EXAMPLES OFF)
option(ALSOFT_INSTALL_AMBDEC_PRESETS OFF)
option(ALSOFT_INSTALL_EXAMPLES OFF)
option(ALSOFT_UTILS OFF)

add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/Glad)
add_subdirectory(vendor/assimp)
add_subdirectory(vendor/doctest)
add_subdirectory(vendor/freetype)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/openal-soft)
add_subdirectory(vendor/qu3e)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/yaml-cpp)


# Dependencies
target_include_directories(${PROJECT_NAME}
    PRIVATE vendor/GLFW/include
    PRIVATE vendor/Glad/include
    PRIVATE vendor/ImGui
    PRIVATE vendor/ImGuizmo
    PRIVATE vendor/assimp/include
    PRIVATE vendor/entt/include
    PRIVATE vendor/freetype/include
    PRIVATE vendor/glm
    PRIVATE vendor/qu3e/src
    PRIVATE vendor/spdlog/include
    PRIVATE vendor/stb_image
    PRIVATE vendor/yaml-cpp/include
    PRIVATE vendor/openal-soft/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE vendor/GLFW/src
    PRIVATE vendor/Glad/src
    PRIVATE vendor/ImGui
    PRIVATE vendor/ImGuizmo
    PRIVATE vendor/assimp/lib
    PRIVATE vendor/freetype
    PRIVATE vendor/qu3e/src
    PRIVATE vendor/spdlog
    PRIVATE vendor/stb_image
    PRIVATE vendor/yaml-cpp/src
    PRIVATE vendor/openal-soft
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw
    PRIVATE glad
    PRIVATE assimp
    PRIVATE freetype
    PRIVATE qu3e
    PRIVATE spdlog
    PRIVATE yaml-cpp
    PRIVATE OpenAL::OpenAL
)
