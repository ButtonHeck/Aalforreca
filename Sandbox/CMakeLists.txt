cmake_minimum_required(VERSION 3.16)

project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Sources and includes
include_directories(
    "${PROJECT_SOURCE_DIR}/../Engine/include/public"
)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/src/sandbox.cpp"
)


# Target
add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE AalforrecaEngine
)

target_compile_definitions(${PROJECT_NAME} PRIVATE "ALRC_APP_ASSETS_PATH=\"${PROJECT_SOURCE_DIR}/assets\"")
