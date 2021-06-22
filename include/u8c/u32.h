/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_u32)
# define u8c_hdr_u32
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
/* Functions */
extern bool u8c_u32alloc( char32_t * * const       u32,size_t const             sz);
extern bool u8c_u32cat(   size_t * const           sz, char32_t const * * const out,  char32_t const * const lstr,char32_t const * const rstr);
extern bool u8c_u32cmp(   uint_least8_t * const    res,char32_t const * const   lstr, char32_t const * const rstr);
extern bool u8c_u32cp(    size_t * const           sz, char32_t const * * const out,  char32_t const * const in);
extern bool u8c_u32fndchr(size_t * const           pos,char32_t const * const   in,   char32_t const         chr);
extern bool u8c_u32fndpat(size_t * const           pos,char32_t const * const   in,   char32_t const * const pat);
extern bool u8c_u32free(  char32_t const * * const u32);
extern bool u8c_u32ins(   size_t * const           sz, char32_t const * * const out,  size_t const           pos, char32_t const * const str0,char32_t const * const str1);
extern bool u8c_u32substr(char32_t const * * const out,size_t const             start,size_t const           len, char32_t const * const in);
extern bool u8c_u32sz(    size_t *                 sz, char32_t const *         in);
/* Constants & Variables: */
static char32_t const u8c_u32max = U'\x10FFFF';
/* Macros: */
# endif
