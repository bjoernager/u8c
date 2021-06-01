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
# include <stddef.h>
# include <stdint.h>
# include <u8c/iscntrl.h>
uint_least8_t u8c_iscntrl(uint_least8_t * const _res,uint_least32_t const _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case UINT32_C(0x0):  /* NULL */
	case UINT32_C(0x1):  /* START OF HEADING */
	case UINT32_C(0x2):  /* START OF TEXT */
	case UINT32_C(0x3):  /* END OF TEXT */
	case UINT32_C(0x4):  /* END OF TRANSMISSION */
	case UINT32_C(0x5):  /* ENQUIRY */
	case UINT32_C(0x6):  /* ACKNOWLEDGE */
	case UINT32_C(0x7):  /* BELL */
	case UINT32_C(0x8):  /* BACKSPACE */
	case UINT32_C(0x9):  /* HORIZONTAL TABULATION */
	case UINT32_C(0xA):  /* NEW LINE */
	case UINT32_C(0xB):  /* VERTICAL TABULATION */
	case UINT32_C(0xC):  /* FORM FEED */
	case UINT32_C(0xD):  /* CARRIAGE RETURN */
	case UINT32_C(0xE):  /* SHIFT OUT */
	case UINT32_C(0xF):  /* SHIFT IN */
	case UINT32_C(0x10): /* DATA LINK ESCAPE */
	case UINT32_C(0x11): /* DEVICE CONTROL ONE */
	case UINT32_C(0x12): /* DEVICE CONTROL TWO */
	case UINT32_C(0x13): /* DEVICE CONTROL THREE */
	case UINT32_C(0x14): /* DEVICE CONTROL FOUR */
	case UINT32_C(0x15): /* NEGATIVE ACKNOWLEDGE */
	case UINT32_C(0x16): /* SYNCHRONOUS IDLE */
	case UINT32_C(0x17): /* END OF TRANSMISSION BLOCK */
	case UINT32_C(0x18): /* CANCEL */
	case UINT32_C(0x19): /* END OF MEDIUM */
	case UINT32_C(0x1A): /* SUBSTITUTE */
	case UINT32_C(0x1B): /* ESCAPE */
	case UINT32_C(0x1C): /* FILE SEPERATOR */
	case UINT32_C(0x1D): /* GROUP SEPERATOR */
	case UINT32_C(0x1E): /* RECORD SEPERATOR */
	case UINT32_C(0x1F): /* UNIT SEPERATOR */
		*_res = UINT8_C(0x1);
		break;
	}
	return UINT8_C(0x0);
}
