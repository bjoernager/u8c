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
# include <u8c/str.h>
# include <u8c/u8.h>
# include <uchar.h>
struct u8c_u8dec_tuple u8c_u8dec(unsigned char const * const restrict _in) {
	struct u8c_u8dec_tuple ret = {
		.stat = false,
	};
	register size_t insz = SIZE_C(0x0);
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;ret.strsz += SIZE_C(0x1)) { /* First pass: get size of input array and determine size of output array. */
		register unsigned char const tmp = _in[n];
		if(tmp == UINT8_C(0x0)) { /* Null-terminator: end of string has been reached. */
			insz = n;
			goto nottoobig;
		}
		if(tmp >= UINT8_C(0b11111000)) { /* Too big. */
			u8c_seterr(u8c_errtyp_u8oor,U"u8c_u8dec: Character out of range (too big).");
			ret.stat = true;
			return ret;
		}
		if(tmp >= UINT8_C(0b11110000)) { /* Four byte. */
			n += SIZE_C(0x4);
			continue;
		}
		if(tmp >= UINT8_C(0b11100000)) { /* Three bytes. */
			n += SIZE_C(0x3);
			continue;
		}
		if(tmp >= UINT8_C(0b11000000)) { /* Two bytes. */
			n += SIZE_C(0x2);
			continue;
		}
		/* One byte. */
		n += SIZE_C(0x1);
	}
	/* Input is not null-terminated. */
	u8c_seterr(u8c_errtyp_untermin,U"u8c_u8dec: Unterminated input.");
	ret.stat = true;
	return ret;
nottoobig:;
	uint_least32_t * out = NULL;
	{
		struct u8c_stralloc_tuple const tuple = u8c_stralloc(ret.strsz + SIZE_C(0x1));
		if(tuple.stat) {
			ret.stat = true;
			return ret;
		}
		out = tuple.str;
	}
	for(register size_t n = SIZE_C(0x0),outn = SIZE_C(0x0);n < insz;outn += SIZE_C(0x1)) { /* Second pass: decode UTF-8. */
		if(_in[n] >= UINT8_C(0b11110000)) { /* Four bytes. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0b11110000)) << UINT32_C(0x12);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0b10000000)) << UINT32_C(0xC);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0b10000000)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += (uint_least32_t)(_in[n]) ^ SIZE_C(0b10000000);
			n                    += SIZE_C(0x1);
			out[outn]        =  codep;
			continue;
		}
		if(_in[n] >= UINT8_C(0b11100000)) { /* Three bytes. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0b11100000)) << UINT32_C(0xC);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0b10000000)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += _in[n] ^ UINT32_C(0b10000000);
			n                    += SIZE_C(0x1);
			out[outn]        =  codep;
			continue;
		}
		if(_in[n] >= UINT8_C(0b11000000)) { /* Two bytes. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0b11000000)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += _in[n] ^ UINT32_C(0b10000000);
			n                    += SIZE_C(0x1);
			out[outn] =  codep;
			continue;
		}
		/* One byte. */
		out[outn] =  (uint_least32_t)(_in[n]);
		n         += SIZE_C(0x1);
		continue;
	}
	ret.str = out;
	return ret;
}
