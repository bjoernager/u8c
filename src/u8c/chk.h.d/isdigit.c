/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/chk.h>
struct u8c_isdigit_tuple u8c_isdigit(char32_t const _chr) {
	struct u8c_isdigit_tuple ret = {
		.stat = false,
	};
	switch(_chr) {
	default:
		ret.res = false;
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
		ret.res = true;
		break;
	}
	return ret;
}
