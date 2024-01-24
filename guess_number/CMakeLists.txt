cmake_minimum_required(VERSION 3.5)

project(guess_number)

add_executable(${PROJECT_NAME}
    guess_number.cpp
    argument.cpp argument.h
    high_scores.cpp high_scores.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)