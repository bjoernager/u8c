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
# include <u8c/isalnum.h>
# include <u8c/isalpha.h>
# include <u8c/isdigit.h>
bool u8c_isalnum(uint_least8_t * const _res,char32_t const _chr) {
	assert(_res != NULL);
	uint_least8_t res = UINT8_C(0x0);
	u8c_isalpha(&res,_chr);
	if(res) {
		*_res = res;
		return false;
	}
	u8c_isdigit(&res,_chr);
	*_res = res;
	return false;
}
