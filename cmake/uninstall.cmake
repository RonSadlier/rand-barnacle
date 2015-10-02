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

set(installFile "/usr/local/bin/rand-barnacle")

if(EXISTS ${installFile})
	message(STATUS "Removing file: '${installFile}'")
	execute_process(COMMAND ${CMAKE_COMMAND} -E remove ${installFile}
			OUTPUT_VARIABLE rm_out
			RESULT_VARIABLE rm_retval)
	if(NOT ${rm_retval} STREQUAL 0)
		message(FATAL_ERROR "Failed to remove file: '${installFile}'. Do you have permission?")
	endif()
else()
	message(STATUS "File '${installFile}' does not exist.")
endif()
