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

bool u8c_is_minuscule(uint_least32_t const code_point) {
	switch(code_point) {
	default:
		return false;

	case (uint_least32_t)'a':      // LATIN SMALL LETTER A
	case (uint_least32_t)'b':      // LATIN SMALL LETTER B
	case (uint_least32_t)'c':      // LATIN SMALL LETTER C
	case (uint_least32_t)'d':      // LATIN SMALL LETTER D
	case (uint_least32_t)'e':      // LATIN SMALL LETTER E
	case (uint_least32_t)'f':      // LATIN SMALL LETTER F
	case (uint_least32_t)'g':      // LATIN SMALL LETTER G
	case (uint_least32_t)'h':      // LATIN SMALL LETTER H
	case (uint_least32_t)'i':      // LATIN SMALL LETTER I
	case (uint_least32_t)'j':      // LATIN SMALL LETTER J
	case (uint_least32_t)'k':      // LATIN SMALL LETTER K
	case (uint_least32_t)'l':      // LATIN SMALL LETTER L
	case (uint_least32_t)'m':      // LATIN SMALL LETTER M
	case (uint_least32_t)'n':      // LATIN SMALL LETTER N
	case (uint_least32_t)'o':      // LATIN SMALL LETTER O
	case (uint_least32_t)'p':      // LATIN SMALL LETTER P
	case (uint_least32_t)'q':      // LATIN SMALL LETTER Q
	case (uint_least32_t)'r':      // LATIN SMALL LETTER R
	case (uint_least32_t)'s':      // LATIN SMALL LETTER S
	case (uint_least32_t)'t':      // LATIN SMALL LETTER T
	case (uint_least32_t)'u':      // LATIN SMALL LETTER U
	case (uint_least32_t)'v':      // LATIN SMALL LETTER V
	case (uint_least32_t)'w':      // LATIN SMALL LETTER W
	case (uint_least32_t)'x':      // LATIN SMALL LETTER X
	case (uint_least32_t)'y':      // LATIN SMALL LETTER Y
	case (uint_least32_t)'z':      // LATIN SMALL LETTER Z
	case UINT32_C(0x00DF): // LATIN SMALL LETTER SHARP S
	case UINT32_C(0x00E0): // LATIN SMALL LETTER A WITH GRAVE
	case UINT32_C(0x00E1): // LATIN SMALL LETTER A WITH ACUTE
	case UINT32_C(0x00E2): // LATIN SMALL LETTER A WITH CIRCUMFLEX
	case UINT32_C(0x00E3): // LATIN SMALL LETTER A WITH TILDE
	case UINT32_C(0x00E4): // LATIN SMALL LETTER A WITH DIAERESIS
	case UINT32_C(0x00E5): // LATIN SMALL LETTER A WITH RING ABOVE
	case UINT32_C(0x00E6): // LATIN SMALL LETTER AE
	case UINT32_C(0x00E7): // LATIN SMALL LETTER C WITH CEDILLA
	case UINT32_C(0x00E8): // LATIN SMALL LETTER E WITH GRAVE
	case UINT32_C(0x00E9): // LATIN SMALL LETTER E WITH ACUTE
	case UINT32_C(0x00EA): // LATIN SMALL LETTER E WITH CIRCUMFLEX
	case UINT32_C(0x00EB): // LATIN SMALL LETTER E WITH DIAERESIS
	case UINT32_C(0x00EC): // LATIN SMALL LETTER I WITH GRAVE
	case UINT32_C(0x00ED): // LATIN SMALL LETTER I WITH ACUTE
	case UINT32_C(0x00EE): // LATIN SMALL LETTER I WITH CIRCUMFLEX
	case UINT32_C(0x00EF): // LATIN SMALL LETTER I WITH DIAERESIS
	case UINT32_C(0x00F0): // LATIN SMALL LETTER ETH
	case UINT32_C(0x00F1): // LATIN SMALL LETTER N WITH TILDE
	case UINT32_C(0x00F2): // LATIN SMALL LETTER O WITH GRAVE
	case UINT32_C(0x00F3): // LATIN SMALL LETTER O WITH ACUTE
	case UINT32_C(0x00F4): // LATIN SMALL LETTER O WITH CIRCUMFLEX
	case UINT32_C(0x00F5): // LATIN SMALL LETTER O WITH TILDE
	case UINT32_C(0x00F6): // LATIN SMALL LETTER O WITH DIAERESIS
	case UINT32_C(0x00F8): // LATIN SMALL LETTER O WITH STROKE
	case UINT32_C(0x00F9): // LATIN SMALL LETTER U WITH GRAVE
	case UINT32_C(0x00FA): // LATIN SMALL LETTER U WITH ACUTE
	case UINT32_C(0x00FB): // LATIN SMALL LETTER U WITH CIRCUMFLEX
	case UINT32_C(0x00FC): // LATIN SMALL LETTER U WITH DIAERESIS
	case UINT32_C(0x00FD): // LATIN SMALL LETTER Y WITH ACUTE
	case UINT32_C(0x00FE): // LATIN SMALL LETTER THORN
	case UINT32_C(0x00FF): // LATIN SMALL LETTER Y WITH DIAERESIS
	case UINT32_C(0x0105): // LATIN SMALL LETTER A WITH OGONEK
	case UINT32_C(0x0107): // LATIN SMALL LETTER C WITH ACUTE
	case UINT32_C(0x010D): // LATIN SMALL LETTER C WITH CARON
	case UINT32_C(0x010F): // LATIN SMALL LETTER D WITH CARON
	case UINT32_C(0x0119): // LATIN SMALL LETTER E WITH OGONEK
	case UINT32_C(0x011B): // LATIN SMALL LETTER E WITH CARON
	case UINT32_C(0x011F): // LATIN SMALL LETTER G WITH BREVE
	case UINT32_C(0x0131): // LATIN SMALL LETTER DOTLESS I
	case UINT32_C(0x0133): // LATIN SMALL LIGATURE IJ
	case UINT32_C(0x0138): // LATIN SMALL LETTER KRA
	case UINT32_C(0x0142): // LATIN SMALL LETTER L WITH STROKE
	case UINT32_C(0x0144): // LATIN SMALL LETTER N WITH ACUTE
	case UINT32_C(0x0148): // LATIN SMALL LETTER N WITH CARON
	case UINT32_C(0x014B): // LATIN SMALL LETTER ENG
	case UINT32_C(0x0153): // LATIN SMALL LIGATURE OE
	case UINT32_C(0x0159): // LATIN SMALL LETTER R WITH CARON
	case UINT32_C(0x015B): // LATIN SMALL LETTER S WITH ACUTE
	case UINT32_C(0x015F): // LATIN SMALL LETTER S WITH CEDILLA
	case UINT32_C(0x0161): // LATIN SMALL LETTER S WITH CARON
	case UINT32_C(0x0165): // LATIN SMALL LETTER T WITH CARON
	case UINT32_C(0x016F): // LATIN SMALL LETTER U WITH RING ABOVE
	case UINT32_C(0x017A): // LATIN SMALL LETTER Z WITH ACUTE
	case UINT32_C(0x017C): // LATIN SMALL LETTER Z WITH DOT ABOVE
	case UINT32_C(0x017E): // LATIN SMALL LETTER Z WITH CARON
	case UINT32_C(0x01BF): // LATIN LETTER WYNN
	case UINT32_C(0x01DD): // LATIN SMALL LETTER TURNED E
	case UINT32_C(0x021D): // LATIN SMALL LETTER YOGH
	case UINT32_C(0x0242): // LATIN SMALL LETTER GLOTTAL STOP
	case UINT32_C(0x0250): // LATIN SMALL LETTER TURNED A
	case UINT32_C(0x0251): // LATIN SMALL LETTER ALPHA
	case UINT32_C(0x0252): // LATIN SMALL LETTER TURNED ALPHA
	case UINT32_C(0x0253): // LATIN SMALL LETTER B WITH HOOk
	case UINT32_C(0x0254): // LATIN SMALL LETTER OPEN O
	case UINT32_C(0x0255): // LATIN SMALL LETTER C WITH CURL
	case UINT32_C(0x0256): // LATIN SMALL LETTER D WITH TAIL
	case UINT32_C(0x0257): // LATIN SMALL LETTER D WITH HOOk
	case UINT32_C(0x0258): // LATIN SMALL LETTER REVERSED E
	case UINT32_C(0x0259): // LATIN SMALL LETTER SCHWA
	case UINT32_C(0x025A): // LATIN SMALL LETTER SCHWA WITH HOOK
	case UINT32_C(0x025B): // LATIN SMALL LETTER OPEN E
	case UINT32_C(0x025C): // LATIN SMALL LETTER REVERSED OPEN E
	case UINT32_C(0x025D): // LATIN SMALL LETTER REVERSED OPEN E WITH HOOK
	case UINT32_C(0x025E): // LATIN SMALL LETTER CLOSED REVERSED OPEN E
	case UINT32_C(0x025F): // LATIN SMALL LETTER DOTLESS J WITH STROKE
	case UINT32_C(0x0260): // LATIN SMALL LETTER G WITH HOOK
	case UINT32_C(0x0261): // LATIN SMALL LETTER SCRIPT G
	case UINT32_C(0x0262): // LATIN LETTER SMALL CAPITAL G
	case UINT32_C(0x0263): // LATIN SMALL LETTER GAMMA
	case UINT32_C(0x0264): // LATIN SMALL LETTER RAMS HORN
	case UINT32_C(0x0265): // LATIN SMALL LETTER TURNED H
	case UINT32_C(0x0266): // LATIN SMALL LETTER H WITH HOOK
	case UINT32_C(0x0267): // LATIN SMALL LETTER HENG WITH HOOK
	case UINT32_C(0x0268): // LATIN SMALL LETTER I WITH STROKE
	case UINT32_C(0x0269): // LATIN SMALL LETTER IOTA
	case UINT32_C(0x026A): // LATIN LETTER SMALL CAPITAL I
	case UINT32_C(0x026B): // LATIN SMALL LETTER L WITH MIDDLE TILDE
	case UINT32_C(0x026C): // LATIN SMALL LETTER L WITH BELT
	case UINT32_C(0x026D): // LATIN SMALL LETTER L WITH RETROFLEX HOOK
	case UINT32_C(0x026E): // LATIN SMALL LETTER LEZH
	case UINT32_C(0x026F): // LATIN SMALL LETTER TURNED M
	case UINT32_C(0x0270): // LATIN SMALL LETTER TURNED M WITH LONG LEG
	case UINT32_C(0x0271): // LATIN SMALL LETTER M WITH HOOK
	case UINT32_C(0x0272): // LATIN SMALL LETTER N WITH LEFT HOOK
	case UINT32_C(0x0273): // LATIN SMALL LETTER N WITH RETROFLEX HOOK
	case UINT32_C(0x0283): // LATIN SMALL LETTER ESH
	case UINT32_C(0x028A): // LATIN SMALL LETTER UPSILON
	case UINT32_C(0x028B): // LATIN SMALL LETTER V WITH HOOK
	case UINT32_C(0x0292): // LATIN SMALL LETTER EZH
	case UINT32_C(0x0294): // LATIN SMALL LETTER GLOTTAL STOP
	case UINT32_C(0x03B1): // GREEK SMALL LETTER ALPHA
	case UINT32_C(0x03B2): // GREEK SMALL LETTER BETA
	case UINT32_C(0x03B3): // GREEK SMALL LETTER GAMMA
	case UINT32_C(0x03B4): // GREEK SMALL LETTER DELTA
	case UINT32_C(0x03B5): // GREEK SMALL LETTER EPSILON
	case UINT32_C(0x03B6): // GREEK SMALL LETTER ZETA
	case UINT32_C(0x03B7): // GREEK SMALL LETTER ETA
	case UINT32_C(0x03B8): // GREEK SMALL LETTER THETA
	case UINT32_C(0x03B9): // GREEK SMALL LETTER IOTA
	case UINT32_C(0x03BA): // GREEK SMALL LETTER KAPPA
	case UINT32_C(0x03BB): // GREEK SMALL LETTER LAMBDA
	case UINT32_C(0x03BC): // GREEK SMALL LETTER MU
	case UINT32_C(0x03BD): // GREEK SMALL LETTER NU
	case UINT32_C(0x03BE): // GREEK SMALL LETTER XI
	case UINT32_C(0x03BF): // GREEK SMALL LETTER OMICRON
	case UINT32_C(0x03C0): // GREEK SMALL LETTER PI
	case UINT32_C(0x03C1): // GREEK SMALL LETTER RHO
	case UINT32_C(0x03C2): // GREEK SMALL LETTER FINAL SIGMA
	case UINT32_C(0x03C3): // GREEK SMALL LETTER SIGMA
	case UINT32_C(0x03C4): // GREEK SMALL LETTER TAU
	case UINT32_C(0x03C5): // GREEK SMALL LETTER UPSILON
	case UINT32_C(0x03C6): // GREEK SMALL LETTER PHI
	case UINT32_C(0x03C7): // GREEK SMALL LETTER CHI
	case UINT32_C(0x03C8): // GREEK SMALL LETTER PSI
	case UINT32_C(0x03C9): // GREEK SMALL LETTER OMEGA
	case UINT32_C(0x1D79): // LATIN SMALL LETTER INSULAR G
	case UINT32_C(0xA7B7): // LATIN SMALL LETTER OMEGA
	case UINT32_C(0xFB00): // LATIN SMALL LIGATURE FF
		return true;
	}
}
