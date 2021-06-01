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
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <u8c/seterr.h>
# include <u8c/u8enc.h>
# include <u8c/SIZE_C.h>
# include <u8c/vfmt.h>
# include <u8c/vprint.h>
uint_least8_t u8c_vprint(FILE * _fp,uint_least32_t * const _msg,va_list _args) {
	assert(_msg != NULL);
	uint_least32_t * str0 = NULL;
	u8c_vfmt(NULL,&str0,_msg,_args);
	size_t          str1sz = SIZE_C(0x0);
	uint_least8_t * str1   = NULL;
	u8c_u8enc(&str1sz,&str1,str0);
	assert(str1sz > SIZE_C(0x0));
	if(fwrite(str1,sizeof(uint_least8_t),str1sz - SIZE_C(0x1),_fp) < str1sz - SIZE_C(0x1)) {
		u8c_seterr((uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x76),UINT32_C(0x70),UINT32_C(0x72),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x66),UINT32_C(0x77),UINT32_C(0x72),UINT32_C(0x69),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x55),UINT32_C(0x6E),UINT32_C(0x61),UINT32_C(0x62),UINT32_C(0x6C),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0x74),UINT32_C(0x6F),UINT32_C(0x20),UINT32_C(0x77),UINT32_C(0x72),UINT32_C(0x69),UINT32_C(0x74),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0x74),UINT32_C(0x6F),UINT32_C(0x20),UINT32_C(0x73),UINT32_C(0x74),UINT32_C(0x64),UINT32_C(0x6F),UINT32_C(0x75),UINT32_C(0x74),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_vprint: fwrite: Unable to write to stdout. */
		return UINT8_C(0x1);
	}
	free(str0);
	free(str1);
	return UINT8_C(0x0);
}
