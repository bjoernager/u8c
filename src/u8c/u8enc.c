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
# include <stdint.h>
# include <stdlib.h>
# include <u8c/seterr.h>
# include <u8c/u8enc.h>
# include <u8c/SIZE_C.h>
uint_least8_t u8c_u8enc(size_t * const _sz,uint_least8_t const * * const _out,uint_least32_t const * const _in) {
	assert(_in != NULL);
	size_t insz  = SIZE_C(0x0); /* Size of input array (bytes). */
	size_t outsz = SIZE_C(0x0); /* Size of output array /bytes). */
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;n += SIZE_C(0x1)) { /* First pass: get size of input array, and determine size of output array. */
		register uint_least32_t const tmp = _in[n];
		if(tmp >= UINT32_C(0x110000)) { /* Codepoint out of range. */
			u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x65),UINT32_C(0x6E),UINT32_C(0x63),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x43),UINT32_C(0x6F),UINT32_C(0x64),UINT32_C(0x65),UINT32_C(0x70),UINT32_C(0x6F),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x20),UINT32_C(0x6F),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x20),UINT32_C(0x6F),UINT32_C(0x66),UINT32_C(0x20),UINT32_C(0x72),UINT32_C(0x61),UINT32_C(0x6E),UINT32_C(0x67),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0x28),UINT32_C(0x74),UINT32_C(0x6F),UINT32_C(0x6F),UINT32_C(0x20),UINT32_C(0x62),UINT32_C(0x69),UINT32_C(0x67),UINT32_C(0x29),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_u8enc: Codepoint out of range (too big). */
			return UINT8_C(0x1);
		}
		if(tmp >= UINT32_C(0x10000)) { /* 4 bytes. */
			outsz += SIZE_C(0x4);
			continue;
		}
		if(tmp >= UINT32_C(0x800)) { /* 3 bytes. */
			outsz += SIZE_C(0x3);
			continue;
		}
		if(tmp >= UINT32_C(0x80)) { /* 2 bytes. */
			outsz += SIZE_C(0x2);
			continue;
		}
		/* 1 byte. */
		outsz += SIZE_C(0x1);
		if(tmp == UINT32_C(0x0)) {
			insz = n + SIZE_C(0x1);
			goto nottoobig;
		}
	}
	u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x65),UINT32_C(0x6E),UINT32_C(0x63),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x55),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x6D),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x61),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x64),UINT32_C(0x20),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x70),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_u8enc: Unterminated input. */
	return UINT8_C(0x1);
nottoobig:;
	if(_sz != NULL) {
		*_sz = outsz;
	}
	uint_least8_t * out = calloc(sizeof(uint_least8_t),outsz); /* Allocate space for output array. */
	for(register size_t n = SIZE_C(0x0), outn = SIZE_C(0x0);n < insz;n += SIZE_C(0x1),outn += SIZE_C(0x1)) { /* Second pass: encode each codepoint into UTF-8. */
		register uint_least32_t const tmp = _in[n];
		if(tmp >= UINT32_C(0x10000)) { // Four bytes.
			out[outn] =  UINT8_C(0xF0) + (uint_least8_t)(tmp >> UINT32_C(0x12));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp >> UINT32_C(0xC) & UINT8_C(0x3F));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp >> UINT32_C(0x6) & UINT8_C(0x3F));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp & UINT32_C(0x3F));
			continue;
		}
		if(tmp >= UINT32_C(0x800)) { /* Three bytes. */
			out[outn] =  UINT8_C(0xE0) + (uint_least8_t)(tmp >> UINT32_C(0xC));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp >> UINT32_C(0x6) & UINT8_C(0x3F));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp & UINT32_C(0x3F));
			continue;
		}
		if(tmp >= UINT32_C(0x80)) { /* Two bytes. */
			out[outn] =  UINT8_C(0xC0) + (uint_least8_t)(tmp >> UINT8_C(0x6));
			outn          += SIZE_C(0x1);
			out[outn] =  UINT8_C(0x80) + (uint_least8_t)(tmp & UINT8_C(0x3F));
			continue;
		}
		/* One byte. */
		out[outn] = (uint_least8_t)tmp;
	}
	*_out = out;
	return UINT8_C(0x0);
}
