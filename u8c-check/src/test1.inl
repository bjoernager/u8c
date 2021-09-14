#include <cstdint>  /* u8c_uint32c, u8c_ubytec, std::int_fast8_t, u8c::uint32 */
#include <iomanip>  /* std::hex */
#include <iostream> /* std::cout, std::endl */
#include <random>   /* std::random_device */

auto test1() -> void {
	std::random_device rd;
	std::uniform_int_distribution<char32_t> distr(u8c_uint32c(0x0),u8c_uint32c(0x100));
	for(std::int_fast8_t n = u8c_bytec(0x0);n <= u8c_bytec(0x4);n += u8c_ubytec(0x1)) {
		auto const chr = distr(rd);
		std::cout << "U+" << std::hex << static_cast<u8c::uint32>(chr) << " (\"" << u8c::uninm(chr) << "\" @ \"" << u8c::uniblk(chr) << "\")" << std::endl;
		std::cout << "Is alphanumeric:      " << u8c::isalnum(chr) << std::endl;
		std::cout << "Is alphabetic:        " << u8c::isalpha(chr) << std::endl;
		std::cout << "Is control character: " << u8c::iscntrl(chr) << std::endl;
		std::cout << "Is digit:             " << u8c::isdigit(chr) << std::endl;
		std::cout << "Is lowercase:         " << u8c::islower(chr) << std::endl;
		std::cout << "Is punctuation mark:  " << u8c::ispunct(chr) << std::endl;
		std::cout << "Is whitespace:        " << u8c::isspace(chr) << std::endl;
		std::cout << "Is surrogate point:   " << u8c::issurro(chr) << std::endl;
		std::cout << "Is uppercase:         " << u8c::isupper(chr) << std::endl;
		std::cout << "Is hexadecimal digit: " << u8c::isxdigit(chr) << std::endl;
		std::cout << std::endl;
	}
}
