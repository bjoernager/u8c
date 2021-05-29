/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Variadic format */
# if !defined(u8c_sym_vfmt)
# define u8c_sym_vfmt
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# if defined(__cplusplus)
extern "C" {
# endif
extern uint_least8_t u8c_vfmt(size_t * const sz,uint_least32_t * * const out,uint_least32_t * const in,va_list args);
# if defined(__cplusplus)
}
# endif
# endif
