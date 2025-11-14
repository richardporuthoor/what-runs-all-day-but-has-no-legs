cmake_minimum_required(VERSION 3.24)
project(what-runs-all-day-but-has-no-legs)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(main main.cpp src/timer.cpp)

add_executable(timer_test test/timer_test.cpp src/timer.cpp)
target_include_directories(timer_test PRIVATE src)

target_link_libraries(timer_test PRIVATE Catch2::Catch2WithMain)

enable_testing()
add_test(NAME TimerTest COMMAND timer_test)