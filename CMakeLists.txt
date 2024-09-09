cmake_minimum_required(VERSION 3.10)
project(AvionicsSystem)

set(CMAKE_CXX_STANDARD 17)

# Find packages
find_package(CURL REQUIRED)
find_package(GTest REQUIRED)
find_package(bsoncxx REQUIRED)
find_package(mongocxx REQUIRED)
find_package(nlohmann_json REQUIRED)

# Add executable with all necessary source files
add_executable(AvionicsSystem
  AvionicsSystem.cpp
  FlightControl.cpp
  SensorSim.cpp
  GPSsim.cpp
  WeatherSim.cpp
  UserInterface.cpp
)

# Link libraries
target_link_libraries(AvionicsSystem
  PRIVATE
  CURL::libcurl
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main
  bsoncxx
  mongocxx
  nlohmann_json::nlohmann_json
)

# Add tests
enable_testing()
add_test(AllTestsInAvionicsSystem AvionicsSystem)
