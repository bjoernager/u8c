/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the
	terms of the GNU Affero General Public License as published by the Free
	Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
	License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with u8c. If not, see <https://www.gnu.org/licenses/>.
*/

#include <algorithm>     /* std::copy */
#include <cstdint>       /* u8c_ubytec */
#include <ostream>       /* std::ostream */
#include <u8c/str>

auto u8c::operator << (std::ostream & _strm,u8c::str const & _str) -> std::ostream & {
	auto const u8 = _str.u8().app(u8'\u0000');
	return _strm << reinterpret_cast<unsigned char *>(u8.begin());
}
