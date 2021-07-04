/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(SIZE_C)
# include <limits.h>
# include <stdint.h>
# if SIZE_MAX == UINT_LEAST8_MAX
# define SIZE_C(val) UINT8_C(val)
# elif SIZE_MAX == UINT_LEAST16_MAX
# define SIZE_C(val) UINT16_C(val)
# elif SIZE_MAX == UINT_LEAST32_MAX
# define SIZE_C(val) UINT32_C(val)
# elif SIZE_MAX == UINT_LEAST64_MAX
# define SIZE_C(val) UINT64_C(val)
# else
# define SIZE_C(val) ((size_t)UINTMAX_C(val))
# endif
# endif
