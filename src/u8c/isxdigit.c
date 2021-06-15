/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <assert.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/isxdigit.h>
bool u8c_isxdigit(uint_least8_t * const _res,char32_t const _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case UINT32_C(0x30):   /* DIGIT ZERO */
	case UINT32_C(0x31):   /* DIGIT ONE */
	case UINT32_C(0x32):   /* DIGIT TWO */
	case UINT32_C(0x33):   /* DIGIT THREE */
	case UINT32_C(0x34):   /* DIGIT FOUR */
	case UINT32_C(0x35):   /* DIGIT FIVE */
	case UINT32_C(0x36):   /* DIGIT SIX */
	case UINT32_C(0x37):   /* DIGIT SEVEN */
	case UINT32_C(0x38):   /* DIGIT EIGHT */
	case UINT32_C(0x39):   /* DIGIT NINE */
	case UINT32_C(0x41):   /* LATIN CAPITAL LETTER A */
	case UINT32_C(0x42):   /* LATIN CAPITAL LETTER B */
	case UINT32_C(0x43):   /* LATIN CAPITAL LETTER C */
	case UINT32_C(0x44):   /* LATIN CAPITAL LETTER D */
	case UINT32_C(0x45):   /* LATIN CAPITAL LETTER E */
	case UINT32_C(0x46):   /* LATIN CAPITAL LETTER F */
		*_res = UINT8_C(0x1);
		break;
	}
	return false;
}
