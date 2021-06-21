/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include "intern.h"
# include <assert.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/err.h>
# include <u8c/fmt.h>
# include <u8c/u32.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
bool u8c_seterr(char32_t const * const _msg,enum u8c_errtyp _typ) {
	assert(_msg != NULL);
	//u8c_dbgprint(_msg);
# if defined(u8c_bethrdsafe)
	mtx_lock(&u8c_dat.errlock);
# endif
	u8c_u32free(&u8c_dat.err);
	u8c_u32cp(NULL,&u8c_dat.err,_msg);
# if defined(u8c_bethrdsafe)
	mtx_unlock(&u8c_dat.errlock);
# endif
# if defined(u8c_bethrdsafe)
	mtx_lock(&u8c_dat.errhandlslock);
# endif
	if(u8c_dat.errhandls[(size_t)_typ] != NULL) {
		u8c_dat.errhandls[(size_t)_typ](_typ);
	}
# if defined(u8c_bethrdsafe)
	mtx_unlock(&u8c_dat.errhandlslock);
# endif
	return false;
}
