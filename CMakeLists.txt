cmake_minimum_required(VERSION 3.16)

project(ActividadIntegradora2 VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opciones para testing y coverage
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Flags de coverage
if (ENABLE_COVERAGE)
    message(STATUS "Coverage flags enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Incluir los headers locales
include_directories(${CMAKE_SOURCE_DIR})

# Archivos fuente
set(SOURCES
    main.cpp
    ford_fulkerson.cpp
    graph.cpp
    kruskal.cpp
    search.cpp
    tsp.cpp
)

# Ejecutable principal
add_executable(main ${SOURCES})

# ------------------------
# Testing con GoogleTest
# ------------------------
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

if (ENABLE_TESTING)
    enable_testing()

    add_executable(test_main
    test/test_main.cpp
    ford_fulkerson.cpp
    graph.cpp
    kruskal.cpp
    search.cpp
    tsp.cpp
)
target_link_libraries(test_main PRIVATE gtest gtest_main)

if (ENABLE_COVERAGE)
    target_link_libraries(test_main PRIVATE gcov)
    target_compile_options(test_main PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_options(test_main PRIVATE --coverage)
endif()


    if (ENABLE_COVERAGE)
        target_link_libraries(test_main PRIVATE gcov)
        target_compile_options(test_main PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(test_main PRIVATE --coverage)
    endif()

    add_test(NAME test_main COMMAND test_main)

    find_program(LCOV lcov)
    if (LCOV)
        add_custom_target(coverage
            COMMAND lcov --capture --directory . --output-file build/coverage.info
            COMMAND genhtml build/coverage.info --output-directory build/coverage_html
            COMMENT "Generating coverage report"
            VERBATIM
        )
    else()
        message(WARNING "LCOV not found, skipping coverage target")
    endif()
endif()
