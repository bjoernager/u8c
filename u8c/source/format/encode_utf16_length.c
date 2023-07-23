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

#include <u8c/character.h>
#include <u8c/format.h>

#include <stddef.h>
#include <stdint.h>

size_t u8c_encode_utf16_length(uint_least32_t const* const restrict source, size_t const count) {
	size_t length = 0x0u;

	for (ptrdiff_t index = 0x0; index < (ptrdiff_t)count; ++index) {
		uint_least32_t code_point = source[index];

		if (code_point > u8c_MAXIMUM_CODE_POINT) { code_point = UINT32_C(0xFFFD); }

		if (u8c_is_surrogate(code_point)) { code_point = UINT32_C(0xFFFD); }

		if (code_point >= UINT32_C(0x10000)) {
			length += 0x2u;
		} else {
			++length;
		}
	}

	return length;
}
