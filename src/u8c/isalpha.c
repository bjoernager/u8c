/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <assert.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/isalpha.h>
uint_least8_t u8c_isalpha(uint_least8_t * const _res,uint_least32_t _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case UINT32_C(0x61):   /* LATIN SMALL LETTER A */
	case UINT32_C(0x62):   /* LATIN SMALL LETTER B */
	case UINT32_C(0x63):   /* LATIN SMALL LETTER C */
	case UINT32_C(0x64):   /* LATIN SMALL LETTER D */
	case UINT32_C(0x65):   /* LATIN SMALL LETTER E */
	case UINT32_C(0x66):   /* LATIN SMALL LETTER F */
	case UINT32_C(0x67):   /* LATIN SMALL LETTER G */
	case UINT32_C(0x68):   /* LATIN SMALL LETTER H */
	case UINT32_C(0x69):   /* LATIN SMALL LETTER I */
	case UINT32_C(0x6A):   /* LATIN SMALL LETTER J */
	case UINT32_C(0x6B):   /* LATIN SMALL LETTER K */
	case UINT32_C(0x6C):   /* LATIN SMALL LETTER L */
	case UINT32_C(0x6D):   /* LATIN SMALL LETTER M */
	case UINT32_C(0x6E):   /* LATIN SMALL LETTER N */
	case UINT32_C(0x6F):   /* LATIN SMALL LETTER O */
	case UINT32_C(0x70):   /* LATIN SMALL LETTER P */
	case UINT32_C(0x71):   /* LATIN SMALL LETTER Q */
	case UINT32_C(0x72):   /* LATIN SMALL LETTER R */
	case UINT32_C(0x73):   /* LATIN SMALL LETTER S */
	case UINT32_C(0x74):   /* LATIN SMALL LETTER T */
	case UINT32_C(0x75):   /* LATIN SMALL LETTER U */
	case UINT32_C(0x76):   /* LATIN SMALL LETTER V */
	case UINT32_C(0x77):   /* LATIN SMALL LETTER W */
	case UINT32_C(0x78):   /* LATIN SMALL LETTER X */
	case UINT32_C(0x79):   /* LATIN SMALL LETTER Y */
	case UINT32_C(0x7A):   /* LATIN SMALL LETTER Z */
	case UINT32_C(0xDF):   /* LATIN SMALL LETTER SHARP S */
	case UINT32_C(0xE1):   /* LATIN SMALL LETTER A WITH ACUTE */
	case UINT32_C(0xE4):   /* LATIN SMALL LETTER A WITH DIAERESIS */
	case UINT32_C(0xE5):   /* LATIN SMALL LETTER A WITH RING ABOVE */
	case UINT32_C(0xE6):   /* LATIN SMALL LETTER AE */
	case UINT32_C(0xE9):   /* LATIN SMALL LETTER E WITH ACUTE */
	case UINT32_C(0xED):   /* LATIN SMALL LETTER I WITH ACUTE */
	case UINT32_C(0xF0):   /* LATIN SMALL LETTER ETH */
	case UINT32_C(0xF3):   /* LATIN SMALL LETTER O WITH ACUTE */
	case UINT32_C(0xF6):   /* LATIN SMALL LETTER O WITH DIAERESIS */
	case UINT32_C(0xF8):   /* LATIN SMALL LETTER O WITH STROKE */
	case UINT32_C(0xFA):   /* LATIN SMALL LETTER U WITH ACUTE */
	case UINT32_C(0xFC):   /* U WITH TWO DOTS */
	case UINT32_C(0xFD):   /* LATIN SMALL LETTER Y WITH ACUTE */
	case UINT32_C(0xFE):   /* LATIN SMALL LETTER THORN */
	case UINT32_C(0x131):  /* LATIN SMALL LETTER DOTLESS I */
	case UINT32_C(0x133):  /* LATIN SMALL LIGATURE LJ */
	case UINT32_C(0x138):  /* LATIN SMALL LETTER KRA */
	case UINT32_C(0x14B):  /* LATIN SMALL LETTER ENG */
	case UINT32_C(0x153):  /* LATIN SMALL LIGATURE OE */
	case UINT32_C(0x1BF):  /* LATIN LETTER WYNN */
	case UINT32_C(0x1DD):  /* LATIN SMALL LETTER TURNED E */
	case UINT32_C(0x21D):  /* LATIN SMALL LETTER YOGH */
	case UINT32_C(0x251):  /* LATIN SMALL LETTER ALPHA */
	case UINT32_C(0x254):  /* LATIN SMALL LETTER OPEN O */
	case UINT32_C(0x259):  /* LATIN SMALL LETTER SCHWA */
	case UINT32_C(0x25B):  /* LATIN SMALL LETTER OPEN E */
	case UINT32_C(0x263):  /* LATIN SMALL LETTER GAMMA */
	case UINT32_C(0x269):  /* LATIN SMALL LETTER IOTA */
	case UINT32_C(0x283):  /* LATIN SMALL LETTER ESH */
	case UINT32_C(0x28A):  /* LATIN SMALL LETTER UPSILON */
	case UINT32_C(0x28B):  /* LATIN SMALL LETTER V WITH HOOK */
	case UINT32_C(0x292):  /* LATIN SMALL LETTER EZH */
	case UINT32_C(0x294):  /* LATIN SMALL LETTER GLOTTAL STOP */
	case UINT32_C(0x1D79): /* LATIN SMALL LETTER INSULAR G */
	case UINT32_C(0xA7B7): /* LATIN SMALL LETTER OMEGA */
		*_res = UINT8_C(0x1);
		break;
	}
	return UINT8_C(0x0);
}
