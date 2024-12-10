cmake_minimum_required(VERSION 3.10)
project(RadioNetworkScheduler)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(radio_scheduler ${SOURCES})

enable_testing()
add_subdirectory(tests)

find_package(Threads REQUIRED)
target_link_libraries(radio_scheduler Threads::Threads)