/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or	(at your option) any later version.

	u8c is distributed in the hope that it will be useful,	but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <u8c/dbgprint.h>
# include <u8c/u8dec.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
uint_least8_t u8c_u8dec(uint_least8_t * utf,size_t * codepssz,uint_least32_t * * codeps) {
	size_t insz  = (size_t){0x0};
	size_t outsz = (size_t){0x0};
	for(size_t n = (size_t){0x0};;n += (size_t){0x1}) { // First pass: get size of input array and determine size of output array.
		outsz += (size_t){0x1};
		if(utf[n] == (uint_least8_t){0x0}) { // Null-terminator.
			insz = n;
			break;
		}
		if(utf[n] >= (uint_least8_t){0xF0}) { // Four byte.
			n     += (size_t){0x4};
			continue;
		}
		if(utf[n] >= (uint_least8_t){0xE0}) { // Three bytes.
			n     += (size_t){0x3};
			continue;
		}
		if(utf[n] >= (uint_least8_t){0xC0}) { // Two bytes.
			n     += (size_t){0x2};
			continue;
		}
	}
	if(codepssz != NULL) {
		*codepssz = outsz;
	}
	*codeps                          = malloc(outsz);
	(*codeps)[outsz - (size_t){0x1}] = (uint_least32_t){0x0}; // Create null-terminator on output array.
	for(size_t n = (size_t){0x0}, outn = (size_t){0x0};n < insz;n += (size_t){0x1},outn += (size_t){0x1}) { // Second pass: decode UTF-8.
		uint_least8_t chr = utf[n];
		if(chr >= (uint_least8_t){0xF7}) { // Out of range.
			u8c_dbgprint(U"Out of range (in character decoding: byte too big).");
			return 0x1;
		}
		if(chr >= (uint_least8_t){0xF0}) { // Four byte.
			uint_least32_t codep  =  (uint_least32_t){(chr ^ 0xF0) << 0x12};
			n               += (size_t){0x1};
			chr             =  utf[n];
			codep           += (uint_least32_t){(chr ^ 0x80) << 0xC};
			n               += (size_t){0x1};
			chr             =  utf[n];
			codep           += (uint_least32_t){(chr ^ 0x80) << 0x6};
			n               += (size_t){0x1};
			chr             =  utf[n];
			codep           += (uint_least32_t){(chr ^ 0x80)};
			(*codeps)[outn] =  codep;
			continue;
		}
		if(chr >= (uint_least8_t){0xE0}) { // Three bytes.
			uint_least32_t codep  =  (uint_least32_t){(chr ^ 0xE0) << 0xC};
			n               += (size_t){0x1};
			chr             =  utf[n];
			codep           += (uint_least32_t){(chr ^ 0x80) << 0x6};
			n               += (size_t){0x1};
			chr             =  utf[n];
			codep           += (uint_least32_t){(chr ^ 0x80)};
			n               += (size_t){0x1};
			(*codeps)[outn] =  codep;
			continue;
		}
		if(chr >= (uint_least8_t){0xC0}) { // Two bytes.
			uint_least32_t codep  =  (uint_least32_t){(chr ^ 0xC0) << 0x6};
			n               += (size_t){0x1};
			chr             =  utf[n];
			codep           += (uint_least32_t){(chr ^ 0x80)};
			n               += (size_t){0x1};
			(*codeps)[outn] =  codep;
			continue;
		}
		// One byte.
		uint_least32_t codep  = (uint_least32_t){chr};
		(*codeps)[outn] = codep;
		continue;
	}
	return 0x0;
}
