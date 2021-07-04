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
# include <u8c/SIZE_C.h>
# include <u8c/str.h>
# include <uchar.h>
struct u8c_strins_tuple u8c_strins(size_t const _pos,char32_t const * const restrict _str0,char32_t const * const restrict _str1) {
	struct u8c_strins_tuple ret = {
		.stat = false,
	};
	char32_t const * lstr = u8c_strsubstr(SIZE_C(0x0),_pos - SIZE_C(0x1),_str0).str;
	char32_t const * rstr = u8c_strsubstr(_pos,SIZE_C(0x0),_str0).str;
	                 ret.strsz = SIZE_C(0x0);
	char32_t const * out       = NULL;
	{
		char32_t const * tmp = u8c_strcat(lstr,_str1).str;
		u8c_strfree(lstr);
		out = u8c_strcat(tmp,rstr).str;
		u8c_strfree(rstr);
		u8c_strfree(tmp);
	}
	ret.str = out;
	return ret;
}
