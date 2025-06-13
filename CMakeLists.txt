cmake_minimum_required(VERSION 3.14)
project(RedOptima)

set(CMAKE_CXX_STANDARD 17)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Archivos fuente
add_library(core
    main.cpp
    graph.h
    kruskal.h
    tsp.h
    ford_fulkerson.h
    search.h
)

# Test executable
add_executable(test_main
    test/test_main.cpp
)

target_link_libraries(test_main
    core
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_main)
