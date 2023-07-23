#include <climits>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <u8c/character.h>
#include <u8c/format.h>

using namespace ::std::literals::string_literals;

int main() {
	int unsigned error_count = 0x0u;

	auto const log_unit = [](::std::string const& identifier) noexcept -> void {
		::std::cerr <<"\n\x1B[38;5;75mtesting\x1B[0m " << identifier <<"\n\n";
	};

	auto const check = [&error_count](long const line, auto const& left_value, auto const& right_value) {
		::std::cerr << " " <<  ::std::setbase(0xA) << line << ". ";

		auto const okay = [](auto const& left_reference, auto const& right_reference) -> bool {
			auto const get_value = [](auto const& reference) -> auto {
				using T = ::std::remove_cv_t<::std::remove_reference_t<decltype (left_value)>>;

				if constexpr (::std::is_same_v<T, char>) {
					return static_cast<::std::uintmax_t>(static_cast<char unsigned>(reference));
				} else if constexpr (::std::is_signed_v<T>) {
					return static_cast<::std::intmax_t>(reference);
				} else if constexpr (::std::is_unsigned_v<T>) {
					return static_cast<::std::uintmax_t>(reference);
				} else {
					return static_cast<T>(reference);
				}
			};

			auto const left_value  = get_value(left_reference);
			auto const right_value = get_value(right_reference);

			::std::cerr << "" << ::std::setbase(0x10) << left_value << " equals " << right_value << "... ";

			return left_value == right_value;
		}(left_value, right_value);

		if (!okay) {
			::std::cerr << "\x1B[38;5;161mfalse\x1B[0m\n";
			++error_count;
		} else {
			::std::cerr <<"\x1B[38;5;77mtrue\x1B[0m\n";
		}
	};
	#define check(left_value, right_value) (check(__LINE__, (left_value), (right_value)))

	::std::cerr << "u8c-check " << u8c_VERSION << "\n";

	[&] {
		log_unit("UTF-8");

		::std::uint_least32_t const source[] {
			UINT32_C(0x0026),
			UINT32_C(0x00F0),
			UINT32_C(0x218A),
			UINT32_C(0x0001F480),
			UINT32_C(0xD800),
			UINT32_C(0x0010FFFF),
			UINT32_C(0x00110000),
		};
		auto const source_length = sizeof (source) / sizeof (source[0x0]);

		size_t const utf8_buffer_length = ::u8c_encode_utf8_length(source, source_length);
		check(utf8_buffer_length, 0x14u);

		auto const utf8_buffer = new char[utf8_buffer_length];

		::u8c_encode_utf8(utf8_buffer, source, source_length);

		check(utf8_buffer[0x00], '\x26');
		check(utf8_buffer[0x01], '\xC3');
		check(utf8_buffer[0x02], '\xB0');
		check(utf8_buffer[0x03], '\xE2');
		check(utf8_buffer[0x04], '\x86');
		check(utf8_buffer[0x05], '\x8A');
		check(utf8_buffer[0x06], '\xF0');
		check(utf8_buffer[0x07], '\x9F');
		check(utf8_buffer[0x08], '\x92');
		check(utf8_buffer[0x09], '\x80');
		check(utf8_buffer[0x0A], '\xEF');
		check(utf8_buffer[0x0B], '\xBF');
		check(utf8_buffer[0x0C], '\xBD');
		check(utf8_buffer[0x0D], '\xF4');
		check(utf8_buffer[0x0E], '\x8F');
		check(utf8_buffer[0x0F], '\xBF');
		check(utf8_buffer[0x10], '\xBF');
		check(utf8_buffer[0x11], '\xEF');
		check(utf8_buffer[0x12], '\xBF');
		check(utf8_buffer[0x13], '\xBD');

		auto const utf32_buffer_length = ::u8c_decode_utf8_length(utf8_buffer, utf8_buffer_length);
		check(utf32_buffer_length, 0x7u);

		auto const utf32_buffer = new ::std::uint_least32_t[utf32_buffer_length];

		::u8c_decode_utf8(utf32_buffer, utf8_buffer, utf8_buffer_length);

		check(utf32_buffer[0x0], UINT32_C(0x0026));
		check(utf32_buffer[0x1], UINT32_C(0x00F0));
		check(utf32_buffer[0x2], UINT32_C(0x218A));
		check(utf32_buffer[0x3], UINT32_C(0x0001F480));
		check(utf32_buffer[0x4], UINT32_C(0xFFFD));

		delete[] utf8_buffer;
		delete[] utf32_buffer;
	}();

	[&] {
		log_unit("UTF-16");

		::std::uint_least32_t const source[] {
			UINT32_C(0x0026),
			UINT32_C(0x00F0),
			UINT32_C(0x218A),
			UINT32_C(0x0001F480),
			UINT32_C(0xD800),
			UINT32_C(0x0010FFFF),
			UINT32_C(0x00110000),
		};
		auto const source_length = sizeof (source) / sizeof (source[0x0]);

		auto const utf16_buffer_length = ::u8c_encode_utf16_length(source, source_length);
		check(utf16_buffer_length, 0x9u);

		auto const utf16_buffer = new ::std::uint_least16_t[utf16_buffer_length];

		::u8c_encode_utf16(utf16_buffer, source, source_length);

		check(utf16_buffer[0x0], UINT16_C(0x0026));
		check(utf16_buffer[0x1], UINT16_C(0x00F0));
		check(utf16_buffer[0x2], UINT16_C(0x218A));
		check(utf16_buffer[0x3], UINT16_C(0xD83D));
		check(utf16_buffer[0x4], UINT16_C(0xDC80));
		check(utf16_buffer[0x5], UINT16_C(0xFFFD));
		check(utf16_buffer[0x6], UINT16_C(0xDBFF));
		check(utf16_buffer[0x7], UINT16_C(0xDFFF));
		check(utf16_buffer[0x8], UINT16_C(0xFFFD));

		auto const utf32_buffer_length = ::u8c_decode_utf16_length(utf16_buffer, utf16_buffer_length);
		check(utf32_buffer_length, 0x7u);

		auto const utf32_buffer = new ::std::uint_least32_t[utf32_buffer_length];

		::u8c_decode_utf16(utf32_buffer, utf16_buffer, utf16_buffer_length);

		check(utf32_buffer[0x0], UINT32_C(0x0026));
		check(utf32_buffer[0x1], UINT32_C(0x00F0));
		check(utf32_buffer[0x2], UINT32_C(0x218A));
		check(utf32_buffer[0x3], UINT32_C(0x0001F480));
		check(utf32_buffer[0x4], UINT32_C(0xFFFD));
		check(utf32_buffer[0x5], UINT32_C(0x0010FFFF));
		check(utf32_buffer[0x6], UINT32_C(0xFFFD));

		delete[] utf16_buffer;
		delete[] utf32_buffer;
	}();

	::std::cerr << "\ndone - " << error_count << " error(s)\n";

	return error_count != 0x0u ? EXIT_FAILURE : EXIT_SUCCESS;
}