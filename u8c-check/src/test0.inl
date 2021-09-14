#include <iostream> /* std::cerr, std::endl */
#include <limits>   /* std::numeric_limits */
#include <random>   /* std::random_device, std::uniform_int_distribution */
#include <u8c/arr>

auto test0() -> void {
	std::cerr << "Constructing array of 256 elements, each with a value of 15...";
	u8c::arr<int> arr(0x100uz,0xF);
	u8c_assert(arr.sz() == 0x100uz);
	u8c_assert(static_cast<u8c::size>(arr.end() - arr.begin()) == arr.sz());
	for (auto const elm : arr) {
		u8c_assert(elm == 0xF);
	}
	std::cerr << " okay." << std::endl;
	std::random_device rd;
	{
		std::uniform_int_distribution<int> distr(0x0,std::numeric_limits<int>::max());
		for (u8c::byte n = u8c_bytec(0x0);n <= u8c_bytec(0x10);n += u8c_ubytec(0x1)) {
			auto const val = distr(rd);
			std::cerr << "Filling array with the value of " << val << "...";
			arr.fill(val);
			for (auto const elm : arr) {
				u8c_assert(elm == val);
			}
			std::cerr << " okay." << std::endl;
		}
	}
	{
		std::uniform_int_distribution<u8c::size> distr(0x1,0xFFF);
		for (u8c::byte n = u8c_bytec(0x0);n <= u8c_bytec(0x4);n += u8c_ubytec(0x1)) {
			auto const sz = distr(rd);
			std::cerr << "Allocating the array to the size of " << sz << "...";
			arr.alloc(sz);
			u8c_assert(arr.sz() == sz);
			std::cerr << " okay." << std::endl;
		}
	}
	std::cerr << "Doing some additionel tests...";
	arr.alloc(0x2uz);
	u8c_assert(arr.sz() == 0x2uz);
	arr.fill(0xF);
	u8c_assert(arr[0x0uz] == 0xF);
	u8c_assert(arr[0x1uz] == 0xF);
	arr.realloc(0x4uz);
	u8c_assert(arr.sz() == 0x4uz);
	u8c_assert(arr[0x0uz] == 0xF);
	u8c_assert(arr[0x1uz] == 0xF);
	std::cerr << " okay." << std::endl;
}
