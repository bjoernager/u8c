/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/SIZE_C.h>
# include <u8c/err.h>
# include <u8c/str.h>
struct u8c_strfndpat_tuple u8c_strfndpat(char32_t const * const restrict _in,char32_t const * const restrict _pat) {
	struct u8c_strfndpat_tuple ret = {
		.stat = false,
	};
	size_t insz  = u8c_strsz(_in).sz;
	size_t patsz = u8c_strsz(_pat).sz;
	if(insz == SIZE_C(0x1) || insz < patsz) {
		ret.pos = SIZE_C(-0x1);
		return ret;
	}
	for(register size_t n = SIZE_C(0x0);n < insz - patsz;n += SIZE_C(0x1)) {
		char32_t const *    str    = u8c_strsubstr(n,patsz - SIZE_C(0x1),_in).str;
		uint_least8_t const cmpres = u8c_strcmp(str,_pat).res;
		u8c_strfree(str);
		if(cmpres == UINT8_C(0x1)) {
			ret.pos = n;
			return ret;
		}
	}
	ret.pos = SIZE_C(-0x1);
	return ret;
}
