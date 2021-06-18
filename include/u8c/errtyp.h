/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Error type */
# if !defined(u8c_sym_errtyp)
# define u8c_sym_errtyp
enum u8c_errtyp {
	u8c_errtyp_badalloc,  /* Bad allocation */
	u8c_errtyp_badio,     /* Bad input or output */
	u8c_errtyp_u32oor,    /* UTF-32 out of range */
	u8c_errtyp_u8oor,     /* UTF-8 out of range */
	u8c_errtyp_deferr,    /* Default error */
	u8c_errtyp_untermin,  /* Unterminated input */
	u8c_errtyp_maxerrtyp, /* Maximum error type */
	u8c_errtyp_all,       /* All */
};
# endif
