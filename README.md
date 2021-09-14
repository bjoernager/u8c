# u8c

[*u8c*](https://mandelbrot.dk/delta/u8c) is a free, open-source and portable general-purpose library. It is written in the C++ *(C++2b)* programming language. A wrapper for C may arrive in the future.

## Features

u8c has the following features:

* Array container with support for compile-time, dynamic, and static arrays.
* Compile-time-compatible alternatives to the C maths library *(incomplete)*.
* Compile-time-compatible alternatives to the C string manipulation facilities *(incomplete)*.
* Facilities for determining the target platform using immediate functions *(Supports major platforms, including AIX, FreeBSD, Linux, macOS, OpenBSD, Windows NT)*.
* Optional platform-specific behaviour, including vendor-specific attributes, pointer-restriction.
* Quota type for fractional mathematics *(incomplete)*.
* String container with built-in UTF-conversions
* Unicode *(UTF-8, UTF-16 and UTF-32)* conversions and manipulations facilities *(UTF-16 lacking full support)*.

With more to come in the future.

## Installing

TBA

## Compiling

u8c has been tested to work with Clang 14.

1. Checkout u8c using `git`:

    * Clone the repository: `git clone https://mandelbrot.dk/delta/u8c.git
    * Or do a shallow cone: `git clone --depth 1 https://mandelbrot.dk/delta/u8c.git`

2. Configure the compilation of u8c:

	* `cd u8c`
	* `cmake -B build`

		You can append the following options to the command:

		* `-DCMAKE_BUILD_TYPE` — Set the build type. Can be either `Debug`or `Release`.
		* `-DU8C_TEST` — Enables compilation of the test program if set to `ON`.

3. Build u8c build

	* `cmake --build build`

## Contributing

u8c does currently not accept **any** merge requests.

## Copyright & License

Copyright 2021 Gabriel Jensen

This file is part of u8c.

u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with u8c. If not, see <https://www.gnu.org/licenses/>.