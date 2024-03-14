cmake_minimum_required(VERSION 3.5)

project(containers)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
    )
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(containers   main.cpp 
                            my_vector.h 
                            my_forward_list.h 
                            my_list.h
                            icontainer.h)
add_executable(containers_tests tests/test_vector.cpp)
set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
# set(CMAKE_DEBUG_POSTFIX d)

target_include_directories(containers_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
# target_include_directories(containers_tests PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(containers_tests PRIVATE gtest gtest_main)

# target_compile_options(containers PUBLIC -g)