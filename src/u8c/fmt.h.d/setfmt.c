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
# include <u8c/fmt.h>
# include <u8c/intern.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
bool u8c_setfmt(unsigned char const _base,unsigned char const _endian) {
	uint_least8_t base   = _base;
	uint_least8_t endian = _endian;
	if(_base > UINT8_C(0x20)) {
		base = UINT8_C(0xC);
	}
	if(_endian > UINT8_C(0x1)) {
		endian = UINT8_C(0x0);
	}
# if defined(u8c_bethrdsafe)
	mtx_lock(&u8c_dat.fmtlock);
# endif
	u8c_dat.fmtbase   = base;
	u8c_dat.fmtendian = endian;
# if defined(u8c_bethrdsafe)
	mtx_unlock(&u8c_dat.fmtlock);
# endif
	return false;
}
