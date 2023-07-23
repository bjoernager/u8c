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

/*
	Greater Header Dependencies:

	u8c →┬→ character
	     └→ format
*/

#ifndef u8c_HEADER_U8C
#define u8c_HEADER_U8C

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#if defined(__GNUC__) || defined(__clang__)

#define u8c_RESTRICT __restrict__

#elif defined(_MSC_VER)

#define u8c_RESTRICT __restrict

#else

#define u8c_RESTRICT

#endif
#else

#define u8c_RESTRICT restrict

#endif

#ifdef __GNUC__

#define u8c_ALWAYS_INLINE __attribute__ ((__always_inline__))
#define u8c_NO_DISCARD    __attribute__ ((__warn_unused_result__))
#define u8c_NO_THROW      __attribute__ ((__nothrow__))
#define u8c_UNSEQUENCED   __attribute__ ((__const__))

#elif __STDC_VERSION__ >= 202311

#define u8c_ALWAYS_INLINE
#define u8c_NO_DISCARD    [[nodiscard]]
#define u8c_NO_THROW
#define u8c_UNSEQUENCED   [[unsequenced]]

#elif __cplusplus >= 201703

#define u8c_ALWAYS_INLINE
#define u8c_NO_DISCARD    [[nodiscard]]
#define u8c_NO_THROW
#define u8c_UNSEQUENCED

#else

#define u8c_ALWAYS_INLINE
#define u8c_NO_DISCARD
#define u8c_NO_THROW
#define u8c_UNSEQUENCED

#endif

#define u8c_VERSION ((uint_least32_t)+UINT32_C(0x1D))

#define u8c_MAXIMUM_CODE_POINT ((uint_least32_t)+UINT32_C(0x0010FFFF))

#endif
