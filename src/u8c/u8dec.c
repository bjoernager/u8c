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
# include <u8c/seterr.h>
# include <u8c/u32alloc.h>
# include <u8c/u32free.h>
# include <u8c/u8dec.h>
# include <uchar.h>
bool u8c_u8dec(size_t * const _sz,char32_t const * * const _out,unsigned char const * const _in) {
	assert(_out != NULL);
	assert(_in != NULL);
	register size_t insz  = SIZE_C(0x0);
	register size_t outsz = SIZE_C(0x1);
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;outsz += SIZE_C(0x1)) { /* First pass: get size of input array and determine size of output array. */
		register unsigned char const tmp = _in[n];
		if(tmp == UINT8_C(0x0)) { /* Null-terminator: end of string has been reached. */
			insz = n;
			goto nottoobig;
		}
		if(tmp >= UINT8_C(0xF8)) { /* Too big. */
			u8c_seterr(U"u8c_u8dec: Character out of range (too big).");
			return true;
		}
		if(tmp >= UINT8_C(0xF0)) { /* Four byte. */
			n += SIZE_C(0x4);
			continue;
		}
		if(tmp >= UINT8_C(0xE0)) { /* Three bytes. */
			n += SIZE_C(0x3);
			continue;
		}
		if(tmp >= UINT8_C(0xC0)) { /* Two bytes. */
			n += SIZE_C(0x2);
			continue;
		}
		/* One byte. */
		n += SIZE_C(0x1);
	}
	/* Input is not null-terminated. */
	u8c_seterr(U"u8c_u8dec: Unterminated input.");
	return true;
nottoobig:;
	if(_sz != NULL) {
		*_sz = outsz;
	}
	uint_least32_t * out = NULL;
	if(u8c_u32alloc(&out,outsz + SIZE_C(0x1))) {
		return false;
	}
	for(register size_t n = SIZE_C(0x0),outn = SIZE_C(0x0);n < insz;outn += SIZE_C(0x1)) { /* Second pass: decode UTF-8. */
		if(_in[n] >= UINT8_C(0xF0)) { /* Four byte. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0xF0)) << UINT32_C(0x12);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0x80)) << UINT32_C(0xC);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0x80)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += (uint_least32_t)(_in[n]) ^ SIZE_C(0x80);
			n                    += SIZE_C(0x1);
			out[outn]        =  codep;
			continue;
		}
		if(_in[n] >= UINT8_C(0xE0)) { /* Three bytes. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0xE0)) << UINT32_C(0xC);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0x80)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += _in[n] ^ UINT32_C(0x80);
			n                    += SIZE_C(0x1);
			out[outn]        =  codep;
			continue;
		}
		if(_in[n] >= UINT8_C(0xC0)) { /* Two bytes. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0xC0)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += _in[n] ^ UINT32_C(0x80);
			n                    += SIZE_C(0x1);
			out[outn] =  codep;
			continue;
		}
		/* One byte. */
		out[outn] =  (uint_least32_t)(_in[n]);
		n             += SIZE_C(0x1);
		continue;
	}
	u8c_u32free(_out);
	*_out = out;
	return false;
}
