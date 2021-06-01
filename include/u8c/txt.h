/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
/* Text */
# if !defined(__STDC_UTF_32__)
# error UTF-32 is required to use u8c_txt.
# else
# if !defined(u8c_txt)
# if defined(__cplusplus)
# include <cstdint>
# define u8c_txt(txt) (reinterpret_cast<std::uint_least32_t const *>(U ## txt))
# else
# include <stdint.h>
# define u8c_txt(txt) (uint_least32_t const *)U ## txt
# endif
# endif
# endif
