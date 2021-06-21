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
bool u8c_iscntrl(uint_least8_t * const _res,char32_t const _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case U'\x0':   /* NULL */
	case U'\x1':  /* START OF HEADING */
	case U'\x2':  /* START OF TEXT */
	case U'\x3':  /* END OF TEXT */
	case U'\x4':  /* END OF TRANSMISSION */
	case U'\x5':  /* ENQUIRY */
	case U'\x6':  /* ACKNOWLEDGE */
	case U'\a':   /* BELL */
	case U'\b':   /* BACKSPACE */
	case U'\t':   /* HORIZONTAL TABULATION */
	case U'\n':   /* NEW LINE */
	case U'\v':   /* VERTICAL TABULATION */
	case U'\f':   /* FORM FEED */
	case U'\r':   /* CARRIAGE RETURN */
	case U'\xE':  /* SHIFT OUT */
	case U'\xF':  /* SHIFT IN */
	case U'\x10': /* DATA LINK ESCAPE */
	case U'\x11': /* DEVICE CONTROL ONE */
	case U'\x12': /* DEVICE CONTROL TWO */
	case U'\x13': /* DEVICE CONTROL THREE */
	case U'\x14': /* DEVICE CONTROL FOUR */
	case U'\x15': /* NEGATIVE ACKNOWLEDGE */
	case U'\x16': /* SYNCHRONOUS IDLE */
	case U'\x17': /* END OF TRANSMISSION BLOCK */
	case U'\x18': /* CANCEL */
	case U'\x19': /* END OF MEDIUM */
	case U'\x1A': /* SUBSTITUTE */
	case U'\x1B': /* ESCAPE */
	case U'\x1C': /* FILE SEPERATOR */
	case U'\x1D': /* GROUP SEPERATOR */
	case U'\x1E': /* RECORD SEPERATOR */
	case U'\x1F': /* UNIT SEPERATOR */
		*_res = UINT8_C(0x1);
		break;
	}
	return false;
}
