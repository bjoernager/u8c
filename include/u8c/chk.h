/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_hdr_chk)
# define u8c_hdr_chk
# include <stdbool.h>
# include <uchar.h>
/* Enumerations: */
/* Type definitions: */
/* Structures: */
struct u8c_isalnum_tuple {
	bool res;
	bool stat;
};
struct u8c_isalpha_tuple {
	bool res;
	bool stat;
};
struct u8c_iscntrl_tuple {
	bool res;
	bool stat;
};
struct u8c_isdigit_tuple {
	bool res;
	bool stat;
};
struct u8c_islower_tuple {
	bool res;
	bool stat;
};
struct u8c_ispunct_tuple {
	bool res;
	bool stat;
};
struct u8c_isspace_tuple {
	bool res;
	bool stat;
};
struct u8c_issurro_tuple {
	bool res;
	bool stat;
};
struct u8c_isupper_tuple {
	bool res;
	bool stat;
};
struct u8c_isxdigit_tuple {
	bool res;
	bool stat;
};
/* Functions: */
extern struct u8c_isalnum_tuple  u8c_isalnum( char32_t const chr); /* Is alphanumeric */
extern struct u8c_isalpha_tuple  u8c_isalpha( char32_t const chr); /* Is alphabetic */
extern struct u8c_iscntrl_tuple  u8c_iscntrl( char32_t const chr); /* Is control character */
extern struct u8c_isdigit_tuple  u8c_isdigit( char32_t const chr); /* Is digit */
extern struct u8c_islower_tuple  u8c_islower( char32_t const chr); /* Is lowercase */
extern struct u8c_ispunct_tuple  u8c_ispunct( char32_t const chr); /* Is punctuation */
extern struct u8c_isspace_tuple  u8c_isspace( char32_t const chr); /* Is space */
extern struct u8c_issurro_tuple  u8c_issurro( char32_t const chr); /* Is surrogate point */
extern struct u8c_isupper_tuple  u8c_isupper( char32_t const chr); /* Is uppercase */
extern struct u8c_isxdigit_tuple u8c_isxdigit(char32_t const chr); /* Is hexadecimal digit */
/* Constants & Variables: */
/* Macros: */
# endif
