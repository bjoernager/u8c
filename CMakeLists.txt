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

project(
	u8c
	VERSION 29
	DESCRIPTION "Unicode for C."
	HOMEPAGE_URL "https://mandelbrot.dk/u8c"
	LANGUAGES C CXX
)

add_subdirectory(u8c)
add_subdirectory(u8c-check)
