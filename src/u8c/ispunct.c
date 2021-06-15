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
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/ispunct.h>
bool u8c_ispunct(uint_least8_t * const _res,char32_t const _chr) {
	assert(_res != NULL);
	switch(_chr) {
	default:
		*_res = UINT8_C(0x0);
		break;
	case UINT32_C(0x21):    /* EXCLAMATION MARK */
	case UINT32_C(0x22):    /* QUOTATION MARK */
	case UINT32_C(0x23):    /* NUMBER SIGN */
	case UINT32_C(0x24):    /* DOLLAR SIGN */
	case UINT32_C(0x25):    /* PERCENT SIGN */
	case UINT32_C(0x26):    /* AMPERSAND */
	case UINT32_C(0x27):    /* APOSTROPHE */
	case UINT32_C(0x28):    /* LEFT PARANTHESIS */
	case UINT32_C(0x29):    /* RIGHT PARANTHESIS */
	case UINT32_C(0x2A):    /* ASTERISK */
	case UINT32_C(0x2B):    /* PLUS SIGN */
	case UINT32_C(0x2C):    /* COMMA */
	case UINT32_C(0x2D):    /* HYPHEN-MINUS */
	case UINT32_C(0x2E):    /* FULL STOP */
	case UINT32_C(0x2F):    /* SOLIDUS */
	case UINT32_C(0x3A):    /* COLON */
	case UINT32_C(0x3B):    /* SEMICOLON */
	case UINT32_C(0x3C):    /* LESS-THAN SIGN */
	case UINT32_C(0x3D):    /* EQUALS SIGN */
	case UINT32_C(0x3E):    /* GREATER-THAN SIGN */
	case UINT32_C(0x3F):    /* QUESTION MARK */
	case UINT32_C(0x40):    /* COMMERCIAL AT */
	case UINT32_C(0x5B):    /* LEFT SQUARE BRACKET */
	case UINT32_C(0x5C):    /* REVERSE SOLIDUS */
	case UINT32_C(0x5D):    /* RIGHT SQUARE BRACKET */
	case UINT32_C(0x5E):    /* CIRCUMFLEX ACCENT */
	case UINT32_C(0x5F):    /* LOW LINE */
	case UINT32_C(0x60):    /* GRAVE ACCENT */
	case UINT32_C(0x7B):    /* LEFT CURLY BRACKET */
	case UINT32_C(0x7C):    /* VERTICAL LINE */
	case UINT32_C(0x7D):    /* RIGHT CURLY BRACKET */
	case UINT32_C(0x7E):    /* TILDE */
	case UINT32_C(0xA1):    /* INVERT EXCLAMATION MARK */
	case UINT32_C(0xA2):    /* CENT SIGN */
	case UINT32_C(0xA3):    /* POUND SIGN */
	case UINT32_C(0xA4):    /* CURRENCY SIGN */
	case UINT32_C(0xA5):    /* YEN SIGN */
	case UINT32_C(0xA7):    /* SECTION SIGN */
	case UINT32_C(0xA8):    /* DIAERESIS */
	case UINT32_C(0xA9):    /* COPYRIGHT SIGN */
	case UINT32_C(0xAB):    /* LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
	case UINT32_C(0xAE):    /* REGISTERED SIGN */
	case UINT32_C(0xB0):    /* DEGREE SIGN */
	case UINT32_C(0xB4):    /* ACUTE ACCENT */
	case UINT32_C(0xB6):    /* PILCROW SIGN */
	case UINT32_C(0xBB):    /* RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
	case UINT32_C(0xB1):    /* PLUS MINUS SIGN */
	case UINT32_C(0xBF):    /* INVERT QUESTION MARK */
	case UINT32_C(0xD7):    /* MULTIPLICATION SIGN */
	case UINT32_C(0xF7):    /* DIVISION SIGN */
	case UINT32_C(0x2010):  /* HYPHEN */
	case UINT32_C(0x2013):  /* EN DASH */
	case UINT32_C(0x2014):  /* EM DASH */
	case UINT32_C(0x2018):  /* LEFT SINGLE QUOTATION MARK */
	case UINT32_C(0x2019):  /* RIGHT SINGLE QUOTATION MARK */
	case UINT32_C(0x201C):  /* LEFT DOUBLE QUOTATION MARK */
	case UINT32_C(0x201D):  /* RIGHT DOUBLE QUOTATION MARK */
	case UINT32_C(0x2026):  /* HORIZONTAL ELLIPSIS */
	case UINT32_C(0x2030):  /* PER MILLE SIGN */
	case UINT32_C(0x20A3):  /* FRENCH FRANC SIGN */
	case UINT32_C(0x20A4):  /* LIRA SIGN */
	case UINT32_C(0x20A8):  /* RUPEE SIGN */
	case UINT32_C(0x20A9):  /* WON SIGN */
	case UINT32_C(0x20AC):  /* EURO SIGN */
	case UINT32_C(0x20B9):  /* INDIAN RUPEE SIGN */
	case UINT32_C(0x20BF):  /* BITCOIN SIGN */
	case UINT32_C(0x2103):  /* DEGREE CELSIUS */
	case UINT32_C(0x2107):  /* EULER CONSTANT */
	case UINT32_C(0x2109):  /* DEGREE FAHRENHEIT */
	case UINT32_C(0x210E):  /* PLANCK CONSTANT */
	case UINT32_C(0x2117):  /* SOUND RECORDING COPYRIGHT */
	case UINT32_C(0x2122):  /* TRADE MARK SIGN */
	case UINT32_C(0x2125):  /* OUNCE SIGN */
	case UINT32_C(0x2126):  /* OHM SIGN */
	case UINT32_C(0x212A):  /* KELVIN SIGN */
	case UINT32_C(0x214D):  /* AKTIESELSKAB */
	case UINT32_C(0x2205):  /* EMPTY SET */
	case UINT32_C(0x2212):  /* MINUS SIGN */
	case UINT32_C(0x221A):  /* SQUARE ROOT */
	case UINT32_C(0x221B):  /* CUBE ROOT */
	case UINT32_C(0x221C):  /* FOURTH ROOT */
	case UINT32_C(0x221E):  /* INFINITY */
	case UINT32_C(0x2248):  /* ALMOST EQUAL TO */
	case UINT32_C(0x2260):  /* NOT EQUAL TO */
	case UINT32_C(0x2264):  /* LESS-THAN OR EQUAL TO */
	case UINT32_C(0x2265):  /* GREATER-THAN OR EQUAL TO */
	case UINT32_C(0x2609):  /* SUN */
	case UINT32_C(0x263F):  /* MERCURY */
	case UINT32_C(0x2640):  /* FEMALE SIGN */
	case UINT32_C(0x2641):  /* EARTH */
	case UINT32_C(0x2642):  /* MALE SIGN */
	case UINT32_C(0x2643):  /* JUPITER */
	case UINT32_C(0x2644):  /* SATURN */
	case UINT32_C(0x2645):  /* URANUS */
	case UINT32_C(0x2646):  /* NEPTUNE */
	case UINT32_C(0x2647):  /* PLUTO */
	case UINT32_C(0x26A2):  /* DOUBLED FEMALE SIGN */
	case UINT32_C(0x26A3):  /* DOUBLED MALE SIGN */
	case UINT32_C(0x26A4):  /* INTERLOCKED FEMALE AND MALE SIGN */
	case UINT32_C(0x26A5):  /* MALE AND FEMALE SIGN */
	case UINT32_C(0x26B3):  /* CERES */
	case UINT32_C(0x26B4):  /* PALLAS */
	case UINT32_C(0x26B5):  /* JUNO */
	case UINT32_C(0x26B6):  /* VESTA */
	case UINT32_C(0x26B7):  /* CHIRON */
	case UINT32_C(0x2BD8):  /* PROSERPINA */
	case UINT32_C(0x2BD9):  /* ASTRAEA */
	case UINT32_C(0x2BDA):  /* HYGIEA */
	case UINT32_C(0x2BDB):  /* PHOLOS */
	case UINT32_C(0x2BDC):  /* NESSUS */
	case UINT32_C(0x33D7):  /* SQUARE PH */
	case UINT32_C(0xFDFC):  /* RIAL SIGN */
	case UINT32_C(0x1F10D): /* CIRCLED ZERO WITH SLASH */
	case UINT32_C(0x1F10E): /* CIRCLED ANTICKLOCKWISE ARROW */
	case UINT32_C(0x1F10F): /* CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH */
	case UINT32_C(0x1F12F): /* COPYLEFT SYMBOL */
	case UINT32_C(0x1F16D): /* CIRCLED CC */
	case UINT32_C(0x1F16E): /* CIRCLED C WITH OVERLAID BACKSLASH */
	case UINT32_C(0x1F16F): /* CIRCLED HUMAN FIGURE */
		*_res = UINT8_C(0x1);
		break;
	}
	return false;
}
