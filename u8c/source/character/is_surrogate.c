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

bool u8c_is_surrogate(uint_least32_t const code_point)  {
	return code_point >= UINT32_C(0xD800) && code_point <= UINT32_C(0xDFFF);
}
