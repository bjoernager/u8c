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

#ifndef u8c_HEADER_FORMAT
#define u8c_HEADER_FORMAT

#include <u8c/u8c.h>

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

u8c_NO_DISCARD u8c_NO_THROW size_t u8c_encode_utf8_length(uint_least32_t const* u8c_RESTRICT _source, size_t _count);
u8c_NO_DISCARD u8c_NO_THROW size_t u8c_decode_utf8_length(char const*           u8c_RESTRICT _source, size_t _count);

u8c_NO_DISCARD u8c_NO_THROW size_t u8c_encode_utf16_length(uint_least32_t const* u8c_RESTRICT _source, size_t _count);
u8c_NO_DISCARD u8c_NO_THROW size_t u8c_decode_utf16_length(uint_least16_t const* u8c_RESTRICT _source, size_t _count);

u8c_NO_THROW size_t u8c_encode_utf8(char*           u8c_RESTRICT _buffer, uint_least32_t const* u8c_RESTRICT _source, size_t _count);
u8c_NO_THROW size_t u8c_decode_utf8(uint_least32_t* u8c_RESTRICT _buffer, char const*           u8c_RESTRICT _source, size_t _count);

u8c_NO_THROW size_t u8c_encode_utf16(uint_least16_t* u8c_RESTRICT _buffer, uint_least32_t const* u8c_RESTRICT _source, size_t _count);
u8c_NO_THROW size_t u8c_decode_utf16(uint_least32_t* u8c_RESTRICT _buffer, uint_least16_t const* u8c_RESTRICT _source, size_t _count);

#ifdef __cplusplus
}
#endif

#endif
