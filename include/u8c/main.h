/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_main)
# define u8c_hdr_main
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdnoreturn.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
struct u8c_end_tuple {
	bool stat;
};
struct u8c_init_tuple {
	bool stat;
};
struct u8c_uniblk_tuple {
	char32_t const * blk;
	size_t           blksz;
	bool             stat;
};
struct u8c_uninm_tuple {
	char32_t const * nm;
	size_t           nmsz;
	bool stat;
};
/* Functions: */
noreturn extern void           u8c_abrtfn(char const * const restrict fl, long const ln,char const * const restrict fn,char const * const restrict why); /* Abort function */
extern struct u8c_end_tuple    u8c_end(   void);                                                                                                         /* End */
extern struct u8c_init_tuple   u8c_init(  void);                                                                                                         /* Initialise */
extern struct u8c_uniblk_tuple u8c_uniblk(char32_t const              chr);                                                                              /* Unicode block */
extern struct u8c_uninm_tuple  u8c_uninm( char32_t const              chr);                                                                              /* Unicode name */
/* Constants & Variables: */
extern bool const           u8c_dbg;                       /* Debug */
extern bool const           u8c_thrdsafe;                  /* Thread-safe */
static char32_t const       u8c_unimax   = U'\U0010FFFF';  /* Unicode maximum */
static uint_least64_t const u8c_ver      = UINT64_C(0x1A); /* Version */
/* Macros: */
# define u8c_abrt(why) u8c_abrtfn(__FILE__,(long)__LINE__,__func__,why) /* Abort */
# endif
