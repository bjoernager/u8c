/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/chk.h>
struct u8c_isupper_tuple u8c_isupper(char32_t const _chr) {
	struct u8c_isupper_tuple ret = {
		.stat = false,
	};
	switch(_chr) {
	default:
		ret.res = false;
		break;
	case U'A':      /* LATIN CAPITAL LETTER A */
	case U'B':      /* LATIN CAPITAL LETTER B */
	case U'C':      /* LATIN CAPITAL LETTER C */
	case U'D':      /* LATIN CAPITAL LETTER D */
	case U'E':      /* LATIN CAPITAL LETTER E */
	case U'F':      /* LATIN CAPITAL LETTER F */
	case U'G':      /* LATIN CAPITAL LETTER G */
	case U'H':      /* LATIN CAPITAL LETTER H */
	case U'I':      /* LATIN CAPITAL LETTER I */
	case U'J':      /* LATIN CAPITAL LETTER J */
	case U'K':      /* LATIN CAPITAL LETTER K */
	case U'L':      /* LATIN CAPITAL LETTER L */
	case U'M':      /* LATIN CAPITAL LETTER M */
	case U'N':      /* LATIN CAPITAL LETTER N */
	case U'O':      /* LATIN CAPITAL LETTER O */
	case U'P':      /* LATIN CAPITAL LETTER P */
	case U'Q':      /* LATIN CAPITAL LETTER Q */
	case U'R':      /* LATIN CAPITAL LETTER R */
	case U'S':      /* LATIN CAPITAL LETTER S */
	case U'T':      /* LATIN CAPITAL LETTER T */
	case U'U':      /* LATIN CAPITAL LETTER U */
	case U'V':      /* LATIN CAPITAL LETTER V */
	case U'X':      /* LATIN CAPITAL LETTER Y */
	case U'W':      /* LATIN CAPITAL LETTER X */
	case U'Y':      /* LATIN CAPITAL LETTER Y */
	case U'Z':      /* LATIN CAPITAL LETTER Z */
	case U'\u00C0': /* LATIN CAPITAL LETTER A WITH GRAVE */
	case U'\u00C1': /* LATIN CAPITAL LETTER A WITH ACUTE */
	case U'\u00C2': /* LATIN CAPITAL LETTER A WITH CIRCUMFLEX */
	case U'\u00C3': /* LATIN CAPITAL LETTER A WITH TILDE */
	case U'\u00C4': /* LATIN CAPITAL LETTER A WITH DIAERESIS */
	case U'\u00C5': /* LATIN CAPITAL LETTER A WITH RING ABOVE */
	case U'\u00C6': /* LATIN CAPITAL LETTER AE */
	case U'\u00C7': /* LATIN CAPITAL LETTER C WITH CEDILLA */
	case U'\u00C8': /* LATIN CAPITAL LETTER E WITH GRAVE */
	case U'\u00C9': /* LATIN CAPITAL LETTER E WITH ACUTE */
	case U'\u00CA': /* LATIN CAPITAL LETTER E WITH CIRCUMFLEX */
	case U'\u00CB': /* LATIN CAPITAL LETTER E WITH DIAERESIS */
	case U'\u00CC': /* LATIN CAPITAL LETTER I WITH GRAVE */
	case U'\u00CD': /* LATIN CAPITAL LETTER I WITH ACUTE */
	case U'\u00CE': /* LATIN CAPITAL LETTER I WITH CIRCUMFLEX */
	case U'\u00CF': /* LATIN CAPITAL LETTER I WITH DIAERESIS */
	case U'\u00D0': /* LATIN CAPITAL LETTER ETH */
	case U'\u00D1': /* LATIN CAPITAL LETTER N WITH TILDE */
	case U'\u00D2': /* LATIN CAPITAL LETTER O WITH GRAVE */
	case U'\u00D3': /* LATIN CAPITAL LETTER O WITH ACUTE */
	case U'\u00D4': /* LATIN CAPITAL LETTER O WITH CIRCUMFLEX */
	case U'\u00D5': /* LATIN CAPITAL LETTER O WITH TILDE */
	case U'\u00D6': /* LATIN CAPITAL LETTER O WITH DIAERESIS */
	case U'\u00D8': /* LATIN CAPITAL LETTER O WITH STROKE */
	case U'\u00D9': /* LATIN CAPITAL LETTER U WITH GRAVE */
	case U'\u00DA': /* LATIN CAPITAL LETTER U WITH STROKE */
	case U'\u00DB': /* LATIN CAPITAL LETTER U WITH CIRCUMFLEX */
	case U'\u00DC': /* LATIN CAPITAL LETTER U WITH DIAERESIS */
	case U'\u00DD': /* LATIN CAPITAL LETTER Y WITH ACUTE */
	case U'\u00DE': /* LATIN CAPITAL LETTER THORN */
	case U'\u0100': /* LATIN CAPITAL LETTER A WITH MACRON */
	case U'\u0102': /* LATIN CAPITAL LETTER A WITH BREVE */
	case U'\u0104': /* LATIN CAPITAL LETTER A WITH OGONEK */
	case U'\u0106': /* LATIN CAPITAL LETTER C WITH ACUTE */
	case U'\u0108': /* LATIN CAPITAL LETTER C WITH CIRCUMFLEX */
	case U'\u010A': /* LATIN CAPITAL LETTER C WITH DOT ABOVE */
	case U'\u010C': /* LATIN CAPITAL LETTER C WITH CARON */
	case U'\u010E': /* LATIN CAPITAL LETTER D WITH CARON */
	case U'\u0110': /* LATIN CAPITAL LETTER D WITH STROKE */
	case U'\u0112': /* LATIN CAPITAL LETTER E WITH MACRON */
	case U'\u0114': /* LATIN CAPITAL LETTER E WITH BREVE */
	case U'\u0116': /* LATIN CAPITAL LETTER E WITH DOT ABOVE */
	case U'\u0118': /* LATIN CAPITAL LETTER E WITH OGONEK */
	case U'\u011A': /* LATIN CAPITAL LETTER E WITH CARON */
	case U'\u011C': /* LATIN CAPITAL LETTER G WITH CIRCUMFLEX */
	case U'\u014A': /* LATIN CAPITAL LETTER ENG */
	case U'\u0152': /* LATIN CAPITAL LIGATURE OE */
	case U'\u0186': /* LATIN CAPITAL LETTER OPEN O */
	case U'\u018E': /* LATIN CAPITAL LETTER REVERSED E */
	case U'\u018F': /* LATIN CAPITAL LETTER SCHWA */
	case U'\u0190': /* LATIN CAPITAL LETTER OPEN E */
	case U'\u0194': /* LATIN CAPITAL LETTER GAMMA */
	case U'\u0196': /* LATIN CAPITAL LETTER IOTA */
	case U'\u01A9': /* LATIN CAPITAL LETTER ESH */
	case U'\u01B1': /* LATIN CAPITAL LETTER UPSILON */
	case U'\u01B2': /* LATIN CAPITAL LETTER V WITH HOOk */
	case U'\u01B7': /* LATIN CAPITAL LETTER EZH */
	case U'\u01F7': /* LATIN CAPITAL LETTER WYNN */
	case U'\u021C': /* LATIN CAPITAL LETTER YOGH */
	case U'\u0241': /* LATIN CAPITAL LETTER GLOTTAL STOP */
	case U'\u0391': /* GREEK CAPITAL LETTER ALPHA */
	case U'\u0392': /* GREEK CAPITAL LETTER BETA */
	case U'\u0393': /* GREEK CAPITAL LETTER GAMMA */
	case U'\u0394': /* GREEK CAPITAL LETTER DELTA */
	case U'\u0395': /* GREEK CAPITAL LETTER EPSILON */
	case U'\u0396': /* GREEK CAPITAL LETTER ZETA */
	case U'\u0397': /* GREEK CAPITAL LETTER ETA */
	case U'\u0398': /* GREEK CAPITAL LETTER THETA */
	case U'\u0399': /* GREEK CAPITAL LETTER IOTA */
	case U'\u039A': /* GREEK CAPITAL LETTER KAPPA */
	case U'\u039B': /* GREEK CAPITAL LETTER LAMBDA */
	case U'\u039C': /* GREEK CAPITAL LETTER MU */
	case U'\u039D': /* GREEK CAPITAL LETTER NU */
	case U'\u039E': /* GREEK CAPITAL LETTER XI */
	case U'\u039F': /* GREEK CAPITAL LETTER OMICRON */
	case U'\u03A0': /* GREEK CAPITAL LETTER PI */
	case U'\u03A1': /* GREEK CAPITAL LETTER RHO */
	case U'\u03A3': /* GREEK CAPITAL LETTER SIGMA */
	case U'\u03A4': /* GREEK CAPITAL LETTER TAU */
	case U'\u03A5': /* GREEK CAPITAL LETTER UPSILON */
	case U'\u03A6': /* GREEK CAPITAL LETTER PHI */
	case U'\u03A7': /* GREEK CAPITAL LETTER CHI */
	case U'\u03A8': /* GREEK CAPITAL LETTER PSI */
	case U'\u03A9': /* GREEK CAPITAL LETTER OMEGA */
	case U'\u1E9E': /* LATIN CAPITAL LETTER SHARP S */
	case U'\u2C6D': /* LATIN CAPITAL LETTER ALPHA */
	case U'\uA77D': /* LATIN CAPITAL LETTER INSULAR G */
	case U'\uA7B4': /* LATIN CAPITAL LETTER BETA */
	case U'\uA7B6': /* LATIN CAPITAL LETTER OMEGA */
		ret.res = true;
		break;
	}
	return ret;
}
