/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <u8c/fmt.h>
# include <u8c/str.h>
# include <uchar.h>
struct u8c_println_tuple u8c_println(FILE * restrict _fp,char32_t const * const restrict _msg,...) {
	struct u8c_println_tuple ret;
	va_list args;
	va_start(args,_msg);
	char32_t const * msg                         = u8c_strcat(_msg,U"\n").str;
	register struct u8c_vprint_tuple const tuple = u8c_vprint(_fp,msg,args);
	u8c_strfree(msg);
	va_end(args);
	ret.stat = tuple.stat;
	return ret;
}
