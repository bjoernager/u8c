/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <u8c/fmt.h>
# include <u8c/fmttyp.h>
# include <u8c/u8enc.h>
# include <u8c/vfmt.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
uint_least8_t u8c_fmt(size_t * _outsz,uint_least32_t * * _out,uint_least32_t * _in,...) {
	va_list args;
	va_start(args,_in);
	uint_least8_t val = u8c_vfmt(_outsz,_out,_in,args);
	va_end(args);
	return val;
}
