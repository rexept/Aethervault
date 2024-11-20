cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(Aethervault VERSION 1.0 LANGUAGES CXX)

# Find the Qt5Widgets module
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Add the executable target
add_executable(Aethervault src/main.cpp)

# Link against the Qt5Widgets library
target_link_libraries(Aethervault Qt5::Widgets)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set g++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")
