cmake_minimum_required(VERSION 3.16)

project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(
    "${PROJECT_SOURCE_DIR}/../Engine/include"
)

target_link_libraries(${PROJECT_NAME} AalforrecaEngine)
