/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Format type */
# if !defined(u8c_sym_fmttyp)
# define u8c_sym_fmttyp
enum u8c_fmttyp {
	u8c_fmttyp_bgcol,  /* Background colour */
	u8c_fmttyp_bgcol0,  /* Background colour #0 */
	u8c_fmttyp_chr,  /* Character */
	u8c_fmttyp_fgcol,  /* Foreground colour */
	u8c_fmttyp_fgcol0,  /* Foreground colour #0 */
	u8c_fmttyp_int,  /* Integer */
	u8c_fmttyp_str,  /* String */
	u8c_fmttyp_uint, /* Unsigned integer */
};
# endif
