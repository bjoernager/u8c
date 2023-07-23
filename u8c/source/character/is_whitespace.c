/*
	Copyright 2021, 2023 Gabriel Bjørnager Jensen.

	This file is part of u8c.

    u8c is free software: you can redistribute it
	and/or modify it under the terms of the GNU
	Lesser General Public License as published by
	the Free Software Foundation, either version 3 of
	the License, or (at your option) any later
	version.

    u8c is distributed in the hope that it will be
	useful, but WITHOUT ANY WARRANTY; without even
	the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	Lesser General Public License for more details.

    You should have received a copy of the GNU
	Lesser General Public License along with u8c. If
	not, see <https://www.gnu.org/licenses/>.
*/

#include <u8c/character.h>

#include <stdbool.h>
#include <stdint.h>

bool u8c_is_whitespace(uint_least32_t const code_point) {
	switch(code_point) {
	default:
		return false;

	case UINT32_C(0x0009): // HORIZONTAL TABULATION
	case UINT32_C(0x000A): // NEW LINE
	case UINT32_C(0x000B): // VERTICAL TABULATION
	case UINT32_C(0x000C): // FORM FEED
	case UINT32_C(0x000D): // CARRIAGE RETURN
	case UINT32_C(0x0020): // SPACE
	case UINT32_C(0x00A0): // NO-BREAK SPACE
	case UINT32_C(0x2002): // EN SPACE
	case UINT32_C(0x2003): // EM SPACE
	case UINT32_C(0x2008): // PUNCTUATION SPACE
	case UINT32_C(0x2009): // THIN SPACE
	case UINT32_C(0x203F): // NARROW NO-BREAK SPACE
		return true;
	}
}
