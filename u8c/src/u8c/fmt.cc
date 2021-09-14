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

#include <cstddef>      /* std::nullptr_t */
#include <string>       /* std::u32string, std::u8string */
#include <u8c/u8c>
#include <u8c/str>

template<> auto u8c::fmt(char32_t const _chr) -> u8c::str {
	return _chr;
}
template<> auto u8c::fmt(std::nullptr_t) -> u8c::str {
	return U"nullptr";
}
template<> auto u8c::fmt(u8c::str const _str) -> u8c::str {
	return _str;
}
template<> auto u8c::fmt(void * _ptr) -> u8c::str {
	if(_ptr == nullptr) [[unlikely]] {
		return U"nullptr";
	}
	return U"PTR";
}
