file(GLOB SOURCES
    src/*.cpp
)

cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(Aethervault VERSION 0.2.0 LANGUAGES CXX)

# Find the Qt6 modules
find_package(Qt6 REQUIRED COMPONENTS Core Widgets SvgWidgets Sql)

# Add the executable target
add_executable(Aethervault ${SOURCES})

# Link against the Qt6 libraries
target_link_libraries(Aethervault PRIVATE Qt6::Core Qt6::Widgets Qt6::SvgWidgets Qt6::Sql)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

set(CMAKE_CXX_COMPILER "g++")
