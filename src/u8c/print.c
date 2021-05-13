/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or	(at your option) any later version.

	u8c is distributed in the hope that it will be useful,	but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <u8c/fmttyp.h>
# include <u8c/u8enc.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
uint_least8_t u8c_print(uint_least32_t * msg,...) {
	va_list args;
	va_start(args,msg);
	for(size_t n = (size_t){0x0};;n += (size_t){0x1}) {
		if(msg[n] == (uint_least32_t){0x0}) {
			fwrite(&(uint_least8_t){0xA},(size_t){0x1},(size_t){0x1},stdout);
			break;
		}
		if(msg[n] == (uint_least32_t){0xFFFD}) {
			enum u8c_fmttyp fmttyp = va_arg(args,enum u8c_fmttyp);
			switch(fmttyp) {
			case u8c_fmttyp_chr:
				{
					uint_least32_t const chr = va_arg(args,uint_least32_t);
					if(chr == (uint_least32_t){0x0}) {
						continue;
					}
					size_t          strsz = (size_t){0x0};
					uint_least8_t * str   = NULL;
					u8c_u8enc((uint_least32_t[]){chr,0x0},&strsz,&str);
					fwrite(str,(size_t){0x1},strsz - (size_t){0x1},stdout);
					free(str);
					break;
				}
			case u8c_fmttyp_int:
				{
					int_least64_t n = va_arg(args,int_least64_t);
					if(n < 0x0) {
						size_t               chrsz = (size_t){0x0};
						uint_least8_t *      chr   = NULL;
						u8c_u8enc((uint_least32_t[]){0x2212,0x0},&chrsz,&chr);
						fwrite(chr,(size_t){0x1},chrsz - (size_t){0x1},stdout);
						free(chr);
					}
					for(;n != 0x0;n /= (int_least64_t){0xB}) {
						
					}
					break;
				}
			case u8c_fmttyp_str:
				{
					size_t          strsz = (size_t){0x0};
					uint_least8_t * str   = NULL;
					u8c_u8enc(va_arg(args,uint_least32_t *),&strsz,&str);
					fwrite(str,(size_t){0x1},strsz - (size_t){0x1},stdout);
					free((void *)str);
					break;
				}
			case u8c_fmttyp_uint:
				{
					break;
				}
			}
			continue;
		}
		size_t          chrsz = (size_t){0x0};
		uint_least8_t * chr   = NULL;
		u8c_u8enc((uint_least32_t[]){msg[n],0x0,0x0},&chrsz,&chr);
		fwrite(chr,(size_t){0x1},chrsz - (size_t){0x1},stdout);
		free((void *)chr);
	}
	va_end(args);
	return 0x0;
}
/*
	#######################
	#                     #
	# ##  ##  ### # # ### #
	# # # # #  #  ###  #  #
	# ##  ##   #  ###  #  #
	# #   # #  #  ###  #  #
	# #   # # ### # #  #  #
	#                     #
	#######################
*/
