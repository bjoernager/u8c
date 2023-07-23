U8C

Unicode for C.

- ABOUT

u8c is a C library for various Unicode-related functions. It is written in the
1999 edition of C - C99 - with support for C++11.

- FEATURES

u8c supports conversions to and from the UTF-8 and UTF-16 formats. UTF-32 is
used as the intermediate format.

The encoding and decoding functions automatically replace invalid code
sequences with the replacement character: U+FFFD REPLACEMENT CHARACTER.

Additionally, character trait functions can help determin the type of code
point: Alphabetic, control, numeric, punctuation, etc.

- INSTALLATION

A PKGBUILD is hosted on mandelbrot.dk at:
<https://mandelbrot.dk/pkgbuild_u8c>

- COMPILATION

u8c uses CMake as its build system. The flag 'U8C_CHECK' may be set to ON to
enable building of the check program.

- COPYRIGHT & LICENSE

Copyright 2021, 2023 Gabriel Bjørnager Jensen.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option) any
later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>.
