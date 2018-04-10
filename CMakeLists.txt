cmake_minimum_required(VERSION 2.8.9)

# Compiler settings (this must come before calling project)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project(tnotz)

# Bring the headers, such as Student.h into the project
include_directories(include)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

# Project folder completed
set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/build
)

# Also add resources to the target so they are visible in the IDE
add_executable(tnotz ${SOURCES})
