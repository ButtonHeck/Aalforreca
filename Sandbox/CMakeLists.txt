cmake_minimum_required(VERSION 3.13)

project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES "src/main.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories("../Engine/include")

target_link_libraries(${PROJECT_NAME} AalforrecaEngine)
