cmake_minimum_required(VERSION 3.16)

project(AalforrecaEngine VERSION 0.1)

configure_file(AalforrecaEngineConfig.h.in AalforrecaEngineConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
unset("QT_QMAKE_EXECUTABLE")


# Sources and includes
set(ALRC_INTERNAL_HEADERS_DIR "${PROJECT_SOURCE_DIR}/include/private")
set(ALRC_HEADERS_DIR "${PROJECT_SOURCE_DIR}/include/public")
set(ALRC_SOURCES_DIR "${PROJECT_SOURCE_DIR}/src")
set(ALRC_VENDOR_DIR "${PROJECT_SOURCE_DIR}/vendor")

include_directories(
    ${ALRC_HEADERS_DIR}
    ${ALRC_INTERNAL_HEADERS_DIR}
    ${PROJECT_BINARY_DIR}
)
set(HEADER_FILES
    "${ALRC_HEADERS_DIR}/Aalforreca/core/main.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/application.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/exit_codes.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/helper_macros.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/pointers.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/log.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/key_codes.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/mouse_codes.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/window.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/path_helper.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/core/image.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/events/event.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/events/application_event.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/events/key_event.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/events/mouse_event.h"
    "${ALRC_HEADERS_DIR}/Aalforreca/events/window_event.h"
)

set(SOURCE_FILES
    "${ALRC_SOURCES_DIR}/core/application.cpp"
    "${ALRC_SOURCES_DIR}/core/log.cpp"
    "${ALRC_SOURCES_DIR}/core/window.cpp"
    "${ALRC_SOURCES_DIR}/core/path_helper.cpp"
    "${ALRC_SOURCES_DIR}/core/image.cpp"
)
set(PCH_SOURCE_FILE "${ALRC_SOURCES_DIR}/alrcpch.cpp")
set(IMGUI_IMPL_DIR "${ALRC_VENDOR_DIR}/ImGui/backends")

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
    target_precompile_headers(${PROJECT_NAME} PRIVATE "${ALRC_INTERNAL_HEADERS_DIR}/Aalforreca/alrcpch.h")
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE ALRC_USE_CORE_LOGGER)
target_compile_definitions(${PROJECT_NAME} PRIVATE "ALRC_DEBUG=$<IF:$<CONFIG:Release>,0,1>")
target_compile_definitions(${PROJECT_NAME} PRIVATE "ALRC_ASSETS_PATH=\"${PROJECT_SOURCE_DIR}/assets\"")


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
if (NOT EXISTS "${ALRC_VENDOR_DIR}/GLFW/CMakeLists.txt")
    message(FATAL_ERROR "GLFW submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/assimp/CMakeLists.txt")
    message(FATAL_ERROR "assimp submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/doctest/CMakeLists.txt")
    message(FATAL_ERROR "doctest submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/freetype/CMakeLists.txt")
    message(FATAL_ERROR "freetype submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/glm/CMakeLists.txt")
    message(FATAL_ERROR "glm submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/openal-soft/CMakeLists.txt")
    message(FATAL_ERROR "openal-soft submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/qu3e/CMakeLists.txt")
    message(FATAL_ERROR "qu3e submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/spdlog/CMakeLists.txt")
    message(FATAL_ERROR "spdlog submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${ALRC_VENDOR_DIR}/yaml-cpp/CMakeLists.txt")
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
    PUBLIC  vendor/spdlog/include
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
