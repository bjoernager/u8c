cmake_minimum_required(
	VERSION
	3.20
)
project(
	u8c
	VERSION
	27
	DESCRIPTION
	"Unicode manipulation library."
	HOMEPAGE_URL
	"https://mandelbrot.dk/delta/u8c"
	LANGUAGES
	CXX
)
set(
	CMAKE_CXX_STANDARD
	23
)
set(
	CMAKE_CXX_EXTENSIONS
	OFF
)

# Options:
option(
	U8C_TEST
	"Build test program."
	OFF
)

# Disable in-souce builds:
if(
	"${PROJECT_BINARY_DIR}"
	STREQUAL
	"${PROJECT_SOURCE_DIR}"
)
   message(
	   FATAL_ERROR
	   "In-source building is not allowed."
	)
endif()

# Compiler Settings:
message(
	STATUS
	"Enabling colour output for Clang or GCC..."
)
if(
	"${CMAKE_CXX_COMPILER_ID}"
	STREQUAL
	"Clang"
)
	add_compile_options(
		"-fcolor-diagnostics"
	)
elseif(
	"${CMAKE_CXX_COMPILER_ID}"
	STREQUAL
	"GNU"
)
	add_compile_options (
		"-fdiagnostics-color=always"
	)
endif()
message(
	STATUS
	"Enabling compile warnings..."
)
if(
	MSVC
)
	add_compile_options(
		"/W4"
		"/WX"
	)
else()
	add_compile_options(
		"-Wfatal-errors"
		"-Wall"
		"-Werror"
		"-Wextra"
		"-Wno-attributes"
		"-pedantic-errors"
	)
endif()
if(
	CMAKE_BUILD_TYPE
	MATCHES
	Release
)
	message(
		STATUS
		"Setting optimisation level..."
	)
	if(
		MSVC
	)
		add_compile_options(
			"/Os"
		)
	else()
		add_compile_options(
			"-Os"
		)
	endif()
endif()
include_directories(
	"${PROJECT_SOURCE_DIR}/u8c/include"
)

# u8c settings:
add_library(
	u8c
	SHARED
	"u8c/src/operator.cc"
	"u8c/src/u8c/fmt.cc"
	"u8c/src/u8c/print.cc"
	"u8c/src/u8c/println.cc"
)

# Test settings:
if(
	U8C_TEST
)
	add_executable(
		test
		"u8c-check/src/test.cc"
	)
	add_dependencies(
		test
		u8c
	)
	target_link_libraries(
		test
		u8c
	)
endif()
