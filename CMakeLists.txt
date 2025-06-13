cmake_minimum_required(VERSION 3.14)
project(RedOptima)

set(CMAKE_CXX_STANDARD 17)

# Coverage flags si está activado
option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if (ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Biblioteca principal (sin main.cpp)
add_library(core
    graph.h
    kruskal.h
    tsp.h
    ford_fulkerson.h
    search.h
)

# Ejecutable main (solo para ejecución funcional, no tests)
add_executable(main_exec main.cpp)
target_link_libraries(main_exec core)

# Tests
add_executable(test_main
    test/test_main.cpp
)

target_link_libraries(test_main
    core
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_main)
