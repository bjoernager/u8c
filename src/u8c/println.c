/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include "seterr.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <u8c/println.h>
# include <u8c/SIZE_C.h>
# include <u8c/vprint.h>
uint_least8_t u8c_println(FILE * _fp,uint_least32_t * _msg,...) {
	va_list args;
	va_start(args,_msg);
	if(u8c_vprint(_fp,_msg,args)) {
		return UINT8_C(0x1);
	}
	if(fputc(0xA,stdout) == EOF) {
		u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x70),UINT32_C(0x72),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x6C),UINT32_C(0x6E),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x66),UINT32_C(0x70),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x63),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x55),UINT32_C(0x6E),UINT32_C(0x61),UINT32_C(0x62),UINT32_C(0x6C),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0x74),UINT32_C(0x6F),UINT32_C(0x20),UINT32_C(0x77),UINT32_C(0x72),UINT32_C(0x69),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0x74),UINT32_C(0x6F),UINT32_C(0x20),UINT32_C(0x73),UINT32_C(0x74),UINT32_C(0x64),UINT32_C(0x6F),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_println: fputc: Unable to write to stdout. */
		return UINT8_C(0x0);
	}
	va_end(args);
	return UINT8_C(0x0);
}
