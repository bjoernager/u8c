/*
	Use this program to convert Unicode message into C-arrays.
	Just copy the output and paste it into the source.
*/
# if !defined(__STDC_UTF_32__)
# error UTF-32 support is needed.
# endif
# include <inttypes.h>
# include <stdio.h>
# include <stdlib.h>
# include <u8c/end.h>
# include <u8c/init.h>
# include <u8c/SIZE_C.h>
# include <u8c/u32sz.h>
int main(void) {
	u8c_init();
	size_t           u32sz = SIZE_C(0x0);
	uint_least32_t * u32   = U"u8c_u32sz: Unterminated input."; /* Place string here. */
	u8c_u32sz(&u32sz,u32);
	printf("Arrray:\n{");
	for(size_t n = SIZE_C(0x0);n < u32sz;n += SIZE_C(0x1)) {
		printf("UINT32_C(0x%" PRIXLEAST32 "),",u32[n]);
	}
	printf("}\n");
	u8c_end();
	exit(EXIT_SUCCESS);
}
