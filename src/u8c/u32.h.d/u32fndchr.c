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
# include <u8c/u32.h>
bool u8c_u32fndchr(size_t * const _pos,char32_t const * const _in,char32_t const _chr) {
	assert(_pos != NULL);
	assert(_in != NULL);
	for(register size_t n = SIZE_C(0x0);n <= SIZE_MAX;n += SIZE_C(0x1)) {
		register uint_least32_t const tmp = _in[n];
		if(tmp == U'\x0') {
			if(_chr == U'\x0') {
				*_pos = n;
				return false;
			}
			*_pos = SIZE_C(-0x1);
			return true;
		}
		if(tmp == _chr) {
			*_pos = n;
			return false;
		}
	}
	u8c_seterr(U"u8c_u32fndchr: Unterminated input.",u8c_errtyp_badio);
	*_pos = SIZE_C(-0x1);
	return true;
}
