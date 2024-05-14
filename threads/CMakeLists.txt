cmake_minimum_required(VERSION 3.5)
project(threads)

add_executable(topk_words src/topk_words.cpp)
set_target_properties(topk_words PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(top_words_thread src/top_words_thread.cpp)
set_target_properties(topk_words PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)