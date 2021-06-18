/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include "dat.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <u8c/end.h>
# include <u8c/SIZE_C.h>
# include <u8c/u32free.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
bool u8c_end(void) {
	if(!u8c_dat.stat) {
		return false;
	}
# if defined(u8c_bethrdsafe)
	/* Destroy mutexes: */
	mtx_destroy(&u8c_dat.errhandlslock);
	mtx_destroy(&u8c_dat.errlock);
	mtx_destroy(&u8c_dat.fmtlock);
# endif
	/* Free error message: */
	u8c_u32free(&u8c_dat.err);
	/* Set default formatting options: */
	u8c_dat.fmtbase   = UINT8_C(0xC);
	u8c_dat.fmtendian = UINT8_C(0x0);
	/* Set status: */
	u8c_dat.stat = UINT8_C(0x0);
	return false;
}
