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
# include <u8c/SIZE_C.h>
# include <u8c/u32alloc.h>
# include <u8c/u32cat.h>
# include <u8c/u32free.h>
# include <u8c/u32ins.h>
# include <u8c/u32substr.h>
# include <uchar.h>
bool u8c_u32ins(size_t * const _sz,char32_t const * * const _out,size_t const _pos,char32_t const * const _str0,char32_t const * const _str1) {
	assert(_out != NULL);
	assert(_str0 != NULL);
	assert(_str1 != NULL);
	char32_t const * lstr = NULL;
	char32_t const * rstr = NULL;
	u8c_u32substr(&lstr,SIZE_C(0x0),_pos - SIZE_C(0x1),_str0);
	u8c_u32substr(&rstr,_pos,SIZE_C(0x0),_str0);
	size_t           sz  = SIZE_C(0x0);
	char32_t const * out = NULL;
	{
		char32_t const * tmp = NULL;
		u8c_u32cat(NULL,&tmp,lstr,_str1);
		u8c_u32free(&lstr);
		u8c_u32cat(NULL,&out,tmp,rstr);
		u8c_u32free(&rstr);
		u8c_u32free(&tmp);
	}
	if(_sz != NULL) {
		*_sz = sz;
	}
	*_out = out;
	return false;
}
