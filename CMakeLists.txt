cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(Aethervault VERSION 1.0 LANGUAGES CXX)

# Find the Qt5 modules
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Add the executable target
add_executable(Aethervault src/main.cpp src/window.cpp src/window.h)

# Link against the Qt5 libraries
target_link_libraries(Aethervault PRIVATE Qt5::Core Qt5::Widgets)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set g++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")
