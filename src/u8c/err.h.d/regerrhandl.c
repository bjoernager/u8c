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
# include <stddef.h>
# include <u8c/err.h>
# include <u8c/intern.h>
static void u8c_regerrhandl_seterrhandl(enum u8c_errtyp _typ,u8c_errhandltyp _errhandl) {
	u8c_dat.errhandls[(size_t)_typ] = _errhandl;
}
struct u8c_regerrhandl_tuple u8c_regerrhandl(enum u8c_errtyp _typ,u8c_errhandltyp _errhandl) {
	struct u8c_regerrhandl_tuple ret = {
		.stat = false,
	};
# if defined(u8c_bethrdsafe)
	mtx_lock(&u8c_dat.errhandlslock);
# endif
	if(_typ == u8c_errtyp_all) {
		for(register int n = 0x0;n < (int)u8c_errtyp_all;n += 0x1) {
			u8c_regerrhandl_seterrhandl((enum u8c_errtyp)n,_errhandl);
		}
	}
	else {
		u8c_regerrhandl_seterrhandl(_typ,_errhandl);
	}
# if defined(u8c_bethrdsafe)
	mtx_unlock(&u8c_dat.errhandlslock);
# endif
	return ret;
}
