/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include "seterr.h"
# include <assert.h>
# include <stdint.h>
# include <stdlib.h>
# include <u8c/dbgprint.h>
# include <u8c/u8dec.h>
# include <u8c/SIZE_C.h>
uint_least8_t u8c_u8dec(size_t * _outsz,uint_least32_t * * _out,uint_least8_t * _in) {
	assert(_in != NULL);
	size_t insz  = SIZE_C(0x0);
	size_t outsz = SIZE_C(0x0);
	for(size_t n = SIZE_C(0x0);n <= SIZE_MAX;n += SIZE_C(0x1)) { /* First pass: get size of input array and determine size of output array. */
		outsz += SIZE_C(0x1);
		if(_in[n] == UINT8_C(0x0)) { /* Null-terminator: end of string has been reached. */
			insz = n;
			goto nottoobig;
		}
		if(_in[n] >= UINT8_C(0xF8)) { /* Too big. */
			u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x64),UINT32_C(0x65),UINT32_C(0x63),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x43),UINT32_C(0x68),UINT32_C(0x61),UINT32_C(0x72),UINT32_C(0x61),UINT32_C(0x63),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x20),UINT32_C(0x6F),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x20),UINT32_C(0x6F),UINT32_C(0x66),UINT32_C(0x20),UINT32_C(0x72),UINT32_C(0x61),UINT32_C(0x6E),UINT32_C(0x67),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0x28),UINT32_C(0x74),UINT32_C(0x6F),UINT32_C(0x6F),UINT32_C(0x20),UINT32_C(0x62),UINT32_C(0x69),UINT32_C(0x67),UINT32_C(0x29),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_u8dec: Character out of range (too big). */
			return UINT8_C(0x1);
		}
		if(_in[n] >= UINT8_C(0xF0)) { /* Four byte. */
			n     += SIZE_C(0x4);
			continue;
		}
		if(_in[n] >= UINT8_C(0xE0)) { /* Three bytes. */
			n     += SIZE_C(0x3);
			continue;
		}
		if(_in[n] >= UINT8_C(0xC0)) { /* Two bytes. */
			n     += SIZE_C(0x2);
			continue;
		}
		/* One byte. */
		n += SIZE_C(0x1);
	}
	u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x64),UINT32_C(0x65),UINT32_C(0x63),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x55),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x6D),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x61),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x64),UINT32_C(0x20),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x70),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_u8dec: Unterminated input. */
	return UINT8_C(0x1);
nottoobig:;
	if(_outsz != NULL) {
		*_outsz = outsz;
	}
	*_out                        = calloc(sizeof(uint_least8_t),outsz);
	(*_out)[outsz - SIZE_C(0x1)] = (uint_least32_t){0x0}; /* Create null-terminator on output array. */
	for(size_t n = SIZE_C(0x0), outn = SIZE_C(0x0);n < insz;n += SIZE_C(0x1),outn += SIZE_C(0x1)) { /* Second pass: decode UTF-8. */
		if(_in[n] >= UINT8_C(0xF0)) { /* Four byte. */
			uint_least32_t codep =  (_in[n] ^ UINT32_C(0xF0)) << UINT32_C(0x12);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0x80)) << UINT32_C(0xC);
			n                    += SIZE_C(0x1);
			codep                += (_in[n] ^ UINT32_C(0x80)) << UINT32_C(0x6);
			n                    += SIZE_C(0x1);
			codep                += (uint_least32_t)(_in[n]) ^ SIZE_C(0x80);
			(*_out)[outn]        =  codep;
			continue;
		}
		if(_in[n] >= UINT8_C(0xE0)) { /* Three bytes. */
			uint_least32_t codep  =  (_in[n] ^ UINT32_C(0xE0)) << UINT32_C(0xC);
			n               += SIZE_C(0x1);
			codep           += (_in[n] ^ UINT32_C(0x80)) << UINT32_C(0x6);
			n               += SIZE_C(0x1);
			codep           += _in[n] ^ UINT32_C(0x80);
			n               += SIZE_C(0x1);
			(*_out)[outn] =  codep;
			continue;
		}
		if(_in[n] >= UINT8_C(0xC0)) { /* Two bytes. */
			uint_least32_t codep  =  (_in[n] ^ UINT32_C(0xC0)) << UINT32_C(0x6);
			n               += SIZE_C(0x1);
			codep           += _in[n] ^ UINT32_C(0x80);
			n               += SIZE_C(0x1);
			(*_out)[outn] =  codep;
			continue;
		}
		/* One byte. */
		(*_out)[outn] = (uint_least32_t)(_in[n]);
		continue;
	}
	return UINT8_C(0x0);
}
