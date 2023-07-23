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

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_EXTENSIONS OFF)

add_library(
	u8c SHARED

	"source/character/is_alphabetic.c"
	"source/character/is_control.c"
	"source/character/is_hexadecimal_numeric.c"
	"source/character/is_majuscule.c"
	"source/character/is_minuscule.c"
	"source/character/is_numeric.c"
	"source/character/is_punctuation.c"
	"source/character/is_surrogate.c"
	"source/character/is_whitespace.c"
	"source/character/unicode_name.c"

	"source/format/decode_utf16_length.c"
	"source/format/decode_utf16.c"
	"source/format/decode_utf8_length.c"
	"source/format/decode_utf8.c"
	"source/format/encode_utf16_length.c"
	"source/format/encode_utf16.c"
	"source/format/encode_utf8_length.c"
	"source/format/encode_utf8.c"
)

target_include_directories(
	u8c PUBLIC

	"include"
)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang|GNU")
	target_compile_options(
		u8c PRIVATE

		$<IF:$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">,-Og,-Ofast>
		-Wall
		-Wextra
		-Winvalid-utf8
		-Wmissing-declarations
		-Wmissing-include-dirs
		-Wnull-dereference
		-Wpedantic
		-Wpointer-arith
		-Wstrict-overflow=5
		-fdiagnostics-color=always
		-fno-strict-overflow
		$<IF:$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">,-g,>
	)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_compile_options(
		u8c PRIVATE

		/O2
		/W4
		$<IF:$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">,/Zo,>
	)
endif()
