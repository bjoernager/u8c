/*
	Copyright 2021, 2023 Gabriel Bjørnager Jensen.

	This file is part of u8c.

    u8c is free software: you can redistribute it
	and/or modify it under the terms of the GNU
	Lesser General Public License as published by
	the Free Software Foundation, either version 3 of
	the License, or (at your option) any later
	version.

    u8c is distributed in the hope that it will be
	useful, but WITHOUT ANY WARRANTY; without even
	the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	Lesser General Public License for more details.

    You should have received a copy of the GNU
	Lesser General Public License along with u8c. If
	not, see <https://www.gnu.org/licenses/>.
*/

#include <u8c/character.h>

#include <stdbool.h>
#include <stdint.h>

bool u8c_is_punctuation(uint_least32_t const code_point) {
	switch(code_point) {
	default:
		return false;

	case UINT32_C(0x0021):     // EXCLAMATION MARK
	case UINT32_C(0x0022):     // QUOTATION MARK
	case UINT32_C(0x0023):     // NUMBER SIGN
	case UINT32_C(0x0024):     // DOLLAR SIGN
	case UINT32_C(0x0025):     // PERCENT SIGN
	case UINT32_C(0x0026):     // AMPERSAND
	case UINT32_C(0x0027):     // APOSTROPHE
	case UINT32_C(0x0028):     // LEFT PARANTHESIS
	case UINT32_C(0x0029):     // RIGHT PARANTHESIS
	case UINT32_C(0x002A):     // ASTERISK
	case UINT32_C(0x002B):     // PLUS SIGN
	case UINT32_C(0x002C):     // COMMA
	case UINT32_C(0x002D):     // HYPHEN-MINUS
	case UINT32_C(0x002E):     // FULL STOP
	case UINT32_C(0x002F):     // SOLIDUS
	case UINT32_C(0x003A):     // COLON
	case UINT32_C(0x003B):     // SEMICOLON
	case UINT32_C(0x003C):     // LESS-THAN SIGN
	case UINT32_C(0x003D):     // EQUALS SIGN
	case UINT32_C(0x003E):     // GREATER-THAN SIGN
	case UINT32_C(0x003F):     // QUESTION MARK
	case UINT32_C(0x0040):     // COMMERCIAL AT
	case UINT32_C(0x005B):     // LEFT SQUARE BRACKET
	case UINT32_C(0x005C):     // REVERSE SOLIDUS
	case UINT32_C(0x005D):     // RIGHT SQUARE BRACKET
	case UINT32_C(0x005E):     // CIRCUMFLEX ACCENT
	case UINT32_C(0x005F):     // LOW LINE
	case UINT32_C(0x0060):     // GRAVE ACCENT
	case UINT32_C(0x007B):     // LEFT CURLY BRACKET
	case UINT32_C(0x007C):     // VERTICAL LINE
	case UINT32_C(0x007D):     // RIGHT CURLY BRACKET
	case UINT32_C(0x007E):     // TILDE
	case UINT32_C(0x00A1):     // INVERT EXCLAMATION MARK
	case UINT32_C(0x00A2):     // CENT SIGN
	case UINT32_C(0x00A3):     // POUND SIGN
	case UINT32_C(0x00A4):     // CURRENCY SIGN
	case UINT32_C(0x00A5):     // YEN SIGN
	case UINT32_C(0x00A6):     // BROKEN BAR
	case UINT32_C(0x00A7):     // SECTION SIGN
	case UINT32_C(0x00A8):     // DIAERESIS
	case UINT32_C(0x00A9):     // COPYRIGHT SIGN
	case UINT32_C(0x00AA):     // FEMININE ORDINAL INDICATOR
	case UINT32_C(0x00AB):     // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
	case UINT32_C(0x00AC):     // NOT SIGN
	case UINT32_C(0x00AE):     // REGISTERED SIGN
	case UINT32_C(0x00AF):     // MACRON
	case UINT32_C(0x00B0):     // DEGREE SIGN
	case UINT32_C(0x00B1):     // PLUS MINUS SYMBOL
	case UINT32_C(0x00B2):     // SUPERSCRIPT TWO
	case UINT32_C(0x00B3):     // SUPERSCRIPT THREE
	case UINT32_C(0x00B4):     // ACUTE ACCENT
	case UINT32_C(0x00B5):     // MICRO SIGN
	case UINT32_C(0x00B6):     // PILCROW SIGN
	case UINT32_C(0x00B7):     // MIDDLE DOT
	case UINT32_C(0x00B8):     // CEDILLA
	case UINT32_C(0x00B9):     // SUPERSCRIPT ONE
	case UINT32_C(0x00BA):     // MASCULINE ORDINAL INDICATOR
	case UINT32_C(0x00BB):     // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
	case UINT32_C(0x00BC):     // VULGAR FRACTION ONE QUARTER
	case UINT32_C(0x00BD):     // VULGAR FRACTION ONE HALF
	case UINT32_C(0x00BE):     // VULGAR FRACTION THREE QUARTERS
	case UINT32_C(0x00BF):     // INVERT QUESTION MARK
	case UINT32_C(0x00D7):     // MULTIPLICATION SIGN
	case UINT32_C(0x00F7):     // DIVISION SIGN
	case UINT32_C(0x16EB):     // RUNIC SINGLE PUNCTUATION
	case UINT32_C(0x16EC):     // RUNIC MULTIPLE PUNCTUATION
	case UINT32_C(0x16ED):     // RUNIC CROSS PUNCTUATION
	case UINT32_C(0x2010):     // HYPHEN
	case UINT32_C(0x2013):     // EN DASH
	case UINT32_C(0x2014):     // EM DASH
	case UINT32_C(0x2018):     // LEFT SINGLE QUOTATION MARK
	case UINT32_C(0x2019):     // RIGHT SINGLE QUOTATION MARK
	case UINT32_C(0x201C):     // LEFT DOUBLE QUOTATION MARK
	case UINT32_C(0x201D):     // RIGHT DOUBLE QUOTATION MARK
	case UINT32_C(0x2026):     // HORIZONTAL ELLIPSIS
	case UINT32_C(0x2030):     // PER MILLE SIGN
	case UINT32_C(0x2031):     // PER TEN THOUSAND SIGN
	case UINT32_C(0x2032):     // PRIME
	case UINT32_C(0x2033):     // DOUBLE PRIME
	case UINT32_C(0x2034):     // TRIPLE PRIME
	case UINT32_C(0x2035):     // REVERSED PRIME
	case UINT32_C(0x2036):     // REVERSED DOUBLE PRIME
	case UINT32_C(0x2037):     // REVERSED TRIPLE PRIME
	case UINT32_C(0x203C):     // DOUBLE EXCLAMATION MARK
	case UINT32_C(0x203D):     // INTERROBANG
	case UINT32_C(0x2047):     // DOUBLE QUOTATION MARK
	case UINT32_C(0x2048):     // QUESTION EXCLAMATION MARK
	case UINT32_C(0x2049):     // EXCLAMATION QUESTION MARK
	case UINT32_C(0x20A3):     // FRENCH FRANC SIGN
	case UINT32_C(0x20A4):     // LIRA SIGN
	case UINT32_C(0x20A8):     // RUPEE SIGN
	case UINT32_C(0x20A9):     // WON SIGN
	case UINT32_C(0x20AC):     // EURO SIGN
	case UINT32_C(0x20B9):     // INDIAN RUPEE SIGN
	case UINT32_C(0x20BF):     // BITCOIN SIGN
	case UINT32_C(0x2103):     // DEGREE CELSIUS
	case UINT32_C(0x2107):     // EULER CONSTANT
	case UINT32_C(0x2109):     // DEGREE FAHRENHEIT
	case UINT32_C(0x210E):     // PLANCK CONSTANT
	case UINT32_C(0x2117):     // SOUND RECORDING COPYRIGHT
	case UINT32_C(0x2122):     // TRADE MARK SIGN
	case UINT32_C(0x2125):     // OUNCE SIGN
	case UINT32_C(0x2126):     // OHM SIGN
	case UINT32_C(0x212A):     // KELVIN SIGN
	case UINT32_C(0x214D):     // AKTIESELSKAB
	case UINT32_C(0x2205):     // EMPTY SET
	case UINT32_C(0x2212):     // MINUS SIGN
	case UINT32_C(0x221A):     // SQUARE ROOT
	case UINT32_C(0x221B):     // CUBE ROOT
	case UINT32_C(0x221C):     // FOURTH ROOT
	case UINT32_C(0x221E):     // INFINITY
	case UINT32_C(0x2228):     // LOGICAL OR
	case UINT32_C(0x2248):     // ALMOST EQUAL TO
	case UINT32_C(0x2260):     // NOT EQUAL TO
	case UINT32_C(0x2264):     // LESS-THAN OR EQUAL TO
	case UINT32_C(0x2265):     // GREATER-THAN OR EQUAL TO
	case UINT32_C(0x2609):     // SUN
	case UINT32_C(0x263F):     // MERCURY
	case UINT32_C(0x2640):     // FEMALE SIGN
	case UINT32_C(0x2641):     // EARTH
	case UINT32_C(0x2642):     // MALE SIGN
	case UINT32_C(0x2643):     // JUPITER
	case UINT32_C(0x2644):     // SATURN
	case UINT32_C(0x2645):     // URANUS
	case UINT32_C(0x2646):     // NEPTUNE
	case UINT32_C(0x2647):     // PLUTO
	case UINT32_C(0x26A2):     // DOUBLED FEMALE SIGN
	case UINT32_C(0x26A3):     // DOUBLED MALE SIGN
	case UINT32_C(0x26A4):     // INTERLOCKED FEMALE AND MALE SIGN
	case UINT32_C(0x26A5):     // MALE AND FEMALE SIGN
	case UINT32_C(0x26B3):     // CERES
	case UINT32_C(0x26B4):     // PALLAS
	case UINT32_C(0x26B5):     // JUNO
	case UINT32_C(0x26B6):     // VESTA
	case UINT32_C(0x26B7):     // CHIRON
	case UINT32_C(0x2BD8):     // PROSERPINA
	case UINT32_C(0x2BD9):     // ASTRAEA
	case UINT32_C(0x2BDA):     // HYGIEA
	case UINT32_C(0x2BDB):     // PHOLOS
	case UINT32_C(0x2BDC):     // NESSUS
	case UINT32_C(0x2E2E):     // INVERTED QUESTION MARK
	case UINT32_C(0x33D7):     // SQUARE PH
	case UINT32_C(0xFDFC):     // RIAL SIGN
	case UINT32_C(0x0001F10D): // CIRCLED ZERO WITH SLASH
	case UINT32_C(0x0001F10E): // CIRCLED ANTICKLOCKWISE ARROW
	case UINT32_C(0x0001F10F): // CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH
	case UINT32_C(0x0001F12F): // COPYLEFT SYMBOL
	case UINT32_C(0x0001F16D): // CIRCLED CC
	case UINT32_C(0x0001F16E): // CIRCLED C WITH OVERLAID BACKSLASH
	case UINT32_C(0x0001F16F): // CIRCLED HUMAN FIGURE
		return true;
	}
}
