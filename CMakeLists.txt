cmake_minimum_required(VERSION 3.10)
project(InternetServices)

set(CMAKE_CXX_STANDARD 17)

# Directorios de include
include_directories(include)

# Archivos fuente
add_executable(main
    src/graph.cpp
    src/kruskal.cpp
    src/tsp.cpp
    src/ford_fulkerson.cpp
    src/search.cpp
    src/main.cpp
)

# ====== TESTS ======

# GoogleTest
enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# Evita la instalación de gtest
set(INSTALL_GTEST OFF)
set(BUILD_GMOCK OFF)
set(BUILD_GTEST ON)

FetchContent_MakeAvailable(googletest)

add_executable(run_tests
    test/test_main.cpp
    src/graph.cpp
    src/kruskal.cpp
    src/tsp.cpp
    src/ford_fulkerson.cpp
    src/search.cpp
)

target_include_directories(run_tests PRIVATE include)
target_link_libraries(run_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)
