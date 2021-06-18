/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# if !defined(u8c_sym_dattyp)
# define u8c_sym_dattyp
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/errhandltyp.h>
# include <u8c/errtyp.h>
# include <u8c/SIZE_C.h>
# include <uchar.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
struct u8c_dattyp {
	bool             fmtendian;
	unsigned char    pad0[sizeof(void(*)(void)) - SIZE_C(0x1)]; /* Padding. */
	char32_t const * err;
	u8c_errhandltyp  errhandls[(size_t)u8c_errtyp_maxerrtyp];
	uint_least8_t    fmtbase;
	uint_least8_t    stat;
# if defined(u8c_bethrdsafe)
	unsigned char pad1[sizeof(void(*)(void)) - SIZE_C(0x2)]; /* Padding. */
	mtx_t         errlock;
	mtx_t         errhandlslock;
	mtx_t         fmtlock;
# endif
};
# endif
