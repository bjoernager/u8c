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

bool u8c_is_hexadecimal_numeric(uint_least32_t const code_point) {
	switch(code_point) {
	default:
		return false;

	case UINT32_C(0x0030): // DIGIT ZERO
	case UINT32_C(0x0031): // DIGIT ONE
	case UINT32_C(0x0032): // DIGIT TWO
	case UINT32_C(0x0033): // DIGIT THREE
	case UINT32_C(0x0034): // DIGIT FOUR
	case UINT32_C(0x0035): // DIGIT FIVE
	case UINT32_C(0x0036): // DIGIT SIX
	case UINT32_C(0x0037): // DIGIT SEVEN
	case UINT32_C(0x0038): // DIGIT EIGHT
	case UINT32_C(0x0039): // DIGIT NINE
	case UINT32_C(0x0041): // LATIN CAPITAL LETTER A
	case UINT32_C(0x0042): // LATIN CAPITAL LETTER B
	case UINT32_C(0x0043): // LATIN CAPITAL LETTER C
	case UINT32_C(0x0044): // LATIN CAPITAL LETTER D
	case UINT32_C(0x0045): // LATIN CAPITAL LETTER E
	case UINT32_C(0x0046): // LATIN CAPITAL LETTER F
		return true;
	}
}
