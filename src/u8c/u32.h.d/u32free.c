/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <u8c/u32.h>
bool u8c_u32free(char32_t const * * const _u32) {
	free((char32_t *)*_u32); /* This cast does indeed discard a const-qualifier, but it is not undefined behaviour, as the array must have been allocated by calloc or malloc, meaning it's original type is not const-qualified. */
	*_u32 = NULL;
	return false;
}