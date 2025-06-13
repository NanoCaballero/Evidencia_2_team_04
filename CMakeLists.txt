cmake_minimum_required(VERSION 3.14)
project(RedOptima)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opción para habilitar cobertura
option(ENABLE_COVERAGE "Enable code coverage" ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Fuente principal (como biblioteca para facilitar testing)
add_library(core
    main.cpp
    graph.h
    kruskal.h
    tsp.h
    ford_fulkerson.h
    search.h
)

# Cobertura si está habilitada
if(ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")
    target_compile_options(core PRIVATE --coverage)
    target_link_libraries(core PRIVATE --coverage)
endif()

# Executable de pruebas
add_executable(test_main
    test/test_main.cpp
)

target_link_libraries(test_main
    core
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_main)
