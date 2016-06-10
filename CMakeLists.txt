cmake_minimum_required(VERSION 3.5)
project(S_Night)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES src/ReadBmp.c include/types.h src/encrypt.c include/encrypt.h include/ReadBmp.h src/decode.c include/decode.h src/main.c)
add_executable(S_Night ${SOURCE_FILES})