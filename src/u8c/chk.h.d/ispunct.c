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
struct u8c_ispunct_tuple u8c_ispunct(char32_t const _chr) {
	struct u8c_ispunct_tuple ret = {
		.stat = false,
	};
	switch(_chr) {
	default:
		ret.res = false;
		break;
	case U'!':          /* EXCLAMATION MARK */
	case U'\"':          /* QUOTATION MARK */
	case U'#':          /* NUMBER SIGN */
	case U'\u0024':     /* DOLLAR SIGN */
	case U'%':          /* PERCENT SIGN */
	case U'&':          /* AMPERSAND */
	case U'\'':         /* APOSTROPHE */
	case U'(':          /* LEFT PARANTHESIS */
	case U')':          /* RIGHT PARANTHESIS */
	case U'*':          /* ASTERISK */
	case U'+':          /* PLUS SIGN */
	case U',':          /* COMMA */
	case U'-':          /* HYPHEN-MINUS */
	case U'.':          /* FULL STOP */
	case U'/':          /* SOLIDUS */
	case U':':          /* COLON */
	case U';':          /* SEMICOLON */
	case U'<':          /* LESS-THAN SIGN */
	case U'=':          /* EQUALS SIGN */
	case U'>':          /* GREATER-THAN SIGN */
	case U'\?':          /* QUESTION MARK */
	case U'\u0040':     /* COMMERCIAL AT */
	case U'[':          /* LEFT SQUARE BRACKET */
	case U'\\':         /* REVERSE SOLIDUS */
	case U']':          /* RIGHT SQUARE BRACKET */
	case U'^':          /* CIRCUMFLEX ACCENT */
	case U'_':          /* LOW LINE */
	case U'\u0060':     /* GRAVE ACCENT */
	case U'{':          /* LEFT CURLY BRACKET */
	case U'|':          /* VERTICAL LINE */
	case U'}':          /* RIGHT CURLY BRACKET */
	case U'~':          /* TILDE */
	case U'\u00A1':     /* INVERT EXCLAMATION MARK */
	case U'\u00A2':     /* CENT SIGN */
	case U'\u00A3':     /* POUND SIGN */
	case U'\u00A4':     /* CURRENCY SIGN */
	case U'\u00A5':     /* YEN SIGN */
	case U'\u00A7':     /* SECTION SIGN */
	case U'\u00A8':     /* DIAERESIS */
	case U'\u00A9':     /* COPYRIGHT SIGN */
	case U'\u00AB':     /* LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
	case U'\u00AE':     /* REGISTERED SIGN */
	case U'\u00B0':     /* DEGREE SIGN */
	case U'\u00B4':     /* ACUTE ACCENT */
	case U'\u00B6':     /* PILCROW SIGN */
	case U'\u00BB':     /* RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
	case U'\u00B1':     /* PLUS MINUS SIGN */
	case U'\u00BF':     /* INVERT QUESTION MARK */
	case U'\u00D7':     /* MULTIPLICATION SIGN */
	case U'\u00F7':     /* DIVISION SIGN */
	case U'\u2010':     /* HYPHEN */
	case U'\u2013':     /* EN DASH */
	case U'\u2014':     /* EM DASH */
	case U'\u2018':     /* LEFT SINGLE QUOTATION MARK */
	case U'\u2019':     /* RIGHT SINGLE QUOTATION MARK */
	case U'\u201C':     /* LEFT DOUBLE QUOTATION MARK */
	case U'\u201D':     /* RIGHT DOUBLE QUOTATION MARK */
	case U'\u2026':     /* HORIZONTAL ELLIPSIS */
	case U'\u2030':     /* PER MILLE SIGN */
	case U'\u2031':     /* PER TEN THOUSAND SIGN */
	case U'\u2032':     /* PRIME */
	case U'\u2033':     /* DOUBLE PRIME */
	case U'\u2034':     /* TRIPLE PRIME */
	case U'\u2035':     /* REVERSED PRIME */
	case U'\u2036':     /* REVERSED DOUBLE PRIME */
	case U'\u2037':     /* REVERSED TRIPLE PRIME */
	case U'\u203C':     /* DOUBLE EXCLAMATION MARK */
	case U'\u203D':     /* INTERROBANG */
	case U'\u2047':     /* DOUBLE QUOTATION MARK */
	case U'\u2048':     /* QUESTION EXCLAMATION MARK */
	case U'\u2049':     /* EXCLAMATION QUESTION MARK */
	case U'\u20A3':     /* FRENCH FRANC SIGN */
	case U'\u20A4':     /* LIRA SIGN */
	case U'\u20A8':     /* RUPEE SIGN */
	case U'\u20A9':     /* WON SIGN */
	case U'\u20AC':     /* EURO SIGN */
	case U'\u20B9':     /* INDIAN RUPEE SIGN */
	case U'\u20BF':     /* BITCOIN SIGN */
	case U'\u2103':     /* DEGREE CELSIUS */
	case U'\u2107':     /* EULER CONSTANT */
	case U'\u2109':     /* DEGREE FAHRENHEIT */
	case U'\u210E':     /* PLANCK CONSTANT */
	case U'\u2117':     /* SOUND RECORDING COPYRIGHT */
	case U'\u2122':     /* TRADE MARK SIGN */
	case U'\u2125':     /* OUNCE SIGN */
	case U'\u2126':     /* OHM SIGN */
	case U'\u212A':     /* KELVIN SIGN */
	case U'\u214D':     /* AKTIESELSKAB */
	case U'\u2205':     /* EMPTY SET */
	case U'\u2212':     /* MINUS SIGN */
	case U'\u221A':     /* SQUARE ROOT */
	case U'\u221B':     /* CUBE ROOT */
	case U'\u221C':     /* FOURTH ROOT */
	case U'\u221E':     /* INFINITY */
	case U'\u2228':     /* LOGICAL OR */
	case U'\u2248':     /* ALMOST EQUAL TO */
	case U'\u2260':     /* NOT EQUAL TO */
	case U'\u2264':     /* LESS-THAN OR EQUAL TO */
	case U'\u2265':     /* GREATER-THAN OR EQUAL TO */
	case U'\u2609':     /* SUN */
	case U'\u263F':     /* MERCURY */
	case U'\u2640':     /* FEMALE SIGN */
	case U'\u2641':     /* EARTH */
	case U'\u2642':     /* MALE SIGN */
	case U'\u2643':     /* JUPITER */
	case U'\u2644':     /* SATURN */
	case U'\u2645':     /* URANUS */
	case U'\u2646':     /* NEPTUNE */
	case U'\u2647':     /* PLUTO */
	case U'\u26A2':     /* DOUBLED FEMALE SIGN */
	case U'\u26A3':     /* DOUBLED MALE SIGN */
	case U'\u26A4':     /* INTERLOCKED FEMALE AND MALE SIGN */
	case U'\u26A5':     /* MALE AND FEMALE SIGN */
	case U'\u26B3':     /* CERES */
	case U'\u26B4':     /* PALLAS */
	case U'\u26B5':     /* JUNO */
	case U'\u26B6':     /* VESTA */
	case U'\u26B7':     /* CHIRON */
	case U'\u2BD8':     /* PROSERPINA */
	case U'\u2BD9':     /* ASTRAEA */
	case U'\u2BDA':     /* HYGIEA */
	case U'\u2BDB':     /* PHOLOS */
	case U'\u2BDC':     /* NESSUS */
	case U'\u2E2E':     /* INVERTED QUESTION MARK */
	case U'\u33D7':     /* SQUARE PH */
	case U'\uFDFC':     /* RIAL SIGN */
	case U'\U0001F10D': /* CIRCLED ZERO WITH SLASH */
	case U'\U0001F10E': /* CIRCLED ANTICKLOCKWISE ARROW */
	case U'\U0001F10F': /* CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH */
	case U'\U0001F12F': /* COPYLEFT SYMBOL */
	case U'\U0001F16D': /* CIRCLED CC */
	case U'\U0001F16E': /* CIRCLED C WITH OVERLAID BACKSLASH */
	case U'\U0001F16F': /* CIRCLED HUMAN FIGURE */
		ret.res = true;
		break;
	}
	return ret;
}
