cmake_minimum_required(VERSION 3.13)

project(AalforrecaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
unset("QT_QMAKE_EXECUTABLE")

set(SOURCE_FILES "src/Core/application.cpp")
set(HEADER_FILES "include/Aalforreca/Core/application.h")
set(IMGUI_IMPL_DIR "vendor/ImGui/backends")

aux_source_directory(vendor/ImGui IMGUI_SRC)
aux_source_directory(vendor/ImGuizmo IMGUIZMO_SRC)
aux_source_directory(vendor/stb_image STB_IMAGE_SRC)

include_directories(include/Aalforreca)

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES}
    ${IMGUI_SRC}
    ${IMGUIZMO_SRC}
    ${IMGUI_IMPL_DIR}/imgui_impl_opengl3.cpp
    ${IMGUI_IMPL_DIR}/imgui_impl_glfw.cpp
    ${STB_IMAGE_SRC}
)


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
    message(FATAL_ERROR "assimp submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
endif()
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/glm/CMakeLists.txt")
    message(FATAL_ERROR "glm submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Update submodules and try again.")
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

option(GLFW_BUILD_DOCS OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(ASSIMP_INSTALL OFF)
option(SPDLOG_BUILD_TESTING OFF)
option(YAML_CPP_BUILD_TOOLS OFF)

add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/Glad)
add_subdirectory(vendor/assimp)
add_subdirectory(vendor/doctest)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/qu3e)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/yaml-cpp)

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
