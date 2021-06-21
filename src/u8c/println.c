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
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <u8c/fmt.h>
# include <u8c/u32.h>
# include <uchar.h>
bool u8c_println(FILE * _fp,char32_t const * const _msg,...) {
	assert(_fp != NULL);
	va_list args;
	va_start(args,_msg);
	char32_t const * msg = NULL;
	u8c_u32cat(NULL,&msg,_msg,U"\n");
	{
		register bool const val = u8c_vprint(_fp,msg,args);
		u8c_u32free(&msg);
		if(val) {
			return true;
		}
	}
	va_end(args);
	return false;
}
