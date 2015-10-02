# Copyright 2015 Ronald Sadlier - Oak Ridge National Laboratory
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

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

########################################################################
# INSTALL
########################################################################
install(TARGETS rand-barnacle DESTINATION bin)

########################################################################
# UNINSTALL
########################################################################
add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake)
