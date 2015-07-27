project(rand-barnacle)

cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Release)

find_package(Boost COMPONENTS system program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set(cc_sources "")
list(APPEND cc_sources
	rand-barnacle.cc)

add_executable(rand-barnacle ${cc_sources})
target_link_libraries(rand-barnacle ${Boost_LIBRARIES})

set_property(TARGET rand-barnacle PROPERTY CXX_STANDARD 11)
set_property(TARGET rand-barnacle PROPERTY CXX_STANDARD_REQUIRED ON)
