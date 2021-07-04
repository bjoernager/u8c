# u8c

[*u8c*](https://mandelbrot.dk/delta/u8c) is a free, open-source and (very) portable library for Unicode manipulation.

*u8c* is very portable, and should work (with a trivial build system) on **any** hosted conforming C23 implementation, be it one with 64 bits a byte, 4096 byte shorts, with or without multithreading. In the event it doesn't for you, I really want you to open an issue on GitLab (<https://mandelbrot.dk>).

## Compiling

*u8c* can be compiled via the provided *Makefile* using the command `make`.

By default, GCC-11 is used to build *u8c*. Clang-12 doesn't support C23 to the same extend, and may therefore require some modifications.

Currently, the following C23 features are required:

* Attributes.
* Binary literals.

Yet even with only these two seemingly trivial features, the newest version of Clang (Clang-12 at this time) is unable to compile the library without the `-Wno-gnu-binary-literal`.

To enable debug mode, the option `debug=1` must be passed to Make.

To enable thread-safe operations (where logical), the option `thrdsafe=1` must be passed to Make.

## Installing

*u8c* can be installed, either via the `install` target in the provided Makefile, or using the PKGBUILD found [here](https://mandelbrot.dk/pkgbuild/delta/u8c).

If it's installed so, one must make a note of the output, as it logs what system files have changed.

Using the PKGBUILD is as simple as `git clone https://mandelbrot.dk/pkg/u8c.git && cd u8c && makepkg --clean --install --syncdeps` (on Arch-based distributions).

## Copyright & License

Copyright 2021 Gabriel Jensen.

All rights reserved.

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.

If not, see <https://www.gnu.org/licenses/>.
