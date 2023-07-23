#
# Copyright 2021, 2023 Gabriel Bjørnager Jensen.
#
# This file is part of u8c.
#
# u8c is free software: you can redistribute it
# and/or modify it under the terms of the GNU
# Lesser General Public License as published by
# the Free Software Foundation, either version 3 of
# the License, or (at your option) any later
# version.
#
# u8c is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even
# the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU
# Lesser General Public License along with u8c. If
# not, see <https://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.21)

option(U8C_CHECK "build the test program" OFF)

if(U8C_CHECK)
	set(CMAKE_CXX_STANDARD 17)

	set(CMAKE_CXX_EXTENSIONS OFF)

	add_executable(
		check

		"source/check.cc"
	)

	add_dependencies(
		check

		u8c
	)

	target_link_libraries(
		check

		u8c
	)

	if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang|GNU")
		target_compile_options(
			check PRIVATE

			-Og
			-Wall
			-Wextra
			-Wpedantic
			-fdiagnostics-color=always
			-g
		)
	endif()
endif()
