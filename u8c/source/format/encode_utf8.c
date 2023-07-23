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

size_t u8c_encode_utf8(char* const restrict _buffer, uint_least32_t const* const restrict source, size_t const count) {
	char unsigned* const restrict buffer = (char unsigned*)_buffer;

	ptrdiff_t index_out = 0x0;

	for (ptrdiff_t index_in = 0x0; index_in < (ptrdiff_t)count; ++index_in) {
		uint_least32_t code_point = source[index_in];

		if (code_point > u8c_MAXIMUM_CODE_POINT) { code_point = UINT32_C(0xFFFD); }

		if (u8c_is_surrogate(code_point)) { code_point = UINT32_C(0xFFFD); }

		if (code_point >= 0x10000u) {
			/* Four octets. */

			buffer[index_out + 0x0] = (char unsigned)((code_point >> UINT32_C(0x12))                  | UINT32_C(0xF0));
			buffer[index_out + 0x1] = (char unsigned)((code_point >> UINT32_C(0xC)  & UINT32_C(0x3F)) | UINT32_C(0x80));
			buffer[index_out + 0x2] = (char unsigned)((code_point >> UINT32_C(0x6)  & UINT32_C(0x3F)) | UINT32_C(0x80));
			buffer[index_out + 0x3] = (char unsigned)((code_point                   & UINT32_C(0x3F)) | UINT32_C(0x80));

			index_out += 0x4u;
		} else if (code_point >= 0x800u) {
			/* Three octets. */

			buffer[index_out + 0x0] = (char unsigned)((code_point >> UINT32_C(0xC))                  | UINT32_C(0xE0));
			buffer[index_out + 0x1] = (char unsigned)((code_point >> UINT32_C(0x6) & UINT32_C(0x3F)) | UINT32_C(0x80));
			buffer[index_out + 0x2] = (char unsigned)((code_point                  & UINT32_C(0x3F)) | UINT32_C(0x80));

			index_out += 0x3u;
		} else if (code_point >= 0x80u) {
			/* Two octets. */

			buffer[index_out + 0x0] = (char unsigned)((code_point >> UINT32_C(0x6))                  | UINT32_C(0xC0));
			buffer[index_out + 0x1] = (char unsigned)((code_point                  & UINT32_C(0x3F)) | UINT32_C(0x80));

			index_out += 0x2u;
		} else {
			/* One octet. */

			buffer[index_out] = (char unsigned)code_point;

			++index_out;
		}
	}

	return (size_t)index_out;
}
