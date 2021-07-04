# include <inttypes.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <u8c/SIZE_C.h>
# include <u8c/chk.h>
# include <u8c/err.h>
# include <u8c/fmt.h>
# include <u8c/main.h>
# include <u8c/str.h>
# include <u8c/u8.h>
static void         errhandl(enum u8c_errtyp errtyp);
static int          hlpscrn( char const * const restrict nm);
static void         test(    int n);
static char const * testnm(  int n);
static const int maxtest = 0x17;
static void errhandl(enum u8c_errtyp errtyp) {
	printf(":: Error handler called with type %d.\n",(int)errtyp);
}
static int hlpscrn(char const * const restrict nm) {
	printf("u8c-test: Test u8c\n");
	printf("Usage: %s [test number]\n",nm);
	printf("\n");
	printf("Test numbers:\n");
	for(int n = 0x0;n <= maxtest;n += 0x1) {
		printf("\t %i - \"%s\"\n",n,testnm(n));
	}
	printf("\n");
	return EXIT_SUCCESS;
}
static void test(int n) {
	char const * const restrict _testnm = testnm(n);
	/* printf("\n+->\n| \x1b[38:2::169:225:61mTesting\x1b[0m \""%s"\"...\n+->\n\n",_testnm); */ /* This command works in all of the terminals I tested, except Konsole (whic is funny, because it's xterm-based (and sets the TERM and COLORTERM environemnt variable to "xterm-256color" and "truecolor"), and xterm supports it). */
	printf("\n+->\n| \x1b[38;2;169;225;61mTesting\x1b[0m #%i \"%s\"...\n+->\n\n",n,_testnm);
	switch(n) {
	case 0x0:
		{
			char32_t const * err = u8c_geterr().err;
			printf("default error message: ");
			u8c_println(stdout,err);
			u8c_seterr(u8c_errtyp_deferr,U"Gluchwein!");
			u8c_strfree(err);
			err = u8c_geterr().err;
			printf("set error message:     ");
			u8c_println(stdout,err);
			u8c_strfree(err);
		}
		break;
	case 0x1:
		{
			char32_t const *      msg0 = U"¢,ह,𐍈,€,↊,👋";
			unsigned char const * msg1 = u8c_u8enc(msg0).u8;
			printf("Encoded:                       %s\n",msg1);
			u8c_u8free(msg1);
			msg0 = u8c_u8dec(msg1).str;
			msg1 = u8c_u8enc(msg0).u8;
			printf("Encoded -> Decoded -> Encoded: %s\n",msg1);
			u8c_strfree(msg0);
			u8c_u8free(msg1);
		}
		break;
	case 0x2:
		{
			u8c_print(stdout,U"Hello");
			u8c_print(stdout,U" ðere!\n");
		}
		break;
	case 0x3:
		{
			u8c_println(stdout,U"Hello");
			u8c_println(stdout,U" ðere!");
		}
		break;
	case 0x4:
		{
			u8c_println(stdout,U"The \uFFFCnumber\uFFFC is \uFFFC.",u8c_fmttyp_fgcol,u8c_col_mint,u8c_fmttyp_fgcol0,u8c_fmttyp_int,(int_least64_t){-0x10});
		}
		break;
	case 0x5:
		{
			u8c_println(stdout,U"\uFFFCred\uFFFCorange\uFFFCyellow\uFFFCchartreuse\uFFFCgreen\uFFFCmint\uFFFCcyan\uFFFCazure\uFFFCblue\uFFFCviolet\uFFFCmagenta\uFFFCrose\uFFFC",u8c_fmttyp_fgcol,u8c_col_red,u8c_fmttyp_fgcol,u8c_col_orange,u8c_fmttyp_fgcol,u8c_col_yellow,u8c_fmttyp_fgcol,u8c_col_chartreuse,u8c_fmttyp_fgcol,u8c_col_green,u8c_fmttyp_fgcol,u8c_col_mint,u8c_fmttyp_fgcol,u8c_col_cyan,u8c_fmttyp_fgcol,u8c_col_azure,u8c_fmttyp_fgcol,u8c_col_blue,u8c_fmttyp_fgcol,u8c_col_violet,u8c_fmttyp_fgcol,u8c_col_magenta,u8c_fmttyp_fgcol,u8c_col_rose,u8c_fmttyp_fgcol0);
		}
		break;
	case 0x6:
		{
			for(register uint_least32_t n = UINT32_C(0x300);n <= UINT32_C(0x36F);n += UINT32_C(0x1)) {
				u8c_print(stdout,(uint_least32_t[]){UINT32_C(0x61),n,UINT32_C(0x20),UINT32_C(0x0),});
				fflush(stdout);
			}
			u8c_print(stdout,U"\n");
		}
		break;
	case 0x7:
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
			uint_least8_t res = u8c_strcmp(str0,str1).res;
			printf("str0,str1: %" PRIXLEAST8 ".\n",res);
			res = u8c_strcmp(str1,str2).res;
			printf("str0,str2: %" PRIXLEAST8 ".\n",res);
			res = u8c_strcmp(str2,str1).res;
			printf("str2,str1: %" PRIXLEAST8 ".\n",res);
		}
		break;
	case 0x8:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_isalnum(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0x9:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_isalpha(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0xA:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_isdigit(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0xB:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_ispunct(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0xC:
		{
			u8c_println(stdout,U"Can you see ðis?");
		}
		break;
	case 0xD:
		{
			char32_t const * str0 = U"Free_as_in";
			char32_t const * str1 = U"_freedom!";
			char32_t const * str2 = u8c_strcat(str0,str1).str;
			printf("string #0: ");
			u8c_println(stdout,str0);
			printf("string #1: ");
			u8c_println(stdout,str1);
			printf("string #2: ");
			u8c_println(stdout,str2);
			u8c_strfree(str2);

		}
		break;
	case 0xE:
		{
			char32_t const * str0 = U"I_wish_to_suck_big_duck.";
			char32_t const * str1 = u8c_strsubstr(SIZE_C(0x0),SIZE_C(0xE),str0).str;
			char32_t const * str2 = u8c_strsubstr(SIZE_C(0xF),SIZE_C(0x0),str0).str;
			printf("string #0: ");
			u8c_println(stdout,str0);
			printf("string #1: ");
			u8c_println(stdout,str1);
			printf("string #2: ");
			u8c_println(stdout,str2);
			u8c_strfree(str1);
			u8c_strfree(str2);
		}
		break;
	case 0xF:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_isxdigit(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0x10:
		{
			u8c_dbgprint(U"Hello");
			u8c_dbgprint(U" ðere!");
		}
		break;
	case 0x11:
		{
			char32_t const * str  = U"Proprietary as in Micro$oft.";
			size_t                 pos0 = u8c_strfndchr(str,U'M').pos;
			size_t                 pos1 = u8c_strfndchr(str,U'ŋ').pos;
			printf("string: ");
			u8c_println(stdout,str);
			printf("Position of 'M': %zu\n",pos0);
			printf("Position of 'ŋ': %zu\n",pos1);
		}
		break;
	case 0x12:
		{
			char32_t const * str  = U"Proprietary as in Micro$oft.";
			size_t                 pos0 = u8c_strfndpat(str,U"as in").pos;
			size_t                 pos1 = u8c_strfndpat(str,U"forever").pos;
			printf("string: ");
			u8c_println(stdout,str);
			printf("Position of \"as in\": %zu\n",pos0);
			printf("Position of \"forever\": %zu\n",pos1);
		}
		break;
	case 0x13:
		{
			char32_t const * str0 = U"There_is_I_love.";
			char32_t const * str1 = U"just_somebody_that_";
			char32_t const * str2 = u8c_strins(SIZE_C(0x9),str0,str1).str;
			printf("String #0: ");
			u8c_println(stdout,str0);
			printf("String #1: ");
			u8c_println(stdout,str1);
			printf("String #2: ");
			u8c_println(stdout,str2);
			u8c_strfree(str2);
		}
		break;
	case 0x14:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_islower(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0x15:
		{
			for(register uint_least32_t n = UINT32_C(0x1);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				bool const res = u8c_isupper(n).res;
				if(res) {
					u8c_print(stdout,(uint_least32_t[]){n,UINT32_C(0x20),UINT32_C(0x0),});
				}
			}
			u8c_println(stdout,U"");
		}
		break;
	case 0x16:
		{
			register uint_least32_t num = UINT32_C(0x0);
			for(register uint_least32_t n = UINT32_C(0x0);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1),num += UINT32_C(0x1)) {
				{
					bool const res = u8c_issurro(n).res;
					if(res) {
						num -= UINT32_C(0x1);
						continue;
					}
				}
				char32_t const * nm = u8c_uninm(n).nm;
				uint_least8_t res   = u8c_strcmp(nm,U"UNDEFINED IN UNICODE").res;
				if(res == UINT8_C(0x1)) {
					num -= UINT32_C(0x1);
					u8c_strfree(nm);
					continue;
				}
				printf("U+%" PRIXLEAST32 " ",n);
				u8c_println(stdout,nm);
				u8c_strfree(nm);
			}
			printf("\n:: The number of mapped (named) codepoints is %" PRIuLEAST32 ", which is %f%% of the total number of defined Unicode codepoints (143859).\n",num,((double)num) / (double)UINT32_C(0x231F3) * (double)UINT8_C(0x64));
		}
		break;
	case 0x17:
		{
			char32_t const * lastblk = u8c_strcp(U"").str;
			for(register uint_least32_t n = UINT32_C(0x0);n <= UINT32_C(0x10FFFF);n += UINT32_C(0x1)) {
				char32_t const * blk = u8c_uniblk(n).blk;
				if(u8c_strcmp(blk,lastblk).res == UINT8_C(0x1) || u8c_strcmp(blk,U"UNDEFINED IN UNICODE").res == UINT8_C(0x1)) {
					u8c_strfree(blk);
					continue;
				}
				u8c_strfree(lastblk);
				lastblk = u8c_strcp(blk).str;
				printf("U+%" PRIXLEAST32 " = ",n);
				u8c_println(stdout,blk);
				u8c_strfree(blk);
			}
			u8c_strfree(lastblk);
		}
		break;
	}
	/* printf("\n+->\n| \x1b[38:2::61:225:169mDone\x1b[0m testing (%i) \"%s\"!\n+->\n",n,_testnm); */
	printf("\n+->\n| \x1b[38;2;61;225;169mDone\x1b[0m testing #%i \"%s\"!\n+->\n\n",n,_testnm);
}
static char const * testnm(int n) {
	switch(n) {
	default:
		return "N/A";
	case 0x0:
		return "Error messages";
	case 0x1:
		return "UTF-8 encoding/decoding";
	case 0x2:
		return "Printing (u8c_print)";
	case 0x3:
		return "Printing (u8c_println)";
	case 0x4:
		return "Text formatting";
	case 0x5:
		return "Colour text";
	case 0x6:
		return "Combining characters";
	case 0x7:
		return "String comparison";
	case 0x8:
		return "u8c_isalnum";
	case 0x9:
		return "u8c_isalpha";
	case 0xA:
		return "u8c_isdigit";
	case 0xB:
		return "u8c_ispunct";
	case 0xC:
		return "UTF-32 string literals";
	case 0xD:
		return "String concatenation";
	case 0xE:
		return "Sub-strings";
	case 0xF:
		return "u8c_isxdigit";
	case 0x10:
		return "Printing (u8c_dbgprint)";
	case 0x11:
		return "u8c_strfndchr";
	case 0x12:
		return "u8c_strfndpat";
	case 0x13:
		return "String insertion";
	case 0x14:
		return "u8c_islower";
	case 0x15:
		return "u8c_isupper";
	case 0x16:
		return "u8c_uninm";
	case 0x17:
		return "u8c_uniblk";
	}
}
int main(int const argc,char const * * argv) {
	if(argc == 0x2 && !strcmp(argv[SIZE_C(0x1)],"--help")) {
		exit(hlpscrn(argv[SIZE_C(0x0)]));
	}
	if(u8c_init().stat) {
		printf("Unable to initialise u8c!\n");
		exit(EXIT_FAILURE);
	}
	u8c_regerrhandl(u8c_errtyp_all,errhandl);
	u8c_setfmt(UINT8_C(0xC),UINT8_C(0x1));
	printf("u8c version: %" PRIXLEAST64 "\n",u8c_ver);
	printf("Debug build: %s\n",u8c_dbg ? "true" : "false");
	printf("Thread safe: %s\n",u8c_thrdsafe ? "true" : "false");
	if(argc == 0x2) {
		test(atoi(argv[SIZE_C(0x1)]));
	}
	else {
		for(int n = 0x0;n <= 0x17;n += 0x1) {
			test(n);
		}
	}
	u8c_end();
	exit(EXIT_SUCCESS);
}
