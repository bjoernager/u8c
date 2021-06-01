# 10

* Make `u8c_seterr` public.
* Update logo.

# ↋

* Fix `u8c_ver`.
* Add Turkish letters to `u8c_isalpha`.

# ↊

* Add UTF-32 alternatives to some of the functions from `ctypes.h`; `u8c_isalnum`, `u8c_isalpha`, `u8c_iscntrl`, `u8c_isdigit`, `u8c_isspace`, and `u8c_ispunct`.
* Add assertions.
* Create new logo (move old logo to `u8c_old.svg`).

# 9

* Optimisations.
* Remove some optimisations, as they prevent C++ compatibility.
* Fix memory leak in test program.
* Add function for comparing UTF-32 strings; `u8c_u32cmp`.

# 8

* Optimisations.

# 7

* Optimisations.

# 6

* Remove unneeded include directives.
* Update `SIZE_C` to utilise the C++23 `std::size_t` literal suffix (`uz`).
* Fix include guard in `include/u8c/stat.h`.
* Add more error messages.

# 5

* Add logo (`u8c.svg`).
* Fix UTF-8 decoder.
* Update README.

# 4

* Add link to PKGBUILD in README.

# 3

* Remove `include/u8c.h`.
* Fix minor errors.

# 2

* Move PKGBUILD to seperate project.
* Create a *master* header that includes every other header.
* Create `size_t` constant macro.
* Add colour to text formatting.
* Specify what file to print to in `u8c_print`.
* Add C++ compatibility to headers.
* Add functions for initialising and ending *u8c*.
* Add dedicated function for text formatting (altough not working at the moment); `u8c_fmt`.
* Remove `u8c_free`.
* Improve error handling in the form of error messages (which can be retrieved by the programmer via `u8c_geterr`).
* Split `u8c_print` into two functions: `u8c_print` and `u8c_println`.
* Break the UTF-8 decoder somehow.
* Add compile-time option to be thread-safe (requiring C11 threads if enabled).
* Add function for copying UTF-32; `u8c_u32cp`.
* Add function for getting the size of an UTF-32 array; `u8c_u32sz`.
* Add `va_list` alternatives to `u8c_fmt` and `u8c_print`; `u8c_vfmt` and `u8c_vprint`.
* Add test-program (run via `make runtest`).
* Add program to make human-readable UTF-32 strings machine-readable.
* Turn `u8c_ver` into a compile-time macro.
* Enable more warnings when compiling.
* Add assertions.

# 1

* Fix Makefile compiling *u8c.so* instead of *libu8c.so*.
* Add global variable for version control.

# 0

* Fork from *luma*.
