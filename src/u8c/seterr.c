/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include "err.h"
# include "errlock.h"
# include "seterr.h"
# include <assert.h>
# include <stdint.h>
# include <stdlib.h>
# include <u8c/dbgprint.h>
# include <u8c/u32cp.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
uint_least8_t u8c_seterr(uint_least32_t * _msg) {
	assert(_msg != NULL);
	u8c_dbgprint(_msg);
# if defined(u8c_bethrdsafe)
	mtx_lock(&u8c_errlock);
# endif
	free(u8c_err);
	u8c_u32cp(NULL,&u8c_err,_msg);
# if defined(u8c_bethrdsafe)
	mtx_unlock(&u8c_errlock);
# endif
	return UINT8_C(0x0);
}
