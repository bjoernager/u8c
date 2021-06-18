# include <inttypes.h>
# include <setjmp.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <u8c/SIZE_C.h>
# include <u8c/abrt.h>
# include <u8c/col.h>
# include <u8c/dbgprint.h>
# include <u8c/dbg.h>
# include <u8c/end.h>
# include <u8c/fmt.h>
# include <u8c/fmttyp.h>
# include <u8c/geterr.h>
# include <u8c/init.h>
# include <u8c/isalnum.h>
# include <u8c/isalpha.h>
# include <u8c/iscntrl.h>
# include <u8c/isdigit.h>
# include <u8c/isxdigit.h>
# include <u8c/ispunct.h>
# include <u8c/isspace.h>
# include <u8c/print.h>
# include <u8c/println.h>
# include <u8c/regerrhandl.h>
# include <u8c/seterr.h>
# include <u8c/setfmt.h>
# include <u8c/thrdsafe.h>
# include <u8c/u32cat.h>
# include <u8c/u32cmp.h>
# include <u8c/u32cp.h>
# include <u8c/u32fndchr.h>
# include <u8c/u32fndpat.h>
# include <u8c/u32free.h>
# include <u8c/u32ins.h>
# include <u8c/u32substr.h>
# include <u8c/u32sz.h>
# include <u8c/u8dec.h>
# include <u8c/u8enc.h>
# include <u8c/u8free.h>
# include <u8c/ver.h>
# include <u8c/vfmt.h>
# include <u8c/vprint.h>
static void testmsg(char const * fmt,...) {
	va_list args;
	va_start(args,fmt);
	/* printf("\n+->\n| \x1b[38:2:169:225:61mTesting\x1b[0m \""); */  /* This command works in all of the terminals I tested, except Konsole (whic is funny, because it's xterm-based, and xterm supports it). */
	printf("\n+->\n| \x1b[38;2;169;225;61mTesting\x1b[0m \"");
	vprintf(fmt,args);
	printf("\"...\n+->\n\n");
	va_end(args);
}
static void testmsgdone() {
	/* printf("\n+->\n| \x1b[38:2::61:225:169mDone\x1b[0m!\n+->\n"); */
	printf("\n+->\n| \x1b[38;2;61;225;169mDone\x1b[0m!\n+->\n");
}
static void errhandl(enum u8c_errtyp errtyp) {
	printf(":: Error handler called with type %d.\n",(int)errtyp);
}
int main(void) {
	if(u8c_init()) {
		printf("Unable to initialise u8c!\n");
		exit(EXIT_FAILURE);
	}
	u8c_regerrhandl(u8c_errtyp_all,errhandl);
	u8c_setfmt(UINT8_C(0xC),UINT8_C(0x1));
	printf("u8c version: %" PRIXLEAST64 ".\n",u8c_ver);
	printf("Debug build: %" PRIXLEAST8 ".\n",u8c_dbg);
	printf("Thread safe: %" PRIXLEAST8 ".\n",u8c_thrdsafe);
	testmsg("Error messages");
	{
		char32_t const * err = NULL;
		u8c_geterr(NULL,&err);
		printf("default error message: ");
		u8c_println(stdout,err);
		u8c_seterr(U"Gluchwein!",u8c_errtyp_deferr);
		u8c_geterr(NULL,&err);
		printf("set error message:     ");
		u8c_println(stdout,err);
		u8c_u32free(&err);
	}
	testmsgdone();
	testmsg("UTF-8 encoding/decoding");
	{
		char32_t const * msg0 = U"¢,ह,𐍈,€,↊,👋";
		unsigned char const *  msg1 = NULL;
		u8c_u8enc(NULL,&msg1,msg0);
		msg0 = NULL;
		printf("Encoded:                       %s\n",msg1);
		u8c_u8dec(NULL,&msg0,msg1);
		u8c_u8enc(NULL,&msg1,msg0);
		printf("Encoded -> Decoded -> Encoded: %s\n",msg1);
		u8c_u32free(&msg0);
		u8c_u8free(&msg1);
	}
	testmsgdone();
	testmsg("Printing (u8c_print)");
	{
		u8c_print(stdout,U"Hello");
		u8c_print(stdout,U" ðere!");
	}
	testmsgdone();
	testmsg("Printing (u8c_println)");
	{
		u8c_println(stdout,U"Hello");
		u8c_println(stdout,U" ðere!");
	}
	testmsgdone();
	testmsg("Text formatting");
	{
		u8c_println(stdout,U"The ￼number￼ is ￼.",u8c_fmttyp_fgcol,u8c_col_mint,u8c_fmttyp_fgcol0,u8c_fmttyp_int,(int_least64_t){-0x10});
	}
	testmsgdone();
	testmsg("Colour text");
	{
		u8c_println(stdout,U"￼red￼orange￼yellow￼chartreuse￼green￼mint￼cyan￼azure￼blue￼violet￼magenta￼rose￼",u8c_fmttyp_fgcol,u8c_col_red,u8c_fmttyp_fgcol,u8c_col_orange,u8c_fmttyp_fgcol,u8c_col_yellow,u8c_fmttyp_fgcol,u8c_col_chartreuse,u8c_fmttyp_fgcol,u8c_col_green,u8c_fmttyp_fgcol,u8c_col_mint,u8c_fmttyp_fgcol,u8c_col_cyan,u8c_fmttyp_fgcol,u8c_col_azure,u8c_fmttyp_fgcol,u8c_col_blue,u8c_fmttyp_fgcol,u8c_col_violet,u8c_fmttyp_fgcol,u8c_col_magenta,u8c_fmttyp_fgcol,u8c_col_rose,u8c_fmttyp_fgcol0);
	}
	testmsgdone();
	testmsg("Combining characters");
	{
		for(register uint_least32_t n = UINT32_C(0x300);n <= UINT32_C(0x36F);n += UINT32_C(0x1)) {
			u8c_print(stdout,(uint_least32_t[]){UINT32_C(0x61),n,UINT32_C(0x20),UINT32_C(0x0),});
			fflush(stdout);
		}
		u8c_print(stdout,U"\n");
	}
	testmsgdone();
	testmsg("String comparison");
	{
		char32_t const * str0 = U"Hello";
		char32_t const * str1 = U"Hello";
		char32_t const * str2 = U"Goodbye";
		printf("str0: ");
		u8c_println(stdout,str0);
		printf("str1: ");
		u8c_println(stdout,str1);
		printf("str2: ");
		u8c_println(stdout,str2);
		uint_least8_t res = UINT8_C(0x0);
		u8c_u32cmp(&res,str0,str1);
		printf("str0,str1: %" PRIXLEAST8 ".\n",res);
		u8c_u32cmp(&res,str1,str2);
		printf("str0,str2: %" PRIXLEAST8 ".\n",res);
		u8c_u32cmp(&res,str2,str1);
		printf("str2,str1: %" PRIXLEAST8 ".\n",res);
	}
	testmsgdone();
	testmsg("u8c_isalnum");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			u8c_isalnum(&res,n);
			if(res) {
				u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		u8c_println(stdout,U"");
	}
	testmsgdone();
	testmsg("u8c_isalpha");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			u8c_isalpha(&res,n);
			if(res) {
				u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		u8c_println(stdout,U"");
	}
	testmsgdone();
	testmsg("u8c_isdigit");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			u8c_isdigit(&res,n);
			if(res) {
				u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		u8c_println(stdout,U"");
	}
	testmsgdone();
	testmsg("u8c_ispunct"); /* This test appears broken on some incomplete fonts, altough it is not. */
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			u8c_ispunct(&res,n);
			if(res) {
				u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		u8c_println(stdout,U"");
	}
	testmsgdone();
	testmsg("UTF-32 string literals");
	{
		u8c_println(stdout,U"Can you see ðis?");
	}
	testmsgdone();
	testmsg("string concatenation");
	{
		char32_t const * str0 = U"Free_as_in";
		char32_t const * str1 = U"_freedom!";
		char32_t const * str2 = NULL;
		u8c_u32cat(NULL,&str2,str0,str1);
		printf("string #0: ");
		u8c_println(stdout,str0);
		printf("string #1: ");
		u8c_println(stdout,str1);
		printf("string #2: ");
		u8c_println(stdout,str2);
		u8c_u32free(&str2);

	}
	testmsgdone();
	testmsg("sub-strings");
	{
		char32_t const * str0 = U"I_wish_to_suck_big_duck.";
		char32_t const * str1 = NULL;
		u8c_u32substr(&str1,SIZE_C(0x0),SIZE_C(0xE),str0);
		char32_t const * str2 = NULL;
		u8c_u32substr(&str2,SIZE_C(0xF),SIZE_C(0x0),str0);
		printf("string #0: ");
		u8c_println(stdout,str0);
		printf("string #1: ");
		u8c_println(stdout,str1);
		printf("string #2: ");
		u8c_println(stdout,str2);
		u8c_u32free(&str1);
		u8c_u32free(&str2);
	}
	testmsgdone();
	testmsg("u8c_isxdigit");
	{
		for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
			uint_least8_t res = UINT8_C(0x0);
			u8c_isxdigit(&res,n);
			if(res) {
				u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
			}
		}
		u8c_println(stdout,(uint_least32_t[]){UINT32_C(0x0),});
	}
	testmsgdone();
	testmsg("Printing (u8c_dbgprint)");
	{
		u8c_dbgprint(U"Hello");
		u8c_dbgprint(U" ðere!");
	}
	testmsgdone();
	testmsg("u8c_u32fndchr");
	{
		char32_t const * str  = U"Proprietary as in Microsoft.";
		size_t                 pos0 = SIZE_C(0x0);
		size_t                 pos1 = SIZE_C(0x0);
		u8c_u32fndchr(&pos0,str,U'M');
		u8c_u32fndchr(&pos1,str,U'ŋ');
		printf("string: ");
		u8c_println(stdout,str);
		printf("Position of 'M': %zu\n",pos0);
		printf("Position of 'ŋ': %zu\n",pos1);
	}
	testmsgdone();
	testmsg("u8c_u32fndpat");
	{
		char32_t const * str  = U"Proprietary as in Microsoft.";
		size_t                 pos0 = SIZE_C(0x0);
		size_t                 pos1 = SIZE_C(0x0);
		u8c_u32fndpat(&pos0,str,U"as in");
		u8c_u32fndpat(&pos1,str,U"forever");
		printf("string: ");
		u8c_println(stdout,str);
		printf("Position of \"as in\": %zu\n",pos0);
		printf("Position of \"forever\": %zu\n",pos1);
	}
	testmsgdone();
	testmsg("string insertion");
	{
		char32_t const * str0 = U"There_is_I_love.";
		char32_t const * str1 = U"just_somebody_that_";
		char32_t const * str2 = NULL;
		u8c_u32ins(NULL,&str2,SIZE_C(0x9),str0,str1);
		printf("String #0: ");
		u8c_println(stdout,str0);
		printf("String #1: ");
		u8c_println(stdout,str1);
		printf("String #2: ");
		u8c_println(stdout,str2);
		u8c_u32free(&str2);
	}
	testmsgdone();
	u8c_end();
	exit(EXIT_SUCCESS);
}
