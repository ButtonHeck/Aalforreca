cmake_minimum_required(VERSION 3.13)

project(AalforrecaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES "src/Core/application.cpp")
set(HEADER_FILES "include/Aalforreca/Core/application.h")

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

include_directories(include/Aalforreca)
