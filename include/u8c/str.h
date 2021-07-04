/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_str)
# define u8c_hdr_str
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
struct u8c_stralloc_tuple {
	bool       stat;
	char32_t * str;
};
struct u8c_strcat_tuple {
	bool             stat;
	char32_t const * str;
	size_t           strsz;
};
struct u8c_strcmp_tuple {
	bool          stat;
	uint_least8_t res;
};
struct u8c_strcp_tuple {
	bool             stat;
	char32_t const * str;
	size_t           strsz;
};
struct u8c_strfndchr_tuple {
	size_t pos;
	bool   stat;
};
struct u8c_strfndpat_tuple {
	size_t pos;
	bool   stat;
};
struct u8c_strfree_tuple {
	bool stat;
};
struct u8c_strins_tuple {
	bool             stat;
	char32_t const * str;
	size_t           strsz;
};
struct u8c_strsubstr_tuple {
	bool             stat;
	char32_t const * str;
	size_t           strsz;
};
struct u8c_strsz_tuple {
	bool   stat;
	size_t sz;
};
/* Functions: */
extern struct u8c_stralloc_tuple  u8c_stralloc( size_t const                    sz);                                                                              /* String allocate */
extern struct u8c_strcat_tuple    u8c_strcat(   char32_t const * const restrict str, char32_t const * const          rstr);                                      /* String concatenate */
extern struct u8c_strcmp_tuple    u8c_strcmp(   char32_t const * const restrict lstr,char32_t const * const restrict  rstr);                                      /* String compare */
extern struct u8c_strcp_tuple     u8c_strcp(    char32_t const * const restrict in);                                                                              /* String copy */
extern struct u8c_strfndchr_tuple u8c_strfndchr(char32_t const * const restrict in,   char32_t const                  chr);                                       /* String find character */
extern struct u8c_strfndpat_tuple u8c_strfndpat(char32_t const * const restrict in,   char32_t const * const restrict pat);                                       /* String find pattern */
extern struct u8c_strfree_tuple   u8c_strfree(  char32_t const * const restrict str);                                                                             /* String free */
extern struct u8c_strins_tuple    u8c_strins(   size_t const                    pos,  char32_t const * const restrict str0,char32_t const * const restrict str1); /* String insert */
extern struct u8c_strsubstr_tuple u8c_strsubstr(size_t const                    start,size_t const                    len, char32_t const * const restrict in);   /* String sub-string */
extern struct u8c_strsz_tuple     u8c_strsz(    char32_t const * const restrict in);                                                                              /* String size */
/* Constants & Variables: */
/* Macros: */
# endif
