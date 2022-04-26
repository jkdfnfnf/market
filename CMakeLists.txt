cmake_minimum_required(VERSION 3.20)
project(class_market)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/headers/*.h)

add_executable(class_market main.cpp ${headers} ${sources} headers/market.h src/market.cpp)
