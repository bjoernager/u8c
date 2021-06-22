/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <inttypes.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdnoreturn.h>
# include <time.h>
# include <u8c/intern.h>
# include <u8c/main.h>
noreturn bool u8c_abrtfn(char const * const _fl,long const _ln,char const * const _fn,char const * const _why) {
	fprintf(stderr,"u8c: *** Aborted (\"%s\":%li in function \"%s\": \"%s\" @ %" PRIuMAX ") ***\nLibrary diagnostics:\n    debug:%s\n    status:%" PRIuLEAST8 "\n    thread-safe:%s\n    version:%" PRIuLEAST64 "\n",_fl,_ln,_fn,_why,(intmax_t)time(NULL),u8c_dbg ? "true" : "false",u8c_dat.stat,u8c_thrdsafe ? "true" : "false",u8c_ver);
	fprintf(stderr,"Trying to clean up...\n");
	u8c_end();
	fprintf(stderr,"Aborting...\n");
	abort();
}
