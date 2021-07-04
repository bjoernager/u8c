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
struct u8c_strfndchr_tuple u8c_strfndchr(char32_t const * const restrict _in,char32_t const _chr) {
	struct u8c_strfndchr_tuple ret = {
		.stat = false,
	};
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;n += SIZE_C(0x1)) {
		register uint_least32_t const tmp = _in[n];
		if(tmp == U'\x0') {
			if(_chr == U'\x0') {
				ret.pos = n;
				return ret;
			}
			ret.pos = SIZE_C(-0x1);
			return ret;
		}
		if(tmp == _chr) {
			ret.pos = n;
			return ret;
		}
	}
	u8c_seterr(u8c_errtyp_untermin,U"u8c_strfndchr: Unterminated input.");
	ret.pos  = SIZE_C(-0x1);
	ret.stat = true;
	return ret;
}
