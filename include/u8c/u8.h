/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_u8)
# define u8c_hdr_u8
# include <stdbool.h>
# include <stddef.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
/* Functions */
extern bool u8c_u8alloc(unsigned char * * const       u32,size_t const                  sz);
extern bool u8c_u8dec(  size_t * const                sz, char32_t const * * const      out,unsigned char const * const in);
extern bool u8c_u8enc(  size_t * const                sz, unsigned char const * * const out,char32_t const * const      in);
extern bool u8c_u8free( unsigned char const * * const u8);
/* Constants & Variables: */
/* Macros: */
# endif
