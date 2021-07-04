/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <assert.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/SIZE_C.h>
# include <u8c/err.h>
# include <u8c/main.h>
# include <u8c/str.h>
# include <u8c/u8.h>
# include <uchar.h>
struct u8c_u8enc_tuple u8c_u8enc(char32_t const * const restrict _in) {
	struct u8c_u8enc_tuple ret = {
		.stat = false,
	};
	size_t insz = SIZE_C(0x0); /* Size of input array (bytes). */
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;n += SIZE_C(0x1)) { /* First pass: get size of input array, and determine size of output array. */
		register char32_t const tmp = _in[n];
		if(tmp > u8c_unimax) { /* Codepoint out of range. */
			u8c_seterr(u8c_errtyp_stroor,U"u8c_u8enc: Codepoint out of range (too big).");
			ret.stat = true;
			return ret;
		}
		if(tmp >= UINT32_C(0x10000)) { /* 4 bytes. */
			ret.u8sz += SIZE_C(0x4);
			continue;
		}
		if(tmp >= UINT32_C(0x800)) { /* 3 bytes. */
			ret.u8sz += SIZE_C(0x3);
			continue;
		}
		if(tmp >= UINT32_C(0x80)) { /* 2 bytes. */
			ret.u8sz += SIZE_C(0x2);
			continue;
		}
		/* 1 byte. */
		ret.u8sz += SIZE_C(0x1);
		if(tmp == UINT32_C(0x0)) {
			insz = n + SIZE_C(0x1);
			goto nottoobig;
		}
	}
	u8c_seterr(u8c_errtyp_untermin,U"u8c_u8enc: Unterminated input.");
	ret.stat = true;
	return ret;
nottoobig:;
	unsigned char * out = NULL;
	{
		struct u8c_u8alloc_tuple const tuple = u8c_u8alloc(ret.u8sz + SIZE_C(0x1));
		if(tuple.stat) {
			ret.stat = true;
			return ret;
		}
		out = tuple.u8;
	}
	for(register size_t n = SIZE_C(0x0), outn = SIZE_C(0x0);n < insz;n += SIZE_C(0x1),outn += SIZE_C(0x1)) { /* Second pass: encode each codepoint into UTF-8. */
		register char32_t const tmp = _in[n];
		if(tmp >= UINT32_C(0x10000)) { // Four bytes.
			out[outn] =  UINT8_C(0b11110000) + (uint_least8_t)(tmp >> UINT32_C(0x12));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0b10000000) + (uint_least8_t)(tmp >> UINT32_C(0xC) & UINT8_C(0b00111111));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0b10000000) + (uint_least8_t)(tmp >> UINT32_C(0x6) & UINT8_C(0b00111111));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0b10000000) + (uint_least8_t)(tmp & UINT32_C(0b00111111));
			continue;
		}
		if(tmp >= UINT32_C(0x800)) { /* Three bytes. */
			out[outn] =  UINT8_C(0xE0) + (uint_least8_t)(tmp >> UINT32_C(0xC));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp >> UINT32_C(0x6) & UINT8_C(0b00111111));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp & UINT32_C(0b00111111));
			continue;
		}
		if(tmp >= UINT32_C(0x80)) { /* Two bytes. */
			out[outn] =  UINT8_C(0xC0) + (uint_least8_t)(tmp >> UINT8_C(0x6));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp & UINT8_C(0b00111111));
			continue;
		}
		/* One byte. */
		out[outn] = (uint_least8_t)tmp;
	}
	ret.u8 = out;
	return ret;
}
