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
# include <u8c/isspace.h>
uint_least8_t u8c_isspace(uint_least8_t * const _res,uint_least32_t _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case UINT32_C(0x9):  /* HORIZONTAL TABULATION */
	case UINT32_C(0xA):  /* NEW LINE */
	case UINT32_C(0xB):  /* VERTICAL TABULATION */
	case UINT32_C(0xC):  /* FORM FEED */
	case UINT32_C(0xD):  /* CARRIAGE RETURN */
	case UINT32_C(0x20): /* SPACE */
		*_res = UINT8_C(0x1);
		break;
	}
	return UINT8_C(0x0);
}
