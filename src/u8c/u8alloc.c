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
# include <stdlib.h>
# include <u8c/seterr.h>
# include <u8c/u8alloc.h>
bool u8c_u8alloc(unsigned char * * const _u8,size_t const _sz) {
	unsigned char * arr = NULL;
	if((arr = calloc(sizeof *arr,_sz)) == NULL) {
		u8c_seterr(U"u8c_u8alloc: Unable to allocate resources (not enough memory?).");
		return true;
	}
	*_u8 = arr;
	return false;
}