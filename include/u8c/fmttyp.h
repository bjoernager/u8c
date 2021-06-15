/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Format type */
# if !defined(u8c_sym_fmttyp)
# define u8c_sym_fmttyp
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
# endif
