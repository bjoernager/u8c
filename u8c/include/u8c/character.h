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

#ifndef u8c_HEADER_CHARACTER
#define u8c_HEADER_CHARACTER

#include <u8c/u8c.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// U+0001F676 SANS-SERIF HEAVY DOUBLE TURNED COMMA QUOTATION MARK ORNAMENT
#define u8c_MAXIMUM_NAME_LENGTH ((size_t)+0x3Cu)

u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_surrogate(uint_least32_t _code_point);

u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_control(uint_least32_t _code_point);

u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_punctuation(uint_least32_t _code_point);
u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_whitespace( uint_least32_t _code_point);

u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_numeric(            uint_least32_t _code_point);
u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_hexadecimal_numeric(uint_least32_t _code_point);

u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_alphabetic(uint_least32_t _code_point);
u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_majuscule( uint_least32_t _code_point);
u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED bool u8c_is_minuscule( uint_least32_t _code_point);

u8c_NO_THROW size_t u8c_unicode_name(char* u8c_RESTRICT _buffer, uint_least32_t _code_point);

#ifdef __cplusplus
}
#endif

#endif
