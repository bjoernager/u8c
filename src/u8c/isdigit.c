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
# include <u8c/is.h>
bool u8c_isdigit(uint_least8_t * const _res,char32_t const _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case U'0':      /* DIGIT ZERO */
	case U'1':      /* DIGIT ONE */
	case U'2':      /* DIGIT TWO */
	case U'3':      /* DIGIT THREE */
	case U'4':      /* DIGIT FOUR */
	case U'5':      /* DIGIT FIVE */
	case U'6':      /* DIGIT SIX */
	case U'7':      /* DIGIT SEVEN */
	case U'8':      /* DIGIT EIGHT */
	case U'9':      /* DIGIT NINE */
	case U'\u218A': /* TURNED DIGIT TWO */
	case U'\u218B': /* TURNED DIGIT THREE */
		*_res = UINT8_C(0x1);
		break;
	}
	return false;
}
