/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Debug print */
# if !defined(u8c_dbgprint)
# if defined(NDEBUG)
# if defined(__cplusplus)
# define u8c_dbgprint(...) (static_cast<void>(0x0));
# else
# define u8c_dbgprint(...) ((void)0x0)
# endif
# else
# include <u8c/println.h>
# include <stdio.h>
# define u8c_dbgprint(...) u8c_println(stderr,__VA_ARGS__)
# endif
# endif
