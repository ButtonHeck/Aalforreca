cmake_minimum_required(VERSION 3.16)

project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Sources and includes
include_directories(
    "${PROJECT_SOURCE_DIR}/../Engine/include"
)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)


# Target
add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
)


# Dependencies
target_link_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_BINARY_DIR}/Engine/vendor/openal-soft"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE AalforrecaEngine
    PRIVATE OpenAL::OpenAL
)
