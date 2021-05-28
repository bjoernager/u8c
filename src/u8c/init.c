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
# include "stat.h"
# include <stddef.h>
# include <stdint.h>
# include <u8c/init.h>
# include <u8c/u32cp.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
uint_least8_t u8c_init(void) {
# if defined(u8c_bethrdsafe)
	if(mtx_init(&u8c_errlock,mtx_plain) == thrd_error) {
		return UINT8_C(0x2);
	}
# endif
	/* Set default error message: */
	u8c_u32cp(NULL,&u8c_err,(uint_least32_t[]){UINT32_C(0x75),UINT32_C(0x38),UINT32_C(0x63),UINT32_C(0x5F),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x69),UINT32_C(0x74),UINT32_C(0x3A),UINT32_C(0x20),UINT32_C(0x44),UINT32_C(0x65),UINT32_C(0x66),UINT32_C(0x61),UINT32_C(0x75),UINT32_C(0x6C),UINT32_C(0x74),UINT32_C(0x20),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x72),UINT32_C(0x6F),UINT32_C(0x72),UINT32_C(0x20),UINT32_C(0x6D),UINT32_C(0x65),UINT32_C(0x73),UINT32_C(0x73),UINT32_C(0x61),UINT32_C(0x67),UINT32_C(0x65),UINT32_C(0x2E),UINT32_C(0x0),}); /* u8c_init: Default error message. */
	/* Set status: */
	u8c_stat = UINT8_C(0x0);
	return UINT8_C(0x0);
}
