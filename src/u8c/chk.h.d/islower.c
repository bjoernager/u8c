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
struct u8c_islower_tuple u8c_islower(char32_t const _chr) {
	struct u8c_islower_tuple ret = {
		.stat = false,
	};
	switch(_chr) {
	default:
		ret.res = false;
		break;
	case U'a':      /* LATIN SMALL LETTER A */
	case U'b':      /* LATIN SMALL LETTER B */
	case U'c':      /* LATIN SMALL LETTER C */
	case U'd':      /* LATIN SMALL LETTER D */
	case U'e':      /* LATIN SMALL LETTER E */
	case U'f':      /* LATIN SMALL LETTER F */
	case U'g':      /* LATIN SMALL LETTER G */
	case U'h':      /* LATIN SMALL LETTER H */
	case U'i':      /* LATIN SMALL LETTER I */
	case U'j':      /* LATIN SMALL LETTER J */
	case U'k':      /* LATIN SMALL LETTER K */
	case U'l':      /* LATIN SMALL LETTER L */
	case U'm':      /* LATIN SMALL LETTER M */
	case U'n':      /* LATIN SMALL LETTER N */
	case U'o':      /* LATIN SMALL LETTER O */
	case U'p':      /* LATIN SMALL LETTER P */
	case U'q':      /* LATIN SMALL LETTER Q */
	case U'r':      /* LATIN SMALL LETTER R */
	case U's':      /* LATIN SMALL LETTER S */
	case U't':      /* LATIN SMALL LETTER T */
	case U'u':      /* LATIN SMALL LETTER U */
	case U'v':      /* LATIN SMALL LETTER V */
	case U'w':      /* LATIN SMALL LETTER W */
	case U'x':      /* LATIN SMALL LETTER X */
	case U'y':      /* LATIN SMALL LETTER Y */
	case U'z':      /* LATIN SMALL LETTER Z */
	case U'\u00DF': /* LATIN SMALL LETTER SHARP S */
	case U'\u00E0': /* LATIN SMALL LETTER A WITH GRAVE */
	case U'\u00E1': /* LATIN SMALL LETTER A WITH ACUTE */
	case U'\u00E2': /* LATIN SMALL LETTER A WITH CIRCUMFLEX */
	case U'\u00E3': /* LATIN SMALL LETTER A WITH TILDE */
	case U'\u00E4': /* LATIN SMALL LETTER A WITH DIAERESIS */
	case U'\u00E5': /* LATIN SMALL LETTER A WITH RING ABOVE */
	case U'\u00E6': /* LATIN SMALL LETTER AE */
	case U'\u00E7': /* LATIN SMALL LETTER C WITH CEDILLA */
	case U'\u00E8': /* LATIN SMALL LETTER E WITH GRAVE */
	case U'\u00E9': /* LATIN SMALL LETTER E WITH ACUTE */
	case U'\u00EA': /* LATIN SMALL LETTER E WITH CIRCUMFLEX */
	case U'\u00EB': /* LATIN SMALL LETTER E WITH DIAERESIS */
	case U'\u00EC': /* LATIN SMALL LETTER I WITH GRAVE */
	case U'\u00ED': /* LATIN SMALL LETTER I WITH ACUTE */
	case U'\u00EE': /* LATIN SMALL LETTER I WITH CIRCUMFLEX */
	case U'\u00EF': /* LATIN SMALL LETTER I WITH DIAERESIS */
	case U'\u00F0': /* LATIN SMALL LETTER ETH */
	case U'\u00F1': /* LATIN SMALL LETTER N WITH TILDE */
	case U'\u00F2': /* LATIN SMALL LETTER O WITH GRAVE */
	case U'\u00F3': /* LATIN SMALL LETTER O WITH ACUTE */
	case U'\u00F4': /* LATIN SMALL LETTER O WITH CIRCUMFLEX */
	case U'\u00F5': /* LATIN SMALL LETTER O WITH TILDE */
	case U'\u00F6': /* LATIN SMALL LETTER O WITH DIAERESIS */
	case U'\u00F8': /* LATIN SMALL LETTER O WITH STROKE */
	case U'\u00F9': /* LATIN SMALL LETTER U WITH GRAVE */
	case U'\u00FA': /* LATIN SMALL LETTER U WITH ACUTE */
	case U'\u00FB': /* LATIN SMALL LETTER U WITH CIRCUMFLEX */
	case U'\u00FC': /* U WITH TWO DOTS */
	case U'\u00FD': /* LATIN SMALL LETTER Y WITH ACUTE */
	case U'\u00FE': /* LATIN SMALL LETTER THORN */
	case U'\u00FF': /* LATIN SMALL LETTER Y WITH DIAERESIS */
	case U'\u0105': /* LATIN SMALL LETTER A WITH OGONEK */
	case U'\u0107': /* LATIN SMALL LETTER C WITH ACUTE */
	case U'\u010D': /* LATIN SMALL LETTER C WITH CARON */
	case U'\u010F': /* LATIN SMALL LETTER D WITH CARON */
	case U'\u0119': /* LATIN SMALL LETTER E WITH OGONEK */
	case U'\u011B': /* LATIN SMALL LETTER E WITH CARON */
	case U'\u011F': /* LATIN SMALL LETTER G WITH BREVE */
	case U'\u0131': /* LATIN SMALL LETTER DOTLESS I */
	case U'\u0133': /* LATIN SMALL LIGATURE LJ */
	case U'\u0138': /* LATIN SMALL LETTER KRA */
	case U'\u0142': /* LATIN SMALL LETTER L WITH STROKE */
	case U'\u0144': /* LATIN SMALL LETTER N WITH ACUTE */
	case U'\u0148': /* LATIN SMALL LETTER N WITH CARON */
	case U'\u014B': /* LATIN SMALL LETTER ENG */
	case U'\u0153': /* LATIN SMALL LIGATURE OE */
	case U'\u0159': /* LATIN SMALL LETTER R WITH CARON */
	case U'\u015B': /* LATIN SMALL LETTER S WITH ACUTE */
	case U'\u015F': /* LATIN SMALL LETTER S WITH CEDILLA */
	case U'\u0161': /* LATIN SMALL LETTER S WITH CARON */
	case U'\u0165': /* LATIN SMALL LETTER T WITH CARON */
	case U'\u016F': /* LATIN SMALL LETTER U WITH RING ABOVE */
	case U'\u017A': /* LATIN SMALL LETTER Z WITH ACUTE */
	case U'\u017C': /* LATIN SMALL LETTER Z WITH DOT ABOVE */
	case U'\u017E': /* LATIN SMALL LETTER Z WITH CARON */
	case U'\u01BF': /* LATIN LETTER WYNN */
	case U'\u01DD': /* LATIN SMALL LETTER TURNED E */
	case U'\u021D': /* LATIN SMALL LETTER YOGH */
	case U'\u0242': /* LATIN SMALL LETTER GLOTTAL STOP */
	case U'\u0250': /* LATIN SMALL LETTER TURNED A */
	case U'\u0251': /* LATIN SMALL LETTER ALPHA */
	case U'\u0252': /* LATIN SMALL LETTER TURNED ALPHA */
	case U'\u0253': /* LATIN SMALL LETTER B WITH HOOk */
	case U'\u0254': /* LATIN SMALL LETTER OPEN O */
	case U'\u0255': /* LATIN SMALL LETTER C WITH CURL */
	case U'\u0256': /* LATIN SMALL LETTER D WITH TAIL */
	case U'\u0257': /* LATIN SMALL LETTER D WITH HOOk */
	case U'\u0258': /* LATIN SMALL LETTER REVERSED E */
	case U'\u0259': /* LATIN SMALL LETTER SCHWA */
	case U'\u025A': /* LATIN SMALL LETTER SCHWA WITH HOOK */
	case U'\u025B': /* LATIN SMALL LETTER OPEN E */
	case U'\u025C': /* LATIN SMALL LETTER REVERSED OPEN E */
	case U'\u025D': /* LATIN SMALL LETTER REVERSED OPEN E WITH HOOK */
	case U'\u025E': /* LATIN SMALL LETTER CLOSED REVERSED OPEN E */
	case U'\u025F': /* LATIN SMALL LETTER DOTLESS J WITH STROKE */
	case U'\u0260': /* LATIN SMALL LETTER G WITH HOOK */
	case U'\u0261': /* LATIN SMALL LETTER SCRIPT G */
	case U'\u0262': /* LATIN LETTER SMALL CAPITAL G */
	case U'\u0263': /* LATIN SMALL LETTER GAMMA */
	case U'\u0264': /* LATIN SMALL LETTER RAMS HORN */
	case U'\u0265': /* LATIN SMALL LETTER TURNED H */
	case U'\u0266': /* LATIN SMALL LETTER H WITH HOOK */
	case U'\u0267': /* LATIN SMALL LETTER HENG WITH HOOK */
	case U'\u0268': /* LATIN SMALL LETTER I WITH STROKE */
	case U'\u0269': /* LATIN SMALL LETTER IOTA */
	case U'\u026A': /* LATIN LETTER SMALL CAPITAL I */
	case U'\u026B': /* LATIN SMALL LETTER L WITH MIDDLE TILDE */
	case U'\u026C': /* LATIN SMALL LETTER L WITH BELT */
	case U'\u026D': /* LATIN SMALL LETTER L WITH RETROFLEX HOOK */
	case U'\u026E': /* LATIN SMALL LETTER LEZH */
	case U'\u026F': /* LATIN SMALL LETTER TURNED M */
	case U'\u0270': /* LATIN SMALL LETTER TURNED M WITH LONG LEG */
	case U'\u0271': /* LATIN SMALL LETTER M WITH HOOK */
	case U'\u0272': /* LATIN SMALL LETTER N WITH LEFT HOOK */
	case U'\u0273': /* LATIN SMALL LETTER N WITH RETROFLEX HOOK */
	case U'\u0283': /* LATIN SMALL LETTER ESH */
	case U'\u028A': /* LATIN SMALL LETTER UPSILON */
	case U'\u028B': /* LATIN SMALL LETTER V WITH HOOK */
	case U'\u0292': /* LATIN SMALL LETTER EZH */
	case U'\u0294': /* LATIN SMALL LETTER GLOTTAL STOP */
	case U'\u03B1': /* GREEK SMALL LETTER ALPHA */
	case U'\u03B2': /* GREEK SMALL LETTER BETA */
	case U'\u03B3': /* GREEK SMALL LETTER GAMMA */
	case U'\u03B4': /* GREEK SMALL LETTER DELTA */
	case U'\u03B5': /* GREEK SMALL LETTER EPSILON */
	case U'\u03B6': /* GREEK SMALL LETTER ZETA */
	case U'\u03B7': /* GREEK SMALL LETTER ETA */
	case U'\u03B8': /* GREEK SMALL LETTER THETA */
	case U'\u03B9': /* GREEK SMALL LETTER IOTA */
	case U'\u03BA': /* GREEK SMALL LETTER KAPPA */
	case U'\u03BB': /* GREEK SMALL LETTER LAMBDA */
	case U'\u03BC': /* GREEK SMALL LETTER MU */
	case U'\u03BD': /* GREEK SMALL LETTER NU */
	case U'\u03BE': /* GREEK SMALL LETTER XI */
	case U'\u03BF': /* GREEK SMALL LETTER OMICRON */
	case U'\u03C0': /* GREEK SMALL LETTER PI */
	case U'\u03C1': /* GREEK SMALL LETTER RHO */
	case U'\u03C2': /* GREEK SMALL LETTER FINAL SIGMA */
	case U'\u03C3': /* GREEK SMALL LETTER SIGMA */
	case U'\u03C4': /* GREEK SMALL LETTER TAU */
	case U'\u03C5': /* GREEK SMALL LETTER UPSILON */
	case U'\u03C6': /* GREEK SMALL LETTER PHI */
	case U'\u03C7': /* GREEK SMALL LETTER CHI */
	case U'\u03C8': /* GREEK SMALL LETTER PSI */
	case U'\u03C9': /* GREEK SMALL LETTER OMEGA */
	case U'\u1D79': /* LATIN SMALL LETTER INSULAR G */
	case U'\uA7B7': /* LATIN SMALL LETTER OMEGA */
	case U'\uFB00': /* LATIN SMALL LIGATURE FF */
		ret.res = true;
		break;
	}
	return ret;
}
