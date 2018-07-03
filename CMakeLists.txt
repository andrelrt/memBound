project(membound)
cmake_minimum_required(VERSION 2.8)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")

find_package(Boost 1.63.0 REQUIRED COMPONENTS timer chrono system filesystem)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
find_package(BoostSimd REQUIRED)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -mtune=native -Wall -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -mavx2 -Wall -fno-strict-aliasing")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -msse2 -Wall -fno-strict-aliasing")

add_subdirectory(leibniz)
