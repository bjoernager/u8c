/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_is)
# define u8c_hdr_is
# include <stdbool.h>
# include <stdint.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
/* Functions */
extern bool u8c_isalnum( uint_least8_t * const res,char32_t const chr);
extern bool u8c_isalpha( uint_least8_t * const res,char32_t const chr);
extern bool u8c_iscntrl( uint_least8_t * const res,char32_t const chr);
extern bool u8c_isdigit( uint_least8_t * const res,char32_t const chr);
extern bool u8c_ispunct( uint_least8_t * const res,char32_t const chr);
extern bool u8c_isspace( uint_least8_t * const res,char32_t const chr);
extern bool u8c_isxdigit(uint_least8_t * const res,char32_t const chr);
/* Constants & Variables: */
/* Macros: */
# endif
