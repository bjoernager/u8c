/*
	Copyright 2021, 2023 Gabriel Bjørnager Jensen.

	This file is part of u8c.

    u8c is free software: you can redistribute it
	and/or modify it under the terms of the GNU
	Lesser General Public License as published by
	the Free Software Foundation, either version 3 of
	the License, or (at your option) any later
	version.

    u8c is distributed in the hope that it will be
	useful, but WITHOUT ANY WARRANTY; without even
	the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	Lesser General Public License for more details.

    You should have received a copy of the GNU
	Lesser General Public License along with u8c. If
	not, see <https://www.gnu.org/licenses/>.
*/

#include <u8c/format.h>

#include <stddef.h>
#include <stdint.h>

size_t u8c_decode_utf16_length(uint_least16_t const* const restrict source, size_t const count) {
	size_t length = 0x0u;

	for (ptrdiff_t index = 0x0; index < (ptrdiff_t)count; ++length) {
		uint_least16_t const hextet = source[index];

		if (hextet >= UINT16_C(0xD800) && hextet < UINT16_C(0xDC00)) {
			index += 0x2u;
		} else {
			++index;
		}
	}

	return length;
}
