/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_fmt)
# define u8c_hdr_fmt
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <uchar.h>
/* Enumerations: */
enum u8c_fmttyp {
	u8c_fmttyp_bgcol,  /* Background colour (uint_least32_t) */
	u8c_fmttyp_bgcol0, /* Background colour #0 */
	u8c_fmttyp_bool,   /* Boolean (bool) */
	u8c_fmttyp_byt,    /* Byte (char) */
	u8c_fmttyp_chr,    /* Character (uint_least32_t) */
	u8c_fmttyp_fgcol,  /* Foreground colour (uint_least32_t) */
	u8c_fmttyp_fgcol0, /* Foreground colour #0 */
	u8c_fmttyp_int,    /* Integer (int) */
	u8c_fmttyp_int16,  /* Integer 16 bit (int_least16_t) */
	u8c_fmttyp_int32,  /* Integer 32 bit (int_least32_t) */
	u8c_fmttyp_int64,  /* Integer 64 bit (int_least64_t) */
	u8c_fmttyp_int8,   /* Integer 8 bit (int_least8_t) */
	u8c_fmttyp_llong,  /* Long long (long long) */
	u8c_fmttyp_long,   /* Long (long) */
	u8c_fmttyp_sbyt,   /* Signed byte (signed char) */
	u8c_fmttyp_shrt,   /* Short (short) */
	u8c_fmttyp_str,    /* String (char32_t const *) */
	u8c_fmttyp_sz,     /* Size (size_t) */
	u8c_fmttyp_tm,     /* Time (uint_least64_t) */
	u8c_fmttyp_ubyt,   /* Unsigned byte (unsigned char) */
	u8c_fmttyp_uint,   /* Unsigned integer (unsigned int) */
	u8c_fmttyp_uint16, /* Unsigned integer 16 bit (uint_least16_t) */
	u8c_fmttyp_uint32, /* Unsigned integer 32 bit (uint_least32_t) */
	u8c_fmttyp_uint64, /* Unsigned integer 64 bit (uint_least64_t) */
	u8c_fmttyp_uint8,  /* Unsigned integer 8 bit (uint_least8_t) */
	u8c_fmttyp_ulong,  /* Unsigned long (unsigned long) */
	u8c_fmttyp_ullong, /* Unsigned long long (unsigned long long) */
	u8c_fmttyp_ushrt,  /* Unsigned short (unsigned short) */
};
/* Type definitions: */
/* Structures: */
struct u8c_fmt_tuple {
	char32_t const * str;
	size_t           strsz;
	bool             stat;
};
struct u8c_print_tuple {
	bool stat;
};
struct u8c_println_tuple {
	bool stat;
};
struct u8c_setfmt_tuple {
	bool stat;
};
struct u8c_vfmt_tuple {
	char32_t const * str;
	size_t           strsz;
	bool             stat;
};
struct u8c_vprint_tuple {
	bool stat;
};
/* Functions: */
extern struct u8c_fmt_tuple     u8c_fmt(    char32_t const * const restrict in,                                  ...);                 /* Format */
extern struct u8c_print_tuple   u8c_print(  FILE * restrict                 fp,  char32_t const * const restrict msg,           ...);  /* Print */
extern struct u8c_println_tuple u8c_println(FILE * restrict                 fp,  char32_t const * const restrict msg,           ...);  /* Print line */
extern struct u8c_setfmt_tuple  u8c_setfmt( uint_least8_t const             base,bool const                      endian);              /* Set format */
extern struct u8c_vfmt_tuple    u8c_vfmt(   char32_t const * const restrict in,  va_list                         args);                /* Variadic format */
extern struct u8c_vprint_tuple  u8c_vprint( FILE * restrict                 fp,  char32_t const * const restrict msg,   va_list args); /* Variadic print */
/* Constants & Variables: */
static uint_least32_t const u8c_col_azure      = UINT32_C(0x3DA9E1);
static uint_least32_t const u8c_col_ash        = UINT32_C(0xD2D2CC);
static uint_least32_t const u8c_col_black      = UINT32_C(0x444747);
static uint_least32_t const u8c_col_blue       = UINT32_C(0x3D3DE1);
static uint_least32_t const u8c_col_chartreuse = UINT32_C(0xA9E13D);
static uint_least32_t const u8c_col_cyan       = UINT32_C(0x3DE1E1);
static uint_least32_t const u8c_col_green      = UINT32_C(0x3ED13D);
static uint_least32_t const u8c_col_magenta    = UINT32_C(0xE13DE1);
static uint_least32_t const u8c_col_mint       = UINT32_C(0x3DE1A9);
static uint_least32_t const u8c_col_orange     = UINT32_C(0xE1A93D);
static uint_least32_t const u8c_col_red        = UINT32_C(0xE13D3D);
static uint_least32_t const u8c_col_rose       = UINT32_C(0xE13DA9);
static uint_least32_t const u8c_col_silver     = UINT32_C(0x9CA1A1);
static uint_least32_t const u8c_col_violet     = UINT32_C(0xA93dE1);
static uint_least32_t const u8c_col_white      = UINT32_C(0xF8F8F1);
static uint_least32_t const u8c_col_yellow     = UINT32_C(0xE1E13D);
/* Macros: */
# if defined(NDEBUG)
/* Debug print */
# define u8c_dbgprint(...) ((void)0x0)
# else
# define u8c_dbgprint(...) u8c_println(stderr,__VA_ARGS__)
# endif
# endif
