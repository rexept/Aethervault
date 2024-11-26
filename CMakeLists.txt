file(GLOB SOURCES
    src/*.cpp
)

cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(Aethervault VERSION 1.0 LANGUAGES CXX)

# Find the Qt5 modules
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Svg Sql)

find_library(BCRYPT_LIBRARY NAMES bcrypt)

# Add the executable target
add_executable(Aethervault ${SOURCES})

# Link against the Qt5 libraries
target_link_libraries(Aethervault PRIVATE ${BCRYPT_LIBRARY} Qt5::Core Qt5::Widgets Qt5::Svg Qt5::Sql)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set clangd++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")
