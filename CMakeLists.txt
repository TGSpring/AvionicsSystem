cmake_minimum_required(VERSION 3.10)
project(AvionicsSystem)

# Set CMake toolchain file
set(CMAKE_TOOLCHAIN_FILE "C:/Users/tyler/source/repos/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Add your project source files
add_executable(AvionicsSystem main.cpp)

# Link libraries
find_package(CURL REQUIRED)
target_link_libraries(AvionicsSystem PRIVATE CURL::libcurl)

find_package(nlohmann_json REQUIRED)
target_link_libraries(AvionicsSystem PRIVATE nlohmann_json::nlohmann_json)
