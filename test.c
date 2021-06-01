# include <inttypes.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <u8c/col.h>
# include <u8c/dbgprint.h>
# include <u8c/debug.h>
# include <u8c/end.h>
# include <u8c/fmt.h>
# include <u8c/fmttyp.h>
# include <u8c/freeu32.h>
# include <u8c/freeu8.h>
# include <u8c/geterr.h>
# include <u8c/init.h>
# include <u8c/isalnum.h>
# include <u8c/isalpha.h>
# include <u8c/iscntrl.h>
# include <u8c/isdigit.h>
# include <u8c/ispunct.h>
# include <u8c/isspace.h>
# include <u8c/print.h>
# include <u8c/println.h>
# include <u8c/seterr.h>
# include <u8c/SIZE_C.h>
# include <u8c/thrdsafe.h>
# include <u8c/u32cmp.h>
# include <u8c/u32cp.h>
# include <u8c/u32sz.h>
# include <u8c/u8dec.h>
# include <u8c/u8enc.h>
# include <u8c/ver.h>
# include <u8c/vfmt.h>
# include <u8c/vprint.h>
# if defined(__STDC_UTF_32__)
# include <u8c/txt.h>
# endif
static void testmsg(char const * fmt,...) {
	va_list args;
	va_start(args,fmt);
	printf("\n+->\n| \x1b[38:2::169:225:61mTesting\x1b[0m \"");
	vprintf(fmt,args);
	printf("\"...\n+->\n\n");
	va_end(args);
}
static void testmsgdone(uint_least32_t * num0,uint_least8_t * num1) {
	*num0 += (uint_least32_t)(*num1);
	printf("\n+->\n| \x1b[38:2::61:225:169mDone\x1b[0m! (\x1b[38:2::225:61:61mErrors\x1b[0m: %" PRIuLEAST32 ")\n+->\n",*num1);
	*num1 = UINT8_C(0x0);
}
int main(void) {
	u8c_init();
	printf("u8c version: %" PRIXLEAST64 ".\n",u8c_ver);
	printf("Debug build: %" PRIXLEAST8 ".\n",u8c_debug);
	printf("Thread safe: %" PRIXLEAST8 ".\n",u8c_thrdsafe);
	uint_least32_t errcount0 = UINT32_C(0x0);
	uint_least8_t  errcount1 = UINT8_C(0x0);
	testmsg("Error messages");
	{
		uint_least32_t const * err = NULL;
		errcount1 += u8c_geterr(NULL,&err);
		errcount1 += u8c_println(stdout,err);
		u8c_freeu32(err);
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("UTF-8 encoding/decoding");
	{
		uint_least32_t const * msg0 = (uint_least32_t[]){UINT32_C(0xA2),UINT32_C(0x2C),UINT32_C(0x939),UINT32_C(0x2C),UINT32_C(0x10348),UINT32_C(0x2C),UINT32_C(0x20AC),UINT32_C(0x2C),UINT32_C(0x218A),UINT32_C(0x2C),UINT32_C(0x1F44B),UINT32_C(0x0)};
		uint_least8_t const *  msg1 = NULL;
		errcount1 += u8c_u8enc(NULL,&msg1,msg0);
		printf("Encoded:                       %s\n",msg1);
		errcount1 += u8c_u8dec(NULL,&msg0,msg1);
		u8c_freeu8(msg1);
		errcount1 += u8c_u8enc(NULL,&msg1,msg0);
		printf("Encoded -> Decoded -> Encoded: %s\n",msg1);
		u8c_freeu32(msg0);
		u8c_freeu8(msg1);
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("Printing (u8c_print)");
	{
		errcount1 += u8c_print(stdout,(uint_least32_t[]){UINT32_C(0x48),UINT32_C(0x65),UINT32_C(0x6C),UINT32_C(0x6C),UINT32_C(0x6F),UINT32_C(0x0),});
		errcount1 += u8c_print(stdout,(uint_least32_t[]){UINT32_C(0x20),UINT32_C(0xF0),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x65),UINT32_C(0x21),UINT32_C(0xA),UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("Printing (u8c_println)");
	{
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x48),UINT32_C(0x65),UINT32_C(0x6C),UINT32_C(0x6C),UINT32_C(0x6F),UINT32_C(0x0),});
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x20),UINT32_C(0xF0),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0x65),UINT32_C(0x21),UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("Text formatting");
	{
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x54),UINT32_C(0x68),UINT32_C(0x65),UINT32_C(0x20),UINT32_C(0xFFFD),UINT32_C(0x6E),UINT32_C(0x75),UINT32_C(0x6D),UINT32_C(0x62),UINT32_C(0x65),UINT32_C(0x72),UINT32_C(0xFFFD),UINT32_C(0x20),UINT32_C(0x69),UINT32_C(0x73),UINT32_C(0x20),UINT32_C(0xFFFD),UINT32_C(0x2E),UINT32_C(0x0),},u8c_fmttyp_fgcol,u8c_col_mint,u8c_fmttyp_fgcol0,u8c_fmttyp_int,(int_least64_t){-0x10});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("Colour text");
	{
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0xFFFD),UINT32_C(0x72),UINT32_C(0x65),UINT32_C(0x64),UINT32_C(0xFFFD),UINT32_C(0x6F),UINT32_C(0x72),UINT32_C(0x61),UINT32_C(0x6E),UINT32_C(0x67),UINT32_C(0x65),UINT32_C(0xFFFD),UINT32_C(0x79),UINT32_C(0x65),UINT32_C(0x6C),UINT32_C(0x6C),UINT32_C(0x6F),UINT32_C(0x77),UINT32_C(0xFFFD),UINT32_C(0x63),UINT32_C(0x68),UINT32_C(0x61),UINT32_C(0x72),UINT32_C(0x74),UINT32_C(0x72),UINT32_C(0x65),UINT32_C(0x75),UINT32_C(0x73),UINT32_C(0x65),UINT32_C(0xFFFD),UINT32_C(0x67),UINT32_C(0x72),UINT32_C(0x65),UINT32_C(0x65),UINT32_C(0x6E),UINT32_C(0xFFFD),UINT32_C(0x6D),UINT32_C(0x69),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0xFFFD),UINT32_C(0x63),UINT32_C(0x79),UINT32_C(0x61),UINT32_C(0x6E),UINT32_C(0xFFFD),UINT32_C(0x61),UINT32_C(0x7A),UINT32_C(0x75),UINT32_C(0x72),UINT32_C(0x65),UINT32_C(0xFFFD),UINT32_C(0x62),UINT32_C(0x6C),UINT32_C(0x75),UINT32_C(0x65),UINT32_C(0xFFFD),UINT32_C(0x76),UINT32_C(0x69),UINT32_C(0x6F),UINT32_C(0x6C),UINT32_C(0x65),UINT32_C(0x74),UINT32_C(0xFFFD),UINT32_C(0x6D),UINT32_C(0x61),UINT32_C(0x67),UINT32_C(0x65),UINT32_C(0x6E),UINT32_C(0x74),UINT32_C(0x61),UINT32_C(0xFFFD),UINT32_C(0x72),UINT32_C(0x6F),UINT32_C(0x73),UINT32_C(0x65),UINT32_C(0xFFFD),UINT32_C(0x0),},u8c_fmttyp_fgcol,u8c_col_red,u8c_fmttyp_fgcol,u8c_col_orange,u8c_fmttyp_fgcol,u8c_col_yellow,u8c_fmttyp_fgcol,u8c_col_chartreuse,u8c_fmttyp_fgcol,u8c_col_green,u8c_fmttyp_fgcol,u8c_col_mint,u8c_fmttyp_fgcol,u8c_col_cyan,u8c_fmttyp_fgcol,u8c_col_azure,u8c_fmttyp_fgcol,u8c_col_blue,u8c_fmttyp_fgcol,u8c_col_violet,u8c_fmttyp_fgcol,u8c_col_magenta,u8c_fmttyp_fgcol,u8c_col_rose,u8c_fmttyp_fgcol0);
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("Combining characters");
	{
		for(register uint_least32_t n = UINT32_C(0x300);n <= UINT32_C(0x36F);n += UINT32_C(0x1)) {
			errcount1 += u8c_print(stdout,(uint_least32_t[]){UINT32_C(0x41),n,UINT32_C(0x20),UINT32_C(0x0),});
			fflush(stdout);
		}
		errcount1 += u8c_print(stdout,(uint_least32_t[]){UINT32_C(0xA),UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("String comparison (UTF-32)");
	{
		uint_least32_t const * str0 = (uint_least32_t[]){UINT32_C(0x48),UINT32_C(0x65),UINT32_C(0x6C),UINT32_C(0x6C),UINT32_C(0x6F),UINT32_C(0x0),};
		uint_least32_t const * str1 = (uint_least32_t[]){UINT32_C(0x48),UINT32_C(0x65),UINT32_C(0x6C),UINT32_C(0x6C),UINT32_C(0x6F),UINT32_C(0x0),};
		uint_least32_t const * str2 = (uint_least32_t[]){UINT32_C(0x47),UINT32_C(0x6F),UINT32_C(0x6F),UINT32_C(0x64),UINT32_C(0x62),UINT32_C(0x79),UINT32_C(0x65),UINT32_C(0x0),};
		printf("str0: ");
		u8c_println(stdout,str0);
		printf("str1: ");
		u8c_println(stdout,str1);
		printf("str2: ");
		u8c_println(stdout,str2);
		uint_least8_t res = UINT8_C(0x0);
		errcount1 += u8c_u32cmp(&res,str0,str1);
		printf("str0,str1: %" PRIXLEAST8 ".\n",res);
		errcount1 += u8c_u32cmp(&res,str1,str2);
		printf("str0,str2: %" PRIXLEAST8 ".\n",res);
		errcount1 += u8c_u32cmp(&res,str2,str1);
		printf("str2,str1: %" PRIXLEAST8 ".\n",res);
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("u8c_isalnum");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			errcount1 += u8c_isalnum(&res,n);
			if(res) {
				errcount1 += u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("u8c_isalpha");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			errcount1 += u8c_isalpha(&res,n);
			if(res) {
				errcount1 += u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("u8c_isdigit");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			errcount1 += u8c_isdigit(&res,n);
			if(res) {
				errcount1 += u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
	testmsg("u8c_ispunct"); /* This test appears broken on some fonts. */
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			errcount1 += u8c_ispunct(&res,n);
			if(res) {
				errcount1 += u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		errcount1 += u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x0),});
	}
	testmsgdone(&errcount0,&errcount1);
# if defined(__STDC_UTF_32__)
	testmsg("UTF-32 string literals");
	{
		u8c_println(stdout,u8c_txt("Can you see this?"));
	}
	testmsgdone(&errcount0,&errcount1);
# endif
	printf("\n");
	printf("Test done!\n");
	printf("Total number of errors: %" PRIuLEAST32 ".\n",errcount0);
	u8c_end();
	exit(EXIT_SUCCESS);
}
