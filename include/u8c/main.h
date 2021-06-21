/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Abort */
# if !defined(u8c_hdr_main)
# define u8c_hdr_main
# include <stdbool.h>
# include <stdint.h>
# include <stdnoreturn.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
/* Functions */
extern noreturn bool u8c_abrt(char const * const fl,long long const ln,char const * const fn,char const * const why);
extern bool          u8c_end( void);
extern bool          u8c_init(void);
/* Constants & Variables: */
extern bool const           u8c_dbg;
extern bool const           u8c_thrdsafe;
static char32_t const       u8c_unimax   = (char32_t)UINT32_C(0x10FFFF);
static uint_least64_t const u8c_ver      = UINT64_C(0x19);
/* Macros: */
# endif
