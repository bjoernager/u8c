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
# include <stdlib.h>
# include <u8c/SIZE_C.h>
# include <u8c/err.h>
# include <u8c/str.h>
struct u8c_strcp_tuple u8c_strcp(char32_t const * const restrict _in) {
	struct u8c_strcp_tuple ret = {
		.stat = false,
	};
	ret.strsz = u8c_strsz(_in).sz;
	uint_least32_t * out = NULL;
	{
		struct u8c_stralloc_tuple const tuple = u8c_stralloc(ret.strsz + SIZE_C(0x1));
		if(tuple.stat) {
			ret.stat = true;
			return ret;
		}
		out = tuple.str;
	}
	for(register size_t n = SIZE_C(0x0);n < ret.strsz;n += SIZE_C(0x1)) {
		out[n] = _in[n];
	}
	ret.str = out;
	return ret;
}
