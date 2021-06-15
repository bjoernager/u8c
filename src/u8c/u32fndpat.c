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
# include <u8c/u32cmp.h>
# include <u8c/u32fndpat.h>
# include <u8c/u32free.h>
# include <u8c/u32substr.h>
# include <u8c/u32sz.h>
bool u8c_u32fndpat(size_t * const _pos,char32_t const * const _in,char32_t const * const _pat) {
	assert(_pos != NULL);
	assert(_in != NULL);
	size_t insz  = SIZE_C(0x0);
	size_t patsz = SIZE_C(0x0);
	u8c_u32sz(&insz,_in);
	u8c_u32sz(&patsz,_pat);
	if(insz == SIZE_C(0x1) || insz < patsz) {
		*_pos = SIZE_C(-0x1);
		return false;
	}
	for(register size_t n = SIZE_C(0x0);n < insz - patsz;n += SIZE_C(0x1)) {
		char32_t const * str = NULL;
		u8c_u32substr(&str,n,patsz - SIZE_C(0x1),_in);
		uint_least8_t cmpres = UINT8_C(0x0);
		u8c_u32cmp(&cmpres,str,_pat);
		u8c_u32free(&str);
		if(cmpres == UINT8_C(0x1)) {
			*_pos = n;
			return false;
		}
	}
	*_pos = SIZE_C(-0x1);
	return false;
}
