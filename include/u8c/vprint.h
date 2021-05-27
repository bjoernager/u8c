/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Variadic print */
# if !defined(u8c_sym_vprint)
# define u8c_sym_vprint
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# if defined(__cplusplus)
extern "C" {
# endif
extern uint_least8_t u8c_vprint(FILE * fp,uint_least32_t * msg,va_list args);
# if defined(__cplusplus)
}
# endif
# endif
