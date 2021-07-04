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
struct u8c_u8alloc_tuple {
	bool            stat;
	unsigned char * u8;
};
struct u8c_u8dec_tuple {
	bool             stat;
	char32_t const * str;
	size_t           strsz;
};
struct u8c_u8enc_tuple {
	bool                  stat;
	unsigned char const * u8;
	size_t                u8sz;
};
struct u8c_u8free_tuple {
	bool stat;
};
/* Functions: */
extern struct u8c_u8alloc_tuple u8c_u8alloc(size_t const                         sz); /* UTF-8 allocate */
extern struct u8c_u8dec_tuple   u8c_u8dec(  unsigned char const * const restrict u8); /* UTF-8 decode */
extern struct u8c_u8enc_tuple   u8c_u8enc(  char32_t const * const restrict      u8); /* UTF-8 encode */
extern struct u8c_u8free_tuple  u8c_u8free( unsigned char const * const restrict u8); /* UTF-8 free */
/* Constants & Variables: */
/* Macros: */
# endif
