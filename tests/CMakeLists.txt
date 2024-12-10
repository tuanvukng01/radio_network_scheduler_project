set(GTEST_ROOT "/usr/local/")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TEST_SOURCES "test_scheduler.cpp")

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} Threads::Threads)
add_test(NAME runTests COMMAND runTests)