#if defined(NDEBUG)
#undef NDEBUG
#endif

#include <chrono>   /* std::chrono::duration, std::chrono::high_resolution_clock */
#include <cstdlib>  /* EXIT_FAILURE, EXIT_SUCCESS, std::exit */
#include <cstring>  /* std::strcmp */
#include <iostream> /* std::cerr, std::cout, std::endl */
#include <limits>   /* std::numeric_limits */
#include <u8c/u8c>

# include "test0.inl"
# include "test1.inl"

static_assert(u8c::abs(-0x1) == 0x1);
static_assert(u8c::abs(-0x1p0) == 0x1p0);
static_assert(u8c::abs(-0x100p0) == 0x100p0);

static_assert(u8c::fma(0x10,0x10,0x100) == 0x200);

static_assert(!u8c::isinf(0x0));
static_assert(u8c::isinf(std::numeric_limits<float>::infinity()));

static_assert(!u8c::isnan(0x0));
static_assert(u8c::isnan(std::numeric_limits<float>::quiet_NaN()));

static_assert(u8c::isprime(0x2u));
static_assert(u8c::isprime(0x3u));
static_assert(!u8c::isprime(0x4u));
static_assert(u8c::isprime(0x5u));
static_assert(!u8c::isprime(0x6u));
static_assert(u8c::isprime(0x7u));
static_assert(!u8c::isprime(0x8u));
static_assert(!u8c::isprime(0x9u));
static_assert(!u8c::isprime(0xAu));
static_assert(u8c::isprime(0xBu));
static_assert(!u8c::isprime(0xCu));
static_assert(u8c::isprime(0xDu));
static_assert(!u8c::isprime(0xEu));
static_assert(!u8c::isprime(0xFu));

static_assert(u8c::pow(0x1,0x10000) == 0x1);
static_assert(u8c::pow(0x2,0x2) == 0x4);
static_assert(u8c::pow(0x2,0x4) == 0x10);
static_assert(u8c::pow(0x2,0x10) == 0x10000);
static_assert(u8c::pow(0x3,0x3) == 0x1B);

static_assert(u8c::quota(0x1,0x3) < u8c::quota<>::inf());
static_assert(u8c::quota(0x1,0x3) == u8c::quota(0x2,0x6));
static_assert(u8c::quota<>::inf() == u8c::quota<>::inf());
static_assert(u8c::quota<>::nan() != u8c::quota<>::nan());

static_assert(u8c::cstrlen("This is a string!") == 0x11uz);
static_assert(u8c::cstrlen("Das war ein Befehl!") == 0x13uz);

static_assert(u8c::cstrcmp("Clang","Clang") == u8c_bytec(0x0));
static_assert(u8c::cstrcmp("Clang","GCC") == u8c_bytec(0x1));
static_assert(u8c::cstrcmp("GCC","Clang") == u8c_bytec(-0x1));
static_assert(u8c::cstrcmp("GCC","GCC") == u8c_bytec(0x0));

auto main(int const argc,char const * const * const argv) -> int {
	int constexpr maxtestn = 0x1;
	auto gettestnm = [](int const _n) {
		switch (_n) {
		[[unlikely]] default:
			return "N/A";
		case 0x0:
			return "Array Stress-testing";
		case 0x1:
			return "Strings";
		}
	};
	auto helpscrn = [&](char const * const _prognm) {
		std::cout << "u8c-test: Test u8c" << std::endl;
		std::cout << "Usage: " << _prognm << " [test number]" << std::endl;
		std::cout << std::endl;
		std::cout << "Test numbers:" << std::endl;
		for (int n = 0x0;n <= maxtestn;n += 0x1) {
			std::cout << "\t " << n << " - \"" << gettestnm(n) << "\"" << std::endl;
		}
		std::cout << std::endl;
			std::cout << "u8c version: " << u8c::ver << std::endl;
	};
	auto test = [&](int const _n) {
		auto const testnm = gettestnm(_n);
		std::cout << ":: \u001B[95mTesting\u001B[0m test #" << _n << " \u001B[3m\"" << testnm << "\"\u001B[0m..." << std::endl << std::endl;
		auto begin = std::chrono::high_resolution_clock::now();
		switch (_n) {
		[[unlikely]] default:
			std::exit(EXIT_FAILURE);
		case 0x0:
			::test0();
			break;
		case 0x1:
			::test1();
			break;
		}
		auto const                          end    = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> const tmdiff = end - begin;
		std::cout << std::endl << ":: \u001B[96mDone\u001B[0m testing test #" << _n << " \u001B[3m\"" << testnm << "\"\u001B[0m (took " << tmdiff.count() << " seconds)." << std::endl;
	};
	if (argc > 0x1) {
		if (!std::strcmp(argv[0x1uz],"--help")) {
			helpscrn(argv[0x0uz]);
			std::exit(EXIT_SUCCESS);
		}
		else {
			std::cerr << "Invalid argument \"\u001B[3m" << argv[0x1uz] << "\"\u001B[0m." << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	for (int n = 0x0;n <= maxtestn;n += 0x1) {
		test(n);
	}
	std::exit(EXIT_SUCCESS);
}
