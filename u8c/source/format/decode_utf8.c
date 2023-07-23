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

size_t u8c_decode_utf8(uint_least32_t* const restrict buffer, char const* const restrict _source, size_t const count) {
	char unsigned const* const restrict source = (char unsigned const*)_source;

	ptrdiff_t index_out = 0x0;

	for (ptrdiff_t index_in = 0x0; index_in < (ptrdiff_t)count; ++index_out) {
		size_t const remaining = count - 0x1u - index_in;

		uint_least32_t const octet = (uint_least32_t)source[index_in];

		uint_least32_t code_point = UINT32_C(0x0);

		if ((octet & UINT32_C(0xF8)) == UINT32_C(0xF0)) {
			if (remaining < 0x3u) {
				code_point = UINT32_C(0xFFFD);
			} else {
				uint_least32_t const octet1 = (uint_least32_t)source[index_in + 0x1];
				uint_least32_t const octet2 = (uint_least32_t)source[index_in + 0x2];
				uint_least32_t const octet3 = (uint_least32_t)source[index_in + 0x3];

				if (
					   (octet1 & 0xC0) != 0x80
					|| (octet2 & 0xC0) != 0x80
					|| (octet3 & 0xC0) != 0x80
				) {
					code_point = UINT32_C(0xFFFD);
				} else {
					code_point |= (octet  ^ UINT32_C(0xF0)) << UINT32_C(0x12);
					code_point |= (octet1 ^ UINT32_C(0x80)) << UINT32_C(0xC);
					code_point |= (octet2 ^ UINT32_C(0x80)) << UINT32_C(0x6);
					code_point |=  octet3 ^ UINT32_C(0x80);
				}
			}

			index_in += 0x4;
		} else if ((octet & UINT32_C(0xF0)) == UINT32_C(0xE0)) {
			if (remaining < 0x2u) {
				code_point = UINT32_C(0xFFFD);
			} else {
				uint_least32_t const octet1 = (uint_least32_t)source[index_in + 0x1];
				uint_least32_t const octet2 = (uint_least32_t)source[index_in + 0x2];

				if (
					   (octet1 & 0xC0) != 0x80
					|| (octet2 & 0xC0) != 0x80
				) {
					code_point = UINT32_C(0xFFFD);
				} else {
					code_point |= (octet  ^ UINT32_C(0xE0)) << UINT32_C(0xC);
					code_point |= (octet1 ^ UINT32_C(0x80)) << UINT32_C(0x6);
					code_point |=  octet2 ^ UINT32_C(0x80);
				}
			}

			index_in += 0x3;
		} else if ((octet & UINT32_C(0xE0)) == 0xC0) {
			if (remaining < 0x1u) {
				code_point = UINT32_C(0xFFFD);
			} else {
				uint_least32_t const octet1 = (uint_least32_t)source[index_in + 0x1];

				if ((octet1 & 0xC0) != 0x80) {
					code_point = UINT32_C(0xFFFD);
				} else {
					code_point |= (octet  ^ UINT32_C(0xC0)) << UINT32_C(0x6);
					code_point |=  octet1 ^ UINT32_C(0x80);
				}
			}

			index_in += 0x2;
		} else if ((octet & UINT32_C(0x80)) == UINT32_C(0x0)) {
			code_point |= octet;

			++index_in;
		} else {
			code_point = UINT32_C(0xFFFD);

			++index_in;
		}

		if (code_point > u8c_MAXIMUM_CODE_POINT) { code_point = UINT32_C(0xFFFD); }

		if (u8c_is_surrogate(code_point)) { code_point = UINT32_C(0xFFFD); }

		buffer[index_out] = code_point;
	}

	return (size_t)index_out;
}
