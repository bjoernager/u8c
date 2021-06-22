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
# include <stdlib.h>
# include <u8c/SIZE_C.h>
# include <u8c/u32.h>
# include <uchar.h>
bool u8c_u32substr(char32_t const * * const _out,size_t const _start,size_t const _len,char32_t const * const _in) {
	assert(_out != NULL);
	assert(_in != NULL);
	u8c_u32free(_out);
	size_t insz = SIZE_C(0x0);
	u8c_u32sz(&insz,_in);
	size_t len = _len;
	if(_len == SIZE_C(0x0)) {
		len = insz - _start;
	}
	if(insz < _start + len) {
		return true;
	}
	size_t const outsz = len + SIZE_C(0x2);
	char32_t *   out   = NULL;
	if(u8c_u32alloc(&out,outsz)) {
		return true;
	}
	for(register size_t n = SIZE_C(0x0);n <= len;n += SIZE_C(0x1)) {
		out[n] = _in[n + _start];
	}
	*_out = out;
	return false;
}
