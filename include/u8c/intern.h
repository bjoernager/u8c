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
# if defined(u8c_bethrdsafe) && defined(__STDC_NO_THREADS__)
# error u8c is set to be thread-safe, but the implementation does not support multithreading.
# endif
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <uchar.h>
# include <u8c/err.h>
# if defined(u8c_bethrdsafe)
# include <threads.h>
# endif
/* Enumerations: */
/* Type definitions: */
/* Structures: */
struct u8c_dattyp { /* Data type */
	char32_t const * err;                                     /* Error */
	u8c_errhandltyp  errhandls[(size_t)u8c_errtyp_all]; /* Error handlers */
	uint_least8_t    fmtbase;                                 /* Format base */
	bool             fmtendian;                               /* Format endian */
	uint_least8_t    stat;                                    /* Status */
# if defined(u8c_bethrdsafe)
	mtx_t errhandlslock;                                      /* Error handlers lock */
	mtx_t errlock;                                            /* Error lock */
	mtx_t fmtlock;                                            /* Format lock */
	mtx_t outlock;                                            /* Output lock */
# endif
};
/* Functions: */
/* Constants & Variables: */
extern struct u8c_dattyp u8c_dat; /* Data */
/* Macros: */
# endif
