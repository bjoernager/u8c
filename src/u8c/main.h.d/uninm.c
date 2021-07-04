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
# include <u8c/err.h>
# include <u8c/main.h>
# include <u8c/str.h>
# include <uchar.h>
struct u8c_uninm_tuple u8c_uninm(char32_t const _chr) {
	struct u8c_uninm_tuple ret;
	if(_chr > u8c_unimax) {
		u8c_seterr(u8c_errtyp_stroor,U"u8c_uninm: Character out of range.");
		ret.stat = true;
		return ret;
	}
	char32_t const * nm = U"";
	switch(_chr) {
	default:
		nm = U"UNDEFINED IN UNICODE";
		break;
	/* BASIC LATIN: */
	case U'\x0':
		nm = U"NULL";
		break;
	case U'\x1':
		nm = U"START OF HEADING";
		break;
	case U'\x2':
		nm = U"START OF TEXT";
		break;
	case U'\x3':
		nm = U"END OF TEXT";
		break;
	case U'\x4':
		nm = U"END OF TRANSMISSION";
		break;
	case U'\x5':
		nm = U"ENQUIRY";
		break;
	case U'\x6':
		nm = U"ACKNOWLEDGE";
		break;
	case U'\a':
		nm = U"BELL";
		break;
	case U'\b':
		nm = U"BACKSPACE";
		break;
	case U'\t':
		nm = U"HORIZONTAL TABULATION";
		break;
	case U'\n':
		nm = U"NEW LINE";
		break;
	case U'\v':
		nm = U"VERTICAL TABULATION";
		break;
	case U'\f':
		nm = U"FORM FEED";
		break;
	case U'\r':
		nm = U"CARRIAGE RETURN";
		break;
	case U'\xE':
		nm = U"SHIFT OUT";
		break;
	case U'\xF':
		nm = U"SHIFT IN";
		break;
	case U'\x10':
		nm = U"DATA LINK ESCAPE";
		break;
	case U'\x11':
		nm = U"DEVICE CONTROL ONE";
		break;
	case U'\x12':
		nm = U"DEVICE CONTROL TWO";
		break;
	case U'\x13':
		nm = U"DEVICE CONTROL THREE";
		break;
	case U'\x14':
		nm = U"DEVICE CONTROL FOUR";
		break;
	case U'\x15':
		nm = U"NEGATIVE ACKNOWLEDGE";
		break;
	case U'\x16':
		nm = U"SYNCHRONOUS IDLE";
		break;
	case U'\x17':
		nm = U"END OF TRANSMISSION BLOCk";
		break;
	case U'\x18':
		nm = U"CANCEL";
		break;
	case U'\x19':
		nm = U"END OF MEDIUM";
		break;
	case U'\x1A':
		nm = U"SUBSTITUTE";
		break;
	case U'\x1B':
		nm = U"ESCAPE";
		break;
	case U'\x1C':
		nm = U"FILE SEPERATOR";
		break;
	case U'\x1D':
		nm = U"GROUP SEPERATOR";
		break;
	case U'\x1E':
		nm = U"RECORD SEPERATOR";
		break;
	case U'\x1F':
		nm = U"UNIT SEPERATOR";
		break;
	case U' ':
		nm = U"SPACE";
		break;
	case U'!':
		nm = U"EXCLAMATION MARK";
		break;
	case U'\"':
		nm = U"QUOTATION MARK";
		break;
	case U'#':
		nm = U"NUMBER SIGN";
		break;
	case U'\u0024':
		nm = U"DOLLAR SIGN";
		break;
	case U'%':
		nm = U"PERCENT SIGN";
		break;
	case U'&':
		nm = U"AMPERSAND";
		break;
	case U'\'':
		nm = U"APOSTROPHE";
		break;
	case U'(':
		nm = U"LEFT PARANTHESIS";
		break;
	case U')':
		nm = U"RIGHT PARANTHESIS";
		break;
	case U'*':
		nm = U"ASTERISK";
		break;
	case U'+':
		nm = U"PLUS SIGN";
		break;
	case U',':
		nm = U"COMMA";
		break;
	case U'-':
		nm = U"HYPHEN-MINUS";
		break;
	case U'.':
		nm = U"FULL STOP";
		break;
	case U'/':
		nm = U"SOLIDUS";
		break;
	case U'0':
		nm = U"DIGIT ZERO";
		break;
	case U'1':
		nm = U"DIGIT ONE";
		break;
	case U'2':
		nm = U"DIGIT TWO";
		break;
	case U'3':
		nm = U"DIGIT THREE";
		break;
	case U'4':
		nm = U"DIGIT FOUR";
		break;
	case U'5':
		nm = U"DIGIT FIVE";
		break;
	case U'6':
		nm = U"DIGIT SIX";
		break;
	case U'7':
		nm = U"DIGIT SEVEN";
		break;
	case U'8':
		nm = U"DIGIT EIGHT";
		break;
	case U'9':
		nm = U"DIGIT NINE";
		break;
	case U':':
		nm = U"COLON";
		break;
	case U';':
		nm = U"SEMICOLON";
		break;
	case U'<':
		nm = U"LESS-THAN SIGN";
		break;
	case U'=':
		nm = U"EQUALS SIGN";
		break;
	case U'>':
		nm = U"GREATER-THAN SIGN";
		break;
	case U'?':
		nm = U"QUESTION MARK";
		break;
	case U'\u0040':
		nm = U"COMMERCIAL AT";
		break;
	case U'A':
		nm = U"LATIN CAPITAL LETTER A";
		break;
	case U'B':
		nm = U"LATIN CAPITAL LETTER B";
		break;
	case U'C':
		nm = U"LATIN CAPITAL LETTER C";
		break;
	case U'D':
		nm = U"LATIN CAPITAL LETTER D";
		break;
	case U'E':
		nm = U"LATIN CAPITAL LETTER E";
		break;
	case U'F':
		nm = U"LATIN CAPITAL LETTER F";
		break;
	case U'G':
		nm = U"LATIN CAPITAL LETTER G";
		break;
	case U'H':
		nm = U"LATIN CAPITAL LETTER H";
		break;
	case U'I':
		nm = U"LATIN CAPITAL LETTER I";
		break;
	case U'J':
		nm = U"LATIN CAPITAL LETTER J";
		break;
	case U'K':
		nm = U"LATIN CAPITAL LETTER K";
		break;
	case U'L':
		nm = U"LATIN CAPITAL LETTER L";
		break;
	case U'M':
		nm = U"LATIN CAPITAL LETTER M";
		break;
	case U'N':
		nm = U"LATIN CAPITAL LETTER N";
		break;
	case U'O':
		nm = U"LATIN CAPITAL LETTER O";
		break;
	case U'P':
		nm = U"LATIN CAPITAL LETTER P";
		break;
	case U'Q':
		nm = U"LATIN CAPITAL LETTER Q";
		break;
	case U'R':
		nm = U"LATIN CAPITAL LETTER R";
		break;
	case U'S':
		nm = U"LATIN CAPITAL LETTER S";
		break;
	case U'T':
		nm = U"LATIN CAPITAL LETTER T";
		break;
	case U'U':
		nm = U"LATIN CAPITAL LETTER U";
		break;
	case U'V':
		nm = U"LATIN CAPITAL LETTER V";
		break;
	case U'W':
		nm = U"LATIN CAPITAL LETTER W";
		break;
	case U'X':
		nm = U"LATIN CAPITAL LETTER X";
		break;
	case U'Y':
		nm = U"LATIN CAPITAL LETTER Y";
		break;
	case U'Z':
		nm = U"LATIN CAPITAL LETTER Z";
		break;
	case U'[':
		nm = U"LEFT SQUARE BRACKET";
		break;
	case U'\\':
		nm = U"REVERSE SOLIDUS";
		break;
	case U']':
		nm = U"RIGHT SQUARE BRACKET";
		break;
	case U'^':
		nm = U"CIRCUMFLEX ACCENT";
		break;
	case U'_':
		nm = U"LOW LINE";
		break;
	case U'\u0060':
		nm = U"GRAVE ACCENT";
		break;
	case U'a':
		nm = U"LATIN SMALL LETTER A";
		break;
	case U'b':
		nm = U"LATIN SMALL LETTER B";
		break;
	case U'c':
		nm = U"LATIN SMALL LETTER C";
		break;
	case U'd':
		nm = U"LATIN SMALL LETTER D";
		break;
	case U'e':
		nm = U"LATIN SMALL LETTER E";
		break;
	case U'f':
		nm = U"LATIN SMALL LETTER F";
		break;
	case U'g':
		nm = U"LATIN SMALL LETTER G";
		break;
	case U'h':
		nm = U"LATIN SMALL LETTER H";
		break;
	case U'i':
		nm = U"LATIN SMALL LETTER I";
		break;
	case U'j':
		nm = U"LATIN SMALL LETTER J";
		break;
	case U'k':
		nm = U"LATIN SMALL LETTER K";
		break;
	case U'l':
		nm = U"LATIN SMALL LETTER L";
		break;
	case U'm':
		nm = U"LATIN SMALL LETTER M";
		break;
	case U'n':
		nm = U"LATIN SMALL LETTER N";
		break;
	case U'o':
		nm = U"LATIN SMALL LETTER O";
		break;
	case U'p':
		nm = U"LATIN SMALL LETTER P";
		break;
	case U'q':
		nm = U"LATIN SMALL LETTER Q";
		break;
	case U'r':
		nm = U"LATIN SMALL LETTER R";
		break;
	case U's':
		nm = U"LATIN SMALL LETTER S";
		break;
	case U't':
		nm = U"LATIN SMALL LETTER T";
		break;
	case U'u':
		nm = U"LATIN SMALL LETTER U";
		break;
	case U'v':
		nm = U"LATIN SMALL LETTER V";
		break;
	case U'w':
		nm = U"LATIN SMALL LETTER W";
		break;
	case U'x':
		nm = U"LATIN SMALL LETTER X";
		break;
	case U'y':
		nm = U"LATIN SMALL LETTER Y";
		break;
	case U'z':
		nm = U"LATIN SMALL LETTER Z";
		break;
	case U'{':
		nm = U"LEFT CURLY BRACKET";
		break;
	case U'|':
		nm = U"VERTICAL LINE";
		break;
	case U'}':
		nm = U"RIGHT CURLY BRACKET";
		break;
	case U'~':
		nm = U"TILDE";
		break;
	case U'\x7F':
		nm = U"DELETE";
		break;
	/* LATIN-1 SUPPLEMENT: */
	case U'\x80':
		nm = U"<CONTROL>";
		break;
	case U'\x81':
		nm = U"<CONTROL>";
		break;
	case U'\x82':
		nm = U"BREAK PERMITTED HERE";
		break;
	case U'\x83':
		nm = U"NO BREAK HERE";
		break;
	case U'\x84':
		nm = U"<CONTROL>";
		break;
	case U'\x85':
		nm = U"NEXT LINE";
		break;
	case U'\x86':
		nm = U"START OF SELECTED AREA";
		break;
	case U'\x87':
		nm = U"END OF SELECTED AREA";
		break;
	case U'\x88':
		nm = U"CHARACTER TABULATION SET";
		break;
	case U'\x89':
		nm = U"CHARACTER TABULATION WITH JUSTIFICATION";
		break;
	case U'\x8A':
		nm = U"LINE TABULATION SET";
		break;
	case U'\x8B':
		nm = U"PARTIAL LINE FORWARD";
		break;
	case U'\x8C':
		nm = U"PARTIAL LINE BACKWARD";
		break;
	case U'\x8D':
		nm = U"REVERSE LINE FEED";
		break;
	case U'\x8E':
		nm = U"SINGLE SHIFT TWO";
		break;
	case U'\x8F':
		nm = U"SINGLE SHIFT THREE";
		break;
	case U'\x90':
		nm = U"DEVICE CONTROL STRING";
		break;
	case U'\x91':
		nm = U"PRIVATE USE ONE";
		break;
	case U'\x92':
		nm = U"PRIVATE USE TWO";
		break;
	case U'\x93':
		nm = U"SET TRANSMIT STATE";
		break;
	case U'\x94':
		nm = U"CANCEL CHARACTER";
		break;
	case U'\x95':
		nm = U"MESSAGE WAITING";
		break;
	case U'\x96':
		nm = U"START OF GUARDED AREA";
		break;
	case U'\x97':
		nm = U"END OF GUARDED AREA";
		break;
	case U'\x98':
		nm = U"START OF STRING";
		break;
	case U'\x99':
		nm = U"<CONTROL>";
		break;
	case U'\x9A':
		nm = U"SINGLE CHARACTER INTRODUCER";
		break;
	case U'\x9B':
		nm = U"CONTROL SEQUENCE INTRODUCER";
		break;
	case U'\x9C':
		nm = U"STRING TERMINATOR";
		break;
	case U'\x9D':
		nm = U"OPERATING SYSTEM COMMAND";
		break;
	case U'\x9E':
		nm = U"PRIVACY MESSAGE";
		break;
	case U'\x9F':
		nm = U"APPLICATION PROGRAM COMMAND";
		break;
	case U'\xA0':
		nm = U"NO-BREAK SPACE";
		break;
	case U'\u00A1':
		nm = U"INVERTED EXCLAMATION MARK";
		break;
	case U'\u00A2':
		nm = U"CENT SIGN";
		break;
	case U'\u00A3':
		nm = U"POUND SIGN";
		break;
	case U'\u00A4':
		nm = U"CURRENCY SIGN";
		break;
	case U'\u00A5':
		nm = U"YEN SIGN";
		break;
	case U'\u00A6':
		nm = U"BROKEN BAR";
		break;
	case U'\u00A7':
		nm = U"SECTION SIGN";
		break;
	case U'\u00A8':
		nm = U"DIAERESIS";
		break;
	case U'\u00A9':
		nm = U"COPYRIGHT SIGN";
		break;
	case U'\u00AA':
		nm = U"FEMININE ORDINAL INDICATOR";
		break;
	case U'\u00AB':
		nm = U"LEFT-POINTING DOUBLE ANGLE QUOTATION MARK";
		break;
	case U'\u00AC':
		nm = U"NOT SIGN";
		break;
	case U'\u00AD':
		nm = U"SOFT HYPHEN";
		break;
	case U'\u00AE':
		nm = U"REGISTERED SIGN";
		break;
	case U'\u00AF':
		nm = U"MACRON";
		break;
	case U'\u00B0':
		nm = U"DEGREE SIGN";
		break;
	case U'\u00B1':
		nm = U"PLUS MINUS SYMBOL";
		break;
	case U'\u00B2':
		nm = U"SUPERSCRIPT TWO";
		break;
	case U'\u00B3':
		nm = U"SUPERSCRIPT THREE";
		break;
	case U'\u00B4':
		nm = U"ACUTE ACCENT";
		break;
	case U'\u00B5':
		nm = U"MICRO SIGN";
		break;
	case U'\u00B6':
		nm = U"PILCROW SIGN";
		break;
	case U'\u00B7':
		nm = U"MIDDLE DOT";
		break;
	case U'\u00B8':
		nm = U"CEDILLA";
		break;
	case U'\u00B9':
		nm = U"SUPERSCRIPT ONE";
		break;
	case U'\u00BA':
		nm = U"MASCULINE ORDINAL INDICATOR";
		break;
	case U'\u00BB':
		nm = U"RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK";
		break;
	case U'\u00BC':
		nm = U"VULGAR FRACTION ONE QUARTER";
		break;
	case U'\u00BD':
		nm = U"VULGAR FRACTION ONE HALF";
		break;
	case U'\u00BE':
		nm = U"VULGAR FRACTION THREE QUARTERS";
		break;
	case U'\u00BF':
		nm = U"INVERTED QUESTION MARK";
		break;
	case U'\u00C0':
		nm = U"LATIN CAPITAL LETTER A WITH GRAVE";
		break;
	case U'\u00C1':
		nm = U"LATIN CAPITAL LETTER A WITH ACUTE";
		break;
	case U'\u00C2':
		nm = U"LATIN CAPITAL LETTER A WITH CIRCUMFLEX";
		break;
	case U'\u00C3':
		nm = U"LATIN CAPITAL LETTER A WITH TILDE";
		break;
	case U'\u00C4':
		nm = U"LATIN CAPITAL LETTER A WITH DIAERESIS";
		break;
	case U'\u00C5':
		nm = U"LATIN CAPITAL LETTER A WITH RING ABOVE";
		break;
	case U'\u00C6':
		nm = U"LATIN CAPITAL LETTER AE";
		break;
	case U'\u00C7':
		nm = U"LATIN CAPITAL LETTER C WITH CEDILLA";
		break;
	case U'\u00C8':
		nm = U"LATIN CAPITAL LETTER E WITH GRAVE";
		break;
	case U'\u00C9':
		nm = U"LATIN CAPITAL LETTER E WITH ACUTE";
		break;
	case U'\u00CA':
		nm = U"LATIN CAPITAL LETTER E WITH CIRCUMFLEX";
		break;
	case U'\u00CB':
		nm = U"LATIN CAPITAL LETTER E WITH DIAERESIS";
		break;
	case U'\u00CC':
		nm = U"LATIN CAPITAL LETTER I WITH GRAVE";
		break;
	case U'\u00CD':
		nm = U"LATIN CAPITAL LETTER I WITH ACUTE";
		break;
	case U'\u00CE':
		nm = U"LATIN CAPITAL LETTER I WITH CIRCUMFLEX";
		break;
	case U'\u00CF':
		nm = U"LATIN CAPITAL LETTER I WITH DIAERESIS";
		break;
	case U'\u00D0':
		nm = U"LATIN CAPITAL LETTER ETH";
		break;
	case U'\u00D1':
		nm = U"LATIN CAPITAL LETTER N WITH TILDE";
		break;
	case U'\u00D2':
		nm = U"LATIN CAPITAL LETTER O WITH GRAVE";
		break;
	case U'\u00D3':
		nm = U"LATIN CAPITAL LETTER O WITH ACUTE";
		break;
	case U'\u00D4':
		nm = U"LATIN CAPITAL LETTER O WITH CIRCUMFLEX";
		break;
	case U'\u00D5':
		nm = U"LATIN CAPITAL LETTER O WITH TILDE";
		break;
	case U'\u00D6':
		nm = U"LATIN CAPITAL LETTER O WITH DIAERESIS";
		break;
	case U'\u00D7':
		nm = U"MULTIPLICATION SIGN";
		break;
	case U'\u00D8':
		nm = U"LATIN CAPITAL LETTER O WITH STROKE";
		break;
	case U'\u00D9':
		nm = U"LATIN CAPITAL LETTER U WITH GRAVE";
		break;
	case U'\u00DA':
		nm = U"LATIN CAPITAL LETTER U WITH ACUTE";
		break;
	case U'\u00DB':
		nm = U"LATIN CAPITAL LETTER U WITH CIRCUMFLEX";
		break;
	case U'\u00DC':
		nm = U"LATIN CAPITAL LETTER U WITH DIAERESIS";
		break;
	case U'\u00DD':
		nm = U"LATIN CAPITAL LETTER Y WITH ACUTE";
		break;
	case U'\u00DE':
		nm = U"LATIN CAPITAL LETTER THORN";
		break;
	case U'\u00DF':
		nm = U"LATIN SMALL LETTER SHARP S";
		break;
	case U'\u00E0':
		nm = U"LATIN SMALL LETTER A WITH GRAVE";
		break;
	case U'\u00E1':
		nm = U"LATIN SMALL LETTER A WITH ACUTE";
		break;
	case U'\u00E2':
		nm = U"LATIN SMALL LETTER A WITH CIRCUMFLEX";
		break;
	case U'\u00E3':
		nm = U"LATIN SMALL LETTER A WITH TILDE";
		break;
	case U'\u00E4':
		nm = U"LATIN SMALL LETTER A WITH DIAERESIS";
		break;
	case U'\u00E5':
		nm = U"LATIN SMALL LETTER A WITH RING ABOVE";
		break;
	case U'\u00E6':
		nm = U"LATIN SMALL LETTER AE";
		break;
	case U'\u00E7':
		nm = U"LATIN SMALL LETTER C WITH CEDILLA";
		break;
	case U'\u00E8':
		nm = U"LATIN SMALL LETTER E WITH GRAVE";
		break;
	case U'\u00E9':
		nm = U"LATIN SMALL LETTER E WITH ACUTE";
		break;
	case U'\u00EA':
		nm = U"LATIN SMALL LETTER E WITH CIRCUMFLEX";
		break;
	case U'\u00EB':
		nm = U"LATIN SMALL LETTER E WITH DIAERESIS";
		break;
	case U'\u00EC':
		nm = U"LATIN SMALL LETTER I WITH GRAVE";
		break;
	case U'\u00ED':
		nm = U"LATIN SMALL LETTER I WITH ACUTE";
		break;
	case U'\u00EE':
		nm = U"LATIN SMALL LETTER I WITH CIRCUMFLEX";
		break;
	case U'\u00EF':
		nm = U"LATIN SMALL LETTER I WITH DIAERESIS";
		break;
	case U'\u00F0':
		nm = U"LATIN SMALL LETTER ETH";
		break;
	case U'\u00F1':
		nm = U"LATIN SMALL LETTER N WITH TILDE";
		break;
	case U'\u00F2':
		nm = U"LATIN SMALL LETTER O WITH GRAVE";
		break;
	case U'\u00F3':
		nm = U"LATIN SMALL LETTER O WITH ACUTE";
		break;
	case U'\u00F4':
		nm = U"LATIN SMALL LETTER O WITH CIRCUMFLEX";
		break;
	case U'\u00F5':
		nm = U"LATIN SMALL LETTER O WITH TILDE";
		break;
	case U'\u00F6':
		nm = U"LATIN SMALL LETTER O WITH DIAERESIS";
		break;
	case U'\u00F7':
		nm = U"DIVISION SIGN";
		break;
	case U'\u00F8':
		nm = U"LATIN SMALL LETTER O WITH STROKE";
		break;
	case U'\u00F9':
		nm = U"LATIN SMALL LETTER U WITH GRAVE";
		break;
	case U'\u00FA':
		nm = U"LATIN SMALL LETTER U WITH ACUTE";
		break;
	case U'\u00FB':
		nm = U"LATIN SMALL LETTER U WITH CIRCUMFLEX";
		break;
	case U'\u00FC':
		nm = U"U WITH TWO DOTS";
		break;
	case U'\u00FD':
		nm = U"LATIN SMALL LETTER Y WITH ACUTE";
		break;
	case U'\u00FE':
		nm = U"LATIN SMALL LETTER THORN";
		break;
	case U'\u00FF':
		nm = U"LATIN SMALL LETTER Y WITH DIAERESIS";
		break;
	/* LATIN EXTENDED-A: */
	case U'\u0100':
		nm = U"LATIN CAPITAL LETTER A WITH MACRON";
		break;
	case U'\u0101':
		nm = U"LATIN SMALL LETTER A WITH MACRON";
		break;
	case U'\u0102':
		nm = U"LATIN CAPITAL LETTER A WITH BREVE";
		break;
	case U'\u0103':
		nm = U"LATIN SMALL LETTER A WITH BREVE";
		break;
	case U'\u0104':
		nm = U"LATIN CAPITAL LETTER A WITH OGONEK";
		break;
	case U'\u0105':
		nm = U"LATIN SMALL LETTER A WITH OGONEK";
		break;
	case U'\u0106':
		nm = U"LATIN CAPITAL LETTER C WITH ACUTE";
		break;
	case U'\u0107':
		nm = U"LATIN SMALL LETTER C WITH ACUTE";
		break;
	case U'\u0108':
		nm = U"LATIN CAPITAL LETTER C WITH CIRCUMFLEX";
		break;
	case U'\u0109':
		nm = U"LATIN SMALL LETTER C WITH CIRCUMFLEX";
		break;
	case U'\u010A':
		nm = U"LATIN CAPITAL LETTER C WITH DOT ABOVE";
		break;
	case U'\u010B':
		nm = U"LATIN SMALL LETTER C WITH DOT ABOVE";
		break;
	case U'\u010C':
		nm = U"LATIN CAPITAL LETTER C WITH CARON";
		break;
	case U'\u010D':
		nm = U"LATIN SMALL LETTER C WITH CARON";
		break;
	case U'\u010E':
		nm = U"LATIN CAPITAL LETTER D WITH CARON";
		break;
	case U'\u010F':
		nm = U"LATIN SMALL LETTER D WITH CARON";
		break;
	case U'\u0110':
		nm = U"LATIN CAPITAL LETTER D WITH STROKE";
		break;
	case U'\u0120':
		nm = U"LATIN CAPITAL LETTER G WITH DOT ABOVE";
		break;
	case U'\u0130':
		nm = U"LATIN CAPITAL LETTER I WITH DOT ABOVE";
		break;
	case U'\u0140':
		nm = U"LATIN SMALL LETTER L WITH MIDDLE DOT";
		break;
	case U'\u0150':
		nm = U"LATIN CAPITAL LETTER O WITH DOUBLE ACUTE";
		break;
	case U'\u0160':
		nm = U"LATIN CAPITAL LETTER S WITH CARON";
		break;
	case U'\u0170':
		nm = U"LATIN CAPITAL LETTER U WITH DOUBLE ACUTE";
		break;
	/* LATIN EXTENDED-B: */
	case U'\u0180':
		nm = U"LATIN SMALL LETTER B WITH STROKE";
		break;
	case U'\u0190':
		nm = U"LATIN CAPITAL LETTER OPEN E";
		break;
	case U'\u01A0':
		nm = U"LATIN CAPITAL LETTER O WITH HORN";
		break;
	case U'\u01B0':
		nm = U"LATIN SMALL LETTER U WITH HORN";
		break;
	case U'\u01C0':
		nm = U"LATIN LETTER DENTAL CLICK";
		break;
	case U'\u01D0':
		nm = U"LATIN SMALL LETTER I WITH CARON";
		break;
	case U'\u01E0':
		nm = U"LATIN CAPITAL LETTER A WITH DOT ABOVE AND MACRON";
		break;
	case U'\u01F0':
		nm = U"LATIN SMALL LETTER J WITH CARON";
		break;
	case U'\u0200':
		nm = U"LATIN CAPITAL LETTER A WITH DOUBLE GRAVE";
		break;
	case U'\u0210':
		nm = U"LATIN CAPITAL LETTER R WITH DOUBLE GRAVE";
		break;
	case U'\u0220':
		nm = U"LATIN CAPITAL LETTER N WITH LONG RIGHT LEG";
		break;
	case U'\u0230':
		nm = U"LATIN CAPITAL LETTER O WITH DOT ABOVE AND MACRON";
		break;
	case U'\u0240':
		nm = U"LATIN SMALL LETTER Z WITH SWASH TAIL";
		break;
	/* IPA EXTENSIONS: */
	case U'\u0250':
		nm = U"LATIN SMALL LETTER TURNED A";
		break;
	case U'\u0251':
		nm = U"LATIN SMALL LETTER ALPHA";
		break;
	case U'\u0252':
		nm = U"LATIN SMALL LETTER TURNED ALPHA";
		break;
	case U'\u0253':
		nm = U"LATIN SMALL LETTER B WITH HOOK";
		break;
	case U'\u0254':
		nm = U"LATIN SMALL LETTER OPEN O";
		break;
	case U'\u0255':
		nm = U"LATIN SMALL LETTER C WITH CURL";
		break;
	case U'\u0256':
		nm = U"LATIN SMALL LETTER D WITH TAIL";
		break;
	case U'\u0257':
		nm = U"LATIN SMALL LETTER D WITH HOOK";
		break;
	case U'\u0258':
		nm = U"LATIN SMALL LETTER REVERSED E";
		break;
	case U'\u0259':
		nm = U"LATIN SMALL LETTER SCHWA";
		break;
	case U'\u025A':
		nm = U"LATIN SMALL LETTER SCHWA WITH HOOK";
		break;
	case U'\u025B':
		nm = U"LATIN SMALL LETTER OPEN E";
		break;
	case U'\u025C':
		nm = U"LATIN SMALL LETTER REVERSED OPEN E";
		break;
	case U'\u025D':
		nm = U"LATIN SMALL LETTER REVERSED OPEN E WITH HOOK";
		break;
	case U'\u025E':
		nm = U"LATIN SMALL LETTER CLOSED REVERSED OPEN E";
		break;
	case U'\u025F':
		nm = U"LATIN SMALL LETTER DOTLESS J WITH STROKE";
		break;
	case U'\u0260':
		nm = U"LATIN SMALL LETTER G WITH HOOK";
		break;
	case U'\u0261':
		nm = U"LATIN SMALL LETTER SCRIPT G";
		break;
	case U'\u0262':
		nm = U"LATIN LETTER SMALL CAPITAL G";
		break;
	case U'\u0263':
		nm = U"LATIN SMALL LETTER GAMMA";
		break;
	case U'\u0264':
		nm = U"LATIN SMALL LETTER RAMS HORN";
		break;
	case U'\u0265':
		nm = U"LATIN SMALL LETTER TURNED H";
		break;
	case U'\u0266':
		nm = U"LATIN SMALL LETTER H WITH HOOK";
		break;
	case U'\u0267':
		nm = U"LATIN SMALL LETTER HENG WITH HOOK";
		break;
	case U'\u0268':
		nm = U"LATIN SMALL LETTER I WITH STROKE";
		break;
	case U'\u0269':
		nm = U"LATIN SMALL LETTER IOTA";
		break;
	case U'\u026A':
		nm = U"LATIN LETTER SMALL CAPITAL I";
		break;
	case U'\u026B':
		nm = U"LATIN SMALL LETTER L WITH MIDDLE TILDE";
		break;
	case U'\u026C':
		nm = U"LATIN SMALL LETTER L WITH BELT";
		break;
	case U'\u026D':
		nm = U"LATIN SMALL LETTER L WITH RETROFLEX HOOK";
		break;
	case U'\u026E':
		nm = U"LATIN SMALL LETTER LEZH";
		break;
	case U'\u026F':
		nm = U"LATIN SMALL LETTER TURNED M";
		break;
	case U'\u0270':
		nm = U"LATIN SMALL LETTER TURNED M WITH LONG LEG";
		break;
	case U'\u0271':
		nm = U"LATIN SMALL LETTER M WITH HOOK";
		break;
	case U'\u0272':
		nm = U"LATIN SMALL LETTER N WITH LEFT HOOK";
		break;
	case U'\u0273':
		nm = U"LATIN SMALL LETTER N WITH RETROFLEX HOOK";
		break;
	case U'\u0274':
		nm = U"LATIN LETTER SMALL CAPITAL N";
		break;
	case U'\u0275':
		nm = U"LATIN SMALL LETTER BARRED O";
		break;
	case U'\u0276':
		nm = U"LATIN LETTER SMALL CAPITAL OE";
		break;
	case U'\u0277':
		nm = U"LATIN SMALL LETTER CLOSED OMEGA";
		break;
	case U'\u0278':
		nm = U"LATIN SMALL LETTER PHI";
		break;
	case U'\u0279':
		nm = U"LATIN SMALL LETTER TURNED R";
		break;
	case U'\u027A':
		nm = U"LATIN SMALL LETTER TURNED R WITH LONG LEG";
		break;
	case U'\u027B':
		nm = U"LATIN SMALL LETTER TURNED R WITH HOOK";
		break;
	case U'\u027C':
		nm = U"LATIN SMALL LETTER R WITH LONG LEG";
		break;
	case U'\u027D':
		nm = U"LATIN SMALL LETTER R WITH TAIL";
		break;
	case U'\u027E':
		nm = U"LATIN SMALL LETTER R WITH FISHHOOK";
		break;
	case U'\u027F':
		nm = U"LATIN SMALL LETTER REVERSED R WITH FISHHOOK";
		break;
	case U'\u0280':
		nm = U"LATIN LETTER SMALL CAPITAL R";
		break;
	/* GREEK AND COPTIC: */
	case U'\u0370':
		nm = U"GREEK CAPITAL LETTER HETA";
		break;
	case U'\u0371':
		nm = U"GREEK SMALL LETTER HETA";
		break;
	case U'\u0372':
		nm = U"GREEK CAPITAL LETTER ARCHAIC SAMPI";
		break;
	case U'\u0373':
		nm = U"GREEK SMALL LETTER ARCHAIC SAMPI";
		break;
	case U'\u0374':
		nm = U"GREEK NUMERAL SIGN";
		break;
	case U'\u0375':
		nm = U"GREEK LOWER NUMERAL SIGN";
		break;
	case U'\u0376':
		nm = U"GREEK CAPITAL LETTER PAMPHYLIAN DIGAMMA";
		break;
	case U'\u0377':
		nm = U"GREEK SMALL LETTER PAMPHYLIAN DIGAMMA";
		break;
	case U'\u037A':
		nm = U"GREEK YPOGEGRAMMENI";
		break;
	case U'\u037B':
		nm = U"GREEK SMALL REVERSED LUNATE SIGMA SYMBOL";
		break;
	case U'\u037C':
		nm = U"GREEK SMALL DOTTED LUNATE SIGMA SYMBOL";
		break;
	case U'\u037D':
		nm = U"GREEK SMALL REVERSED DOTTED LUNATE SIGMAL SYMBOL";
		break;
	case U'\u037E':
		nm = U"GREEK QUESTION MARK";
		break;
	case U'\u037F':
		nm = U"GREEK CAPITAL LETTER YOT";
		break;
	case U'\u0384':
		nm = U"GREEK TONOS";
		break;
	case U'\u0385':
		nm = U"GREEK DIALYTIKA TONOS";
		break;
	case U'\u0386':
		nm = U"GREEK CAPITAL LETTER ALPHA WITH TONOS";
		break;
	case U'\u0387':
		nm = U"GREEK ANO TELEIA";
		break;
	case U'\u0388':
		nm = U"GREEK CAPITAL LETTER EPSILON WITH TONOS";
		break;
	case U'\u0389':
		nm = U"GREEK CAPITAL LETTER ETA WITH TONOS";
		break;
	case U'\u038A':
		nm = U"GREEK CAPITAL LETTER IOTA WITH TONOS";
		break;
	case U'\u038C':
		nm = U"GREEK CAPITAL LETTER OMICRON WITH TONOS";
		break;
	case U'\u038E':
		nm = U"GREEK CAPITAL LETTER USPILON WITH TONOS";
		break;
	case U'\u038F':
		nm = U"GREEK CAPITAL LETTER OMEGA WITH TONOS";
		break;
	case U'\u0390':
		nm = U"GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS";
		break;
	case U'\u0391':
		nm = U"GREEK CAPITAL LETTER ALPHA";
		break;
	case U'\u0392':
		nm = U"GREEK CAPITAL LETTER BETA";
		break;
	case U'\u0393':
		nm = U"GREEK CAPITAL LETTER GAMMA";
		break;
	case U'\u0394':
		nm = U"GREEK CAPITAL LETTER DELTA";
		break;
	case U'\u0395':
		nm = U"GREEK CAPITAL LETTER EPSILON";
		break;
	case U'\u0396':
		nm = U"GREEK CAPITAL LETTER ZETA";
		break;
	case U'\u0397':
		nm = U"GREEK CAPITAL LETTER ETA";
		break;
	case U'\u0398':
		nm = U"GREEK CAPITAL LETTER THETA";
		break;
	case U'\u0399':
		nm = U"GREEK CAPITAL LETTER IOTA";
		break;
	case U'\u039A':
		nm = U"GREEK CAPITAL LETTER KAPPA";
		break;
	case U'\u039B':
		nm = U"GREEK CAPITAL LETTER LAMBDA";
		break;
	case U'\u039C':
		nm = U"GREEK CAPITAL LETTER MU";
		break;
	case U'\u039D':
		nm = U"GREEK CAPITAL LETTER NU";
		break;
	case U'\u039E':
		nm = U"GREEK CAPITAL LETTER XI";
		break;
	case U'\u039F':
		nm = U"GREEK CAPITAL LETTER OMICRON";
		break;
	case U'\u03A0':
		nm = U"GREEK CAPITAL LETTER PI";
		break;
	case U'\u03A1':
		nm = U"GREEK CAPITAL LETTER RHO";
		break;
	case U'\u03A3':
		nm = U"GREEK CAPITAL LETTER SIGMA";
		break;
	case U'\u03A4':
		nm = U"GREEK CAPITAL LETTER TAU";
		break;
	case U'\u03A5':
		nm = U"GREEK CAPITAL LETTER UPSILON";
		break;
	case U'\u03A6':
		nm = U"GREEK CAPITAL LETTER PHI";
		break;
	case U'\u03A7':
		nm = U"GREEK CAPITAL LETTER CHI";
		break;
	case U'\u03A8':
		nm = U"GREEK CAPITAL LETTER PSI";
		break;
	case U'\u03A9':
		nm = U"GREEK CAPITAL LETTER OMEGA";
		break;
	case U'\u03AA':
		nm = U"GREEK CAPITAL LETTER IOTA WITH DIALYTIKA";
		break;
	case U'\u03AB':
		nm = U"GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA";
		break;
	case U'\u03AC':
		nm = U"GREEK SMALL LETTER ALPHA WITH TONOS";
		break;
	case U'\u03AD':
		nm = U"GREEK SMALL LETTER EPSILON WITH TONOS";
		break;
	case U'\u03AE':
		nm = U"GREEK SMALL LETTER ETA WITH TONOS";
		break;
	case U'\u03AF':
		nm = U"GREEK SMALL LETTER IOTA WITH TONOS";
		break;
	case U'\u03B0':
		nm = U"GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS";
		break;
	case U'\u03B1':
		nm = U"GREEK SMALL LETTER ALPHA";
		break;
	case U'\u03B2':
		nm = U"GREEK SMALL LETTER BETA";
		break;
	case U'\u03B3':
		nm = U"GREEK SMALL LETTER GAMMA";
		break;
	case U'\u03B4':
		nm = U"GREEK SMALL LETTER DELTA";
		break;
	case U'\u03B5':
		nm = U"GREEK SMALL LETTER EPSILON";
		break;
	case U'\u03B6':
		nm = U"GREEK SMALL LETTER ZETA";
		break;
	case U'\u03B7':
		nm = U"GREEK SMALL LETTER ETA";
		break;
	case U'\u03B8':
		nm = U"GREEK SMALL LETTER THETA";
		break;
	case U'\u03B9':
		nm = U"GREEK SMALL LETTER IOTA";
		break;
	case U'\u03BA':
		nm = U"GREEK SMALL LETTER KAPPA";
		break;
	case U'\u03BB':
		nm = U"GREEK SMALL LETTER LAMBDA";
		break;
	case U'\u03BC':
		nm = U"GREEK SMALL LETTER MU";
		break;
	case U'\u03BD':
		nm = U"GREEK SMALL LETTER NU";
		break;
	case U'\u03BE':
		nm = U"GREEK SMALL LETTER XI";
		break;
	case U'\u03BF':
		nm = U"GREEK SMALL LETTER OMICRON";
		break;
	case U'\u03C0':
		nm = U"GREEK SMALL LETTER PI";
		break;
	case U'\u03C1':
		nm = U"GREEK SMALL LETTER RHO";
		break;
	case U'\u03C2':
		nm = U"GREEK SMALL LETTER FINAL SIGMA";
		break;
	case U'\u03C3':
		nm = U"GREEK SMALL LETTER SIGMA";
		break;
	case U'\u03C4':
		nm = U"GREEK SMALL LETTER TAU";
		break;
	case U'\u03C5':
		nm = U"GREEK SMALL LETTER UPSILON";
		break;
	case U'\u03C6':
		nm = U"GREEK SMALL LETTER PHI";
		break;
	case U'\u03C7':
		nm = U"GREEK SMALL LETTER CHI";
		break;
	case U'\u03C8':
		nm = U"GREEK SMALL LETTER PSI";
		break;
	case U'\u03C9':
		nm = U"GREEK SMALL LETTER OMEGA";
		break;
	case U'\u03CA':
		nm = U"GREEK SMALL LETTER IOTA WITH DIALYTIKA";
		break;
	case U'\u03CB':
		nm = U"GREEK SMALL LETTER UPSILON WITH DIALYTIKA";
		break;
	case U'\u03CC':
		nm = U"GREEK SMALL LETTER OMICRON WITH TONOS";
		break;
	case U'\u03CD':
		nm = U"GREEK SMALL LETTER UPSILON WITH TONOS";
		break;
	case U'\u03CE':
		nm = U"GREEK SMALL LETTER OMEGA WITH TONOS";
		break;
	case U'\u03CF':
		nm = U"GREEK CAPITAL KAI SYMBOL";
		break;
	case U'\u03D0':
		nm = U"GREEK BETA SYMBOL";
		break;
	case U'\u03D1':
		nm = U"GREEK THETA SYMBOL";
		break;
	case U'\u03D2':
		nm = U"GREEK UPSILON WITH HOOK SYMBOL";
		break;
	case U'\u03D3':
		nm = U"GREEK UPSILON WITH ACUTE AND HOOK SYMBOL";
		break;
	case U'\u03D4':
		nm = U"GREEK UPSILON WITH DIAERESIS AND HOOK SYMBOL";
		break;
	case U'\u03D5':
		nm = U"GREEK PHI SYMBOL";
		break;
	case U'\u03D6':
		nm = U"GREEK PI SYMBOL";
		break;
	case U'\u03D7':
		nm = U"GREEK KAI SYMBOL";
		break;
	case U'\u03D8':
		nm = U"GREEK LETTER ARCHAIC KOPPA";
		break;
	case U'\u03D9':
		nm = U"GREEK SMALL LETTER ARCHAIC KOPPA";
		break;
	case U'\u03DA':
		nm = U"GREEK LETTER STIGMA";
		break;
	case U'\u03DB':
		nm = U"GREEK SMALL LETTER STIGMA";
		break;
	case U'\u03DC':
		nm = U"GREEK LETTER DIGAMMA";
		break;
	case U'\u03DD':
		nm = U"GREEK SMALL LETTER DIGAMMA";
		break;
	case U'\u03DE':
		nm = U"GREEK LETTER KOPPA";
		break;
	case U'\u03DF':
		nm = U"GREEK SMALL LETTER KOPPA";
		break;
	case U'\u03E0':
		nm = U"GREEK LETTER SAMPI";
		break;
	case U'\u03F0':
		nm = U"GREEK KAPPA SYMBOL";
		break;
	/* HEBREW: */
	case U'\u05D0':
		nm = U"HEBREW LETTER ALEF";
		break;
	case U'\u05D1':
		nm = U"HEBREW LETTER BET";
		break;
	case U'\u05D2':
		nm = U"HEBREW LETTER GIMEL";
		break;
	case U'\u05D3':
		nm = U"HEBREW LETTER DALET";
		break;
	case U'\u05D4':
		nm = U"HEBREW LETTER HE";
		break;
	case U'\u05D5':
		nm = U"HEBREW LETTER VAV";
		break;
	case U'\u05D6':
		nm = U"HEBREW LETTER ZAYIN";
		break;
	case U'\u05D7':
		nm = U"HEBREW LETTER HET";
		break;
	case U'\u05D8':
		nm = U"HEBREW LETTER TET";
		break;
	case U'\u05D9':
		nm = U"HEBREW LETTER YOD";
		break;
	case U'\u05DA':
		nm = U"HEBREW LETTER FINAL KAF";
		break;
	case U'\u05DB':
		nm = U"HEBREW LETTER KAF";
		break;
	case U'\u05DC':
		nm = U"HEBREW LETTER LAMED";
		break;
	case U'\u05DD':
		nm = U"HEBREW LETTER FINAL MEM";
		break;
	case U'\u05DE':
		nm = U"HEBREW LETTER MEM";
		break;
	case U'\u05DF':
		nm = U"HEBREW LETTER FINAL NUN";
		break;
	case U'\u05E0':
		nm = U"HEBREW LETTER NUN";
		break;
	case U'\u05E1':
		nm = U"HEBREW LETTER SAMEKH";
		break;
	case U'\u05E2':
		nm = U"HEBREW LETTER AYIN";
		break;
	case U'\u05E3':
		nm = U"HEBREW LETTER FINAL PE";
		break;
	case U'\u05E4':
		nm = U"HEBREW LETTER PE";
		break;
	case U'\u05E5':
		nm = U"HEBREW LETTER FINAL TSADI";
		break;
	case U'\u05E6':
		nm = U"HEBREW LETTER TSADI";
		break;
	case U'\u05E7':
		nm = U"HEBREW LETTER QOF";
		break;
	case U'\u05E8':
		nm = U"HEBREW LETTER RESH";
		break;
	case U'\u05E9':
		nm = U"HEBREW LETTER SHIN";
		break;
	case U'\u05EA':
		nm = U"HEBREW LETTER TAV";
		break;
	case U'\u05EF':
		nm = U"HEBREW YOD TRIANGLE";
		break;
	/* CYRILLIC: */
	case U'\u0400':
		nm = U"CYRILLIC CAPITAL LETTER LE WITH GRAVE";
		break;
	case U'\u0401':
		nm = U"CYRILLIC CAPITAL LETTER LO";
		break;
	case U'\u0402':
		nm = U"CYRILLIC CAPITAL LETTER DJE";
		break;
	case U'\u0403':
		nm = U"CYRILLIC CAPITAL LETTER GJE";
		break;
	case U'\u0404':
		nm = U"CYRILLIC CAPITAL LETTER UKRAINIAN LE";
		break;
	case U'\u0405':
		nm = U"CYRILLIC CAPITAL LETTER DZE";
		break;
	case U'\u0406':
		nm = U"CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I";
		break;
	case U'\u0407':
		nm = U"CYRILLIC CAPITAL LETTER YI";
		break;
	case U'\u0408':
		nm = U"CYRILLIC CAPITAL LETTER JE";
		break;
	case U'\u0409':
		nm = U"CYRILLIC CAPITAL LETTER LJE";
		break;
	case U'\u040A':
		nm = U"CYRILLIC CAPITAL LETTER NJE";
		break;
	case U'\u040B':
		nm = U"CYRILLIC CAPITAL LETTER TSHE";
		break;
	case U'\u040C':
		nm = U"CYRILLIC CAPITAL LETTER KJE";
		break;
	case U'\u040D':
		nm = U"CYRILLIC CAPITAL LETTER I WITH GRAVE";
		break;
	case U'\u040E':
		nm = U"CYRILLIC CAPITAL LETTER SHORT U";
		break;
	case U'\u040F':
		nm = U"CYRILLIC CAPITAL LETTER DZHE";
		break;
	case U'\u0410':
		nm = U"CYRILLIC CAPITAL LETTER A";
		break;
	case U'\u0420':
		nm = U"CYRILLIC CAPITAL LETTER ER";
		break;
	case U'\u0430':
		nm = U"CYRILLIC SMALL LETTER A";
		break;
	case U'\u0440':
		nm = U"CYRILLIC SMALL LETTER ER";
		break;
	case U'\u0450':
		nm = U"CYRILLIC SMALL LETTER LE WITH GRAVE";
		break;
	case U'\u0460':
		nm = U"CYRILLIC CAPITAL LETTER OMEGA";
		break;
	case U'\u0470':
		nm = U"CYRILLIC CAPITAL LETTER PSI";
		break;
	case U'\u0480':
		nm = U"CYRILLIC CAPITAL LETTER KOPPA";
		break;
	case U'\u0490':
		nm = U"CYRILLIC CAPITAL LETTER GHE WITH UPTURN";
		break;
	case U'\u04A0':
		nm = U"CYRILLIC CAPITAL LETTER BASHKIR KA";
		break;
	case U'\u04B0':
		nm = U"CYRILLIC CAPITAL LETTER STRAIGHT U WITH STROKE";
		break;
	case U'\u04C0':
		nm = U"CYRILLIC LETTER PALOCHKA";
		break;
	case U'\u04D0':
		nm = U"CYRILLIC CAPITAL LETTER A WITH BREVE";
		break;
	case U'\u04E0':
		nm = U"CYRILLIC CAPITAL LETTER ABKHASIAN DZE";
		break;
	case U'\u04F0':
		nm = U"CYRILLIC CAPITAL LETTER U WITH DIAERESIS";
		break;
	/* SYRIAC SUPPLEMENT: */
	case U'\u0860':
		nm = U"SYRIAC LETTER MALAYALAM NGA";
		break;
	case U'\u0861':
		nm = U"SYRIAC LETTER MALAYALAM JA";
		break;
	case U'\u0862':
		nm = U"SYRIAC LETTER MALAYALAM NYA";
		break;
	case U'\u0863':
		nm = U"SYRIAC LETTER MALAYALAM TTA";
		break;
	case U'\u0864':
		nm = U"SYRIAC LETTER MALAYALAM NNA";
		break;
	case U'\u0865':
		nm = U"SYRIAC LETTER MALAYALAM NNNA";
		break;
	case U'\u0866':
		nm = U"SYRIAC LETTER MALAYALAM BHA";
		break;
	case U'\u0867':
		nm = U"SYRIAC LETTER MALAYALAM RA";
		break;
	case U'\u0868':
		nm = U"SYRIAC LETTER MALAYALAM LLA";
		break;
	case U'\u0869':
		nm = U"SYRIAC LETTER MALAYALAM LLLA";
		break;
	case U'\u086A':
		nm = U"SYRIAC LETTER MALAYALAM SSA";
		break;
	/* RUNIC: */
	case U'\u16A0':
		nm = U"RUNIC LETTER FEHU FEOH FE F";
		break;
	case U'\u16A1':
		nm = U"RUNIC LETTER V";
		break;
	case U'\u16A2':
		nm = U"RUNIC LETTER URUZ UR U";
		break;
	case U'\u16A3':
		nm = U"RUNIC LETTER YR";
		break;
	case U'\u16A4':
		nm = U"RUNIC LETTER Y";
		break;
	case U'\u16A5':
		nm = U"RUNIC LETTER W";
		break;
	case U'\u16A6':
		nm = U"RUNIC LETTER THURISAZ THURS THORN";
		break;
	case U'\u16A7':
		nm = U"RUNIC LETTER ETH";
		break;
	case U'\u16A8':
		nm = U"RUNIC LETTER ANSUZ A";
		break;
	case U'\u16A9':
		nm = U"RUNIC LETTER OS O";
		break;
	case U'\u16AA':
		nm = U"RUNIC LETTER AC A";
		break;
	case U'\u16AB':
		nm = U"RUNIC LETTER AESC";
		break;
	case U'\u16AC':
		nm = U"RUNIC LETTER LONG-BRANCHED-OSS O";
		break;
	case U'\u16AD':
		nm = U"RUNIC LETTER SHORT-TWIG-OSS O";
		break;
	case U'\u16AE':
		nm = U"RUNIC LETTER O";
		break;
	case U'\u16AF':
		nm = U"RUNIC LETTER OE";
		break;
	case U'\u16B0':
		nm = U"RUNIC LETTER ON";
		break;
	case U'\u16C0':
		nm = U"RUNIC LETTER DOTTED-N";
		break;
	case U'\u16D0':
		nm = U"RUNIC LETTER SHORT-TWIG-TYR T";
		break;
	case U'\u16E0':
		nm = U"RUNIC LETTER EAR";
		break;
	case U'\u16F0':
		nm = U"RUNIC BELGTHOR SYMBOL";
		break;
	/* CYRILLIC EXTENDED C: */
	case U'\u1C80':
		nm = U"CYRILLIC SMALL LETTER ROUNDED VE";
		break;
	case U'\u1C81':
		nm = U"CYRILLIC SMALL LETTER LONG-LEGGED DE";
		break;
	case U'\u1C82':
		nm = U"CYRILLIC SMALL LETTER NARROW O";
		break;
	case U'\u1C83':
		nm = U"CYRILLIC SMALL LETTER WIDE ES";
		break;
	case U'\u1C84':
		nm = U"CYRILLIC SMALL LETTER TALL TE";
		break;
	case U'\u1C85':
		nm = U"CYRILLIC SMALL LETTER THREE-LEGGED TE";
		break;
	case U'\u1C86':
		nm = U"CYRILLIC SMALL LETTER TALL HARD SIGN";
		break;
	case U'\u1C87':
		nm = U"CYRILLIC SMALL LETTER TALL YAT";
		break;
	case U'\u1C88':
		nm = U"CYRILLIC SMALL LETTER UNBLENDED UK";
		break;
	/* GENERAL PUNCTUATION: */
	case U'\u2000':
		nm = U"EN QUAD";
		break;
	case U'\u2001':
		nm = U"EM QUAD";
		break;
	case U'\u2002':
		nm = U"EN SPACE";
		break;
	case U'\u2003':
		nm = U"EM SPACE";
		break;
	case U'\u2004':
		nm = U"THREE-PER-EM SPACE";
		break;
	case U'\u2005':
		nm = U"FOUR-PER-EM SPACE";
		break;
	case U'\u2006':
		nm = U"SIX-PER-EM SPACE";
		break;
	case U'\u2007':
		nm = U"FIGURE SPACE";
		break;
	case U'\u2008':
		nm = U"PUNCTUATION SPACE";
		break;
	case U'\u2009':
		nm = U"THIN SPACE";
		break;
	case U'\u200A':
		nm = U"HAIR SPACE";
		break;
	case U'\u203C':
		nm = U"DOUBLE EXCLAMATION MARK";
		break;
	case U'\u2047':
		nm = U"DOUBLE QUOTATION MARK";
		break;
	case U'\u2048':
		nm = U"QUESTION EXCLAMATION MARK";
		break;
	case U'\u2049':
		nm = U"EXCLAMATION QUESTION MARK";
		break;
	/* CURRENCY SYMBOLS: */
	case U'\u20A0':
		nm = U"EURO-CURRENCY SIGN";
		break;
	case U'\u20A1':
		nm = U"COLON SIGN";
		break;
	case U'\u20A2':
		nm = U"CRUZEIRO SIGN";
		break;
	case U'\u20A3':
		nm = U"FRENCH FRANC SIGN";
		break;
	case U'\u20A4':
		nm = U"LIRA SIGN";
		break;
	case U'\u20A5':
		nm = U"MILL SIGN";
		break;
	case U'\u20A6':
		nm = U"NAIRA SIGN";
		break;
	case U'\u20A7':
		nm = U"PESETA SIGN";
		break;
	case U'\u20A8':
		nm = U"RUPEE SIGN";
		break;
	case U'\u20A9':
		nm = U"WON SIGN";
		break;
	case U'\u20AA':
		nm = U"NEW SHEQEL SIGN";
		break;
	case U'\u20AB':
		nm = U"DONG SIGN";
		break;
	case U'\u20AC':
		nm = U"EURO SIGN";
		break;
	case U'\u20AD':
		nm = U"KIP SIGN";
		break;
	case U'\u20AE':
		nm = U"TUGRIK SIGN";
		break;
	case U'\u20AF':
		nm = U"DRACHMA SIGN";
		break;
	case U'\u20B0':
		nm = U"GERMAN PENNY SIGN";
		break;
	case U'\u20B1':
		nm = U"PESO SIGN";
		break;
	case U'\u20B2':
		nm = U"GUARANI SIGN";
		break;
	case U'\u20B3':
		nm = U"AUSTRAL SIGN";
		break;
	case U'\u20B4':
		nm = U"HRYVNIA SIGN";
		break;
	case U'\u20B5':
		nm = U"CEDI SIGN";
		break;
	case U'\u20B6':
		nm = U"LIVRE TOURNOIS SIGN";
		break;
	case U'\u20B7':
		nm = U"SPESMILO SIGN";
		break;
	case U'\u20B8':
		nm = U"TENGE SIGN";
		break;
	case U'\u20BA':
		nm = U"TURKISH LIRA SIGN";
		break;
	case U'\u20BB':
		nm = U"NORDIC MARK SIGN";
		break;
	case U'\u20BC':
		nm = U"MANAT SIGN";
		break;
	case U'\u20BD':
		nm = U"RUBLE SYMBOL";
		break;
	case U'\u20BE':
		nm = U"LARI SIGN";
		break;
	case U'\u20BF':
		nm = U"BITCOIN SIGN";
		break;
	/* LETTERLIKE SYMBOLS: */
	case U'\u2100':
		nm = U"ACCOUNT OF";
		break;
	case U'\u2101':
		nm = U"ADRESSED TO THE SUBJECT";
		break;
	case U'\u2102':
		nm = U"DOUBLE-STRUCK CAPITAL C";
		break;
	case U'\u2103':
		nm = U"DEGREE CELSIUS";
		break;
	case U'\u2104':
		nm = U"CENTRE LINE SYMBOL";
		break;
	case U'\u2105':
		nm = U"CARE OF";
		break;
	case U'\u2106':
		nm = U"CADA UNA";
		break;
	case U'\u2107':
		nm = U"EULER CONSTANT";
		break;
	case U'\u2108':
		nm = U"SCRUPLE";
		break;
	case U'\u2109':
		nm = U"DEGREE FAHRENHEIT";
		break;
	case U'\u210A':
		nm = U"SCRIPT SMALL G";
		break;
	case U'\u210B':
		nm = U"SCRIPT CAPITAL H";
		break;
	case U'\u210C':
		nm = U"BLACK-LETTER CAPITAL H";
		break;
	case U'\u210D':
		nm = U"DOUBLE-STRUCK CAPITAL H";
		break;
	case U'\u210E':
		nm = U"PLANCK CONSTANT";
		break;
	case U'\u210F':
		nm = U"PLANCK CONSTANT OVER TWO PI";
		break;
	case U'\u2110':
		nm = U"SCRIPT CAPITAL I";
		break;
	case U'\u2111':
		nm = U"BLACK-LETTER CAPITAL I";
		break;
	case U'\u2112':
		nm = U"SCRIPT CAPITAL L";
		break;
	case U'\u2113':
		nm = U"SCRIPT SMALL L";
		break;
	case U'\u2114':
		nm = U"L B BAR SYMBOL";
		break;
	case U'\u2115':
		nm = U"DOUBLE-STRUCK CAPITAL N";
		break;
	case U'\u2116':
		nm = U"NUMERO SIGN";
		break;
	case U'\u2117':
		nm = U"SOUND RECORDING COPYRIGHT";
		break;
	case U'\u2118':
		nm = U"SCRIPT CAPITAL P";
		break;
	case U'\u2119':
		nm = U"DOUBLE-STRUCK CAPITAL P";
		break;
	case U'\u211A':
		nm = U"DOUBLE-STRUCK CAPITAL Q";
		break;
	case U'\u211B':
		nm = U"SCRIPT CAPITAL R";
		break;
	case U'\u211C':
		nm = U"BLACK-LETTER CAPITAL R";
		break;
	case U'\u211D':
		nm = U"DOUBLE-STRUCK CAPITAL R";
		break;
	case U'\u211E':
		nm = U"PRESCRIPTION TAKE";
		break;
	case U'\u211F':
		nm = U"RESPONSE";
		break;
	case U'\u2120':
		nm = U"SERVICE MARK";
		break;
	case U'\u2121':
		nm = U"TELEPHONE SIGN";
		break;
	case U'\u2122':
		nm = U"TRADE MARK SIGN";
		break;
	case U'\u2123':
		nm = U"VERSICLE";
		break;
	case U'\u2124':
		nm = U"DOUBLE-STRUCK CAPITAL Z";
		break;
	case U'\u2125':
		nm = U"OUNCE SIGN";
		break;
	case U'\u2126':
		nm = U"OHM SIGN";
		break;
	case U'\u2127':
		nm = U"INVERTED OHM SIGN";
		break;
	case U'\u2128':
		nm = U"BLACK-LETTER CAPITAL Z";
		break;
	case U'\u2129':
		nm = U"TURNED GREEK SMALL LETTER IOTA";
		break;
	case U'\u212A':
		nm = U"KELVIN SIGN";
		break;
	case U'\u212B':
		nm = U"ANGSTROM SIGN";
		break;
	case U'\u212C':
		nm = U"SCRIPT CAPITAL B";
		break;
	case U'\u212D':
		nm = U"BLACK-LETTER CAPITAL C";
		break;
	case U'\u212E':
		nm = U"ESTIMATED SYMBOL";
		break;
	case U'\u212F':
		nm = U"SCRIPT SMALL E";
		break;
	case U'\u2130':
		nm = U"SCRIPT CAPITAL E";
		break;
	case U'\u2131':
		nm = U"SCRIPT CAPITAL F";
		break;
	case U'\u2132':
		nm = U"TURNED CAPITAL F";
		break;
	case U'\u2133':
		nm = U"SCRIPT CAPITAL M";
		break;
	case U'\u2134':
		nm = U"SCRIPT SMALL O";
		break;
	case U'\u2135':
		nm = U"ALEF SYMBOL";
		break;
	case U'\u2136':
		nm = U"BET SYMBOL";
		break;
	case U'\u2137':
		nm = U"GIMEL SYMBOL";
		break;
	case U'\u2138':
		nm = U"DALET SYMBOL";
		break;
	case U'\u2139':
		nm = U"INFORMATION SOURCE";
		break;
	case U'\u213A':
		nm = U"ROTATED CAPITAL Q";
		break;
	case U'\u213B':
		nm = U"FACSIMILE SIGN";
		break;
	case U'\u213C':
		nm = U"DOUBLE-STRUCK SMALL PI";
		break;
	case U'\u213D':
		nm = U"DOUBLE-STRUCK SMALL GAMMA";
		break;
	case U'\u213E':
		nm = U"DOUBLE-STRUCK CAPITAL GAMMA";
		break;
	case U'\u213F':
		nm = U"DOUBLE-STRUCK CAPITAL PI";
		break;
	case U'\u2140':
		nm = U"DOUBLE-STRUCK N-ARY SUMMATION";
		break;
	case U'\u2141':
		nm = U"TURNED SANS-SERIF CAPITAL G";
		break;
	case U'\u2142':
		nm = U"TURNED SANS-SERIF CAPITAL L";
		break;
	case U'\u2143':
		nm = U"REVERSED SANS-SERIF CAPITAL L";
		break;
	case U'\u2144':
		nm = U"TURNED SANS-SERIF CAPITAL Y";
		break;
	case U'\u2145':
		nm = U"DOUBLE-STRUCK ITALIC CAPITAL D";
		break;
	case U'\u2146':
		nm = U"DOUBLE-STRUCK ITALIC SMALL D";
		break;
	case U'\u2147':
		nm = U"DOUBLE-STRUCK ITALIC SMALL E";
		break;
	case U'\u2148':
		nm = U"DOUBLE-STRUCK ITALIC SMALL I";
		break;
	case U'\u2149':
		nm = U"DOUBLE-STRUCK ITALIC SMALL J";
		break;
	case U'\u214A':
		nm = U"PROPERTY LINE";
		break;
	case U'\u214B':
		nm = U"TURNED AMPERSAND";
		break;
	case U'\u214C':
		nm = U"PER SIGN";
		break;
	case U'\u214D':
		nm = U"AKTIESELSKAB";
		break;
	case U'\u214E':
		nm = U"TURNED SMALL F";
		break;
	case U'\u214F':
		nm = U"SYMBOL FOR SAMARITAN SOURCE";
		break;
	/* NUMBER FORMS: */
	case U'\u2150':
		nm = U"VULGAR FRACTION ONE SEVENTH";
		break;
	case U'\u2151':
		nm = U"VULGAR FRACTION ONE NINTH";
		break;
	case U'\u2152':
		nm = U"VULGAR FRACTION ONE TENTH";
		break;
	case U'\u2153':
		nm = U"VULGAR FRACTION ONE THIRD";
		break;
	case U'\u2154':
		nm = U"VULGAR FRACTION TWO THIRDS";
		break;
	case U'\u2155':
		nm = U"VULGAR FRACTION ONE FIFTH";
		break;
	case U'\u2156':
		nm = U"VULGAR FRACTION TWO FIFTHS";
		break;
	case U'\u2157':
		nm = U"VULGAR FRACTION THREE FIFTHS";
		break;
	case U'\u2158':
		nm = U"VULGAR FRACTION FOUR FIFTHS";
		break;
	case U'\u2159':
		nm = U"VULGAR FRACTION ONE SIXTH";
		break;
	case U'\u215A':
		nm = U"VULGAR FRACTION FIVE SIXTHS";
		break;
	case U'\u215B':
		nm = U"VULGAR FRACTION ONE EIGTH";
		break;
	case U'\u215C':
		nm = U"VULGAR FRACTION THREE EIGTHS";
		break;
	case U'\u215D':
		nm = U"VULGAR FRACTION FIVE EIGHTS";
		break;
	case U'\u215E':
		nm = U"VULGAR FRACTION SEVEN EIGTHS";
		break;
	case U'\u215F':
		nm = U"FRACTION NUMERATOR ONE";
		break;
	case U'\u2160':
		nm = U"ROMAN NUMERAL ONE";
		break;
	case U'\u2161':
		nm = U"ROMAN NUMERAL TWO";
		break;
	case U'\u2162':
		nm = U"ROMAN NUMERAL THREE";
		break;
	case U'\u2163':
		nm = U"ROMAN NUMERAL FOUR";
		break;
	case U'\u2164':
		nm = U"ROMAN NUMERAL FIVE";
		break;
	case U'\u2165':
		nm = U"ROMAN NUMERAL SIX";
		break;
	case U'\u2166':
		nm = U"ROMAN NUMERAL SEVEN";
		break;
	case U'\u2167':
		nm = U"ROMAN NUMERAL EIGHT";
		break;
	case U'\u2168':
		nm = U"ROMAN NUMERAL NINE";
		break;
	case U'\u2169':
		nm = U"ROMAN NUMERAL TEN";
		break;
	case U'\u216A':
		nm = U"ROMAN NUMERAL ELEVEN";
		break;
	case U'\u216B':
		nm = U"ROMAN NUMERAL TWELVE";
		break;
	case U'\u216C':
		nm = U"ROMAN NUMERAL FIFTY";
		break;
	case U'\u216D':
		nm = U"ROMAN NUMERAL ONE HUNDRED";
		break;
	case U'\u216E':
		nm = U"ROMAN NUMERAL FIVE HUNDRED";
		break;
	case U'\u216F':
		nm = U"ROMAN NUMERAL ONE THOUSAND";
		break;
	case U'\u2170':
		nm = U"SMALL ROMAN NUMERAL ONE";
		break;
	case U'\u2171':
		nm = U"SMALL ROMAN NUMERAL TWO";
		break;
	case U'\u2172':
		nm = U"SMALL ROMAN NUMERAL THREE";
		break;
	case U'\u2173':
		nm = U"SMALL ROMAN NUMERAL FOUR";
		break;
	case U'\u2174':
		nm = U"SMALL ROMAN NUMERAL FIVE";
		break;
	case U'\u2175':
		nm = U"SMALL ROMAN NUMERAL SIX";
		break;
	case U'\u2176':
		nm = U"SMALL ROMAN NUMERAL SEVEN";
		break;
	case U'\u2177':
		nm = U"SMALL ROMAN NUMERAL EIGHT";
		break;
	case U'\u2178':
		nm = U"SMALL ROMAN NUMERAL NINE";
		break;
	case U'\u2179':
		nm = U"SMALL ROMAN NUMERAL TEN";
		break;
	case U'\u217A':
		nm = U"SMALL ROMAN NUMERAL ELEVEN";
		break;
	case U'\u217B':
		nm = U"SMALL ROMAN NUMERAL TWELVE";
		break;
	case U'\u217C':
		nm = U"SMALL ROMAN NUMERAL FIFTY";
		break;
	case U'\u217D':
		nm = U"SMALL ROMAN NUMERAL ONE HUNDRED";
		break;
	case U'\u217E':
		nm = U"SMALL ROMAN NUMERAL FIVE HUNDRED";
		break;
	case U'\u217F':
		nm = U"SMALL ROMAN NUMERAL ONE THOUSAND";
		break;
	case U'\u2180':
		nm = U"ROMAN NUMERAL ONE THOUSAND C D";
		break;
	case U'\u2181':
		nm = U"ROMAN NUMERAL FIVE THOUSAND";
		break;
	case U'\u2182':
		nm = U"ROMAN NUMERAL TEN THOUSAND";
		break;
	case U'\u2183':
		nm = U"ROMAN NUMERAL REVERSED ONE HUNDRED";
		break;
	case U'\u2184':
		nm = U"LATIN SMALL LETTER REVERSED C";
		break;
	case U'\u2185':
		nm = U"ROMAN NUMERAL SIX LATE FORM";
		break;
	case U'\u2186':
		nm = U"ROMAN NUMERAL FIFTY EARLY FORM";
		break;
	case U'\u2187':
		nm = U"ROMAN NUMERAL FIFTY THOUSAND";
		break;
	case U'\u2188':
		nm = U"ROMAN NUMERAL ONE HUNDRED THOUSAND";
		break;
	case U'\u2189':
		nm = U"VULGAR FRACTION ZERO THIRDS";
		break;
	case U'\u218A':
		nm = U"TURNED DIGIT TWO";
		break;
	case U'\u218B':
		nm = U"TURNED DIGIT THREE";
		break;
	/* MISCELLANEOUS SYMBOLS: */
	case U'\u26B9':
		nm = U"SEXTILE";
		break;
	/* DINGBATS: */
	case U'\u271D':
		nm = U"LATIN CROSS";
		break;
	case U'\u2721':
		nm = U"STAR OF DAVID";
		break;
	/* SUPPLEMENTAL PUNCTUATION: */
	case U'\u2E3B':
		nm = U"THREE-EM DASH";
		break;
	/* ARABIC PRESENTATION FORMS-A: */
	case U'\uFDFD':
		nm = U"ARABIC LIGATURE BISMILLAH AL-RAHMAN AR-RAHEEM";
		break;
	/* ANCIENT SYMBOLS: */
	case U'\U00010190':
		nm = U"ROMAN SEXTANS SIGN";
		break;
	case U'\U00010191':
		nm = U"ROMAN UNCIA SIGN";
		break;
	case U'\U00010192':
		nm = U"ROMAN SEMUNCIA SIGN";
		break;
	case U'\U00010193':
		nm = U"ROMAN SEXTULA SIGN";
		break;
	case U'\U00010194':
		nm = U"ROMAN DIMIDIA SEXTULA SIGN";
		break;
	case U'\U00010195':
		nm = U"ROMAN SILIQUA SIGN";
		break;
	case U'\U00010196':
		nm = U"ROMAN DENARIUS SIGN";
		break;
	case U'\U00010197':
		nm = U"ROMAN QUINARIUS SIGN";
		break;
	case U'\U00010198':
		nm = U"ROMAN SESTERTIUS SIGN";
		break;
	case U'\U00010199':
		nm = U"ROMAN DUPONDIUS SIGN";
		break;
	case U'\U0001019A':
		nm = U"ROMAN AS SIGN";
		break;
	case U'\U0001019B':
		nm = U"ROMAN CENTURIAL SIGN";
		break;
	case U'\U0001019C':
		nm = U"ASCIA SIGN";
		break;
	/* BRAHMI: */
	case U'\U00011066':
		nm = U"BRAHMI DIGIT ZERO";
		break;
	case U'\U00011067':
		nm = U"BRAHMI DIGIT ONE";
		break;
	case U'\U00011068':
		nm = U"BRAHMI DIGIT TWO";
		break;
	case U'\U00011069':
		nm = U"BRAHMI DIGIT THREE";
		break;
	case U'\U0001106A':
		nm = U"BRAHMI DIGIT FOUR";
		break;
	case U'\U0001106B':
		nm = U"BRAHMI DIGIT FIVE";
		break;
	case U'\U0001106C':
		nm = U"BRAHMI DIGIT SIX";
		break;
	case U'\U0001106D':
		nm = U"BRAHMI DIGIT SEVEN";
		break;
	case U'\U0001106E':
		nm = U"BRAHMI DIGIT EIGHT";
		break;
	case U'\U0001106F':
		nm = U"BRAHMI DIGIT NINE";
		break;
	/* CUNEIFORM: */
	case U'\U00012031':
		nm = U"CUNEIFORM SIGN AN PLUS NAGA SQUARED";
		break;
	/* CUNEIFORM NUMBERS AND PUNCTUATION: */
	case U'\U0001242B':
		nm = U"CUNEIFORM NUMERIC SIGN NINE SHAR2";
		break;
	/* EGYPTIAN HIEROGLYPHS: */
	case U'\U000130B8':
		nm = U"EGYPTIAN HIEROGLYPH D052";
		break;
	/* COUNTING ROD NUMERALS: */
	case U'\U0001D372':
		nm = U"IDEOGRAPHIC TALLY MARK ONE";
		break;
	case U'\U0001D373':
		nm = U"IDEOGRAPHIC TALLY MARK TWO";
		break;
	case U'\U0001D374':
		nm = U"IDEOGRAPHIC TALLY MARK THREE";
		break;
	case U'\U0001D375':
		nm = U"IDEOGRAPHIC TALLY MARK FOUR";
		break;
	case U'\U0001D376':
		nm = U"IDEOGRAPHIC TALLY MARK FIVE";
		break;
	case U'\U0001D377':
		nm = U"TALLY MARK ONE";
		break;
	case U'\U0001D378':
		nm = U"TALLY MARK FIVE";
		break;
	/* ENCLOSED ALPHANUMERIC SUPPLEMENT: */
	case U'\U0001F10D':
		nm = U"CIRCLED ZERO WITH SLASH";
		break;
	case U'\U0001F10E':
		nm = U"CIRCLED ANTICKLOCKWISE ARROW";
		break;
	case U'\U0001F10F':
		nm = U"CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH";
		break;
	case U'\U0001F12F':
		nm = U"COPYLEFT SYMBOL";
		break;
	case U'\U0001F16D':
		nm = U"CIRCLED CC";
		break;
	case U'\U0001F16E':
		nm = U"CIRCLED C WITH OVERLAID BACKSLASH";
		break;
	case U'\U0001F16F':
		nm = U"CIRCLED HUMAN FIGURE";
		break;
	/* EMOTICONS: */
	case U'\U0001F600':
		nm = U"GRINNING FACE";
		break;
	case U'\U0001F601':
		nm = U"GRINNING FACE WITH SMIRKING EYES";
		break;
	case U'\U0001F602':
		nm = U"FACE WITH TEARS OF JOY";
		break;
	case U'\U0001F603':
		nm = U"SMILING FACE WITH OPEN MOUTH";
		break;
	case U'\U0001F604':
		nm = U"SMILING FACE WITH OPEN MOUTH AND SMILING EYES";
		break;
	case U'\U0001F605':
		nm = U"SMILING FACE WITH OPEN MOUTH AND COULD SWEAT";
		break;
	case U'\U0001F606':
		nm = U"SMILING FACE WITH OPEN MOUTH AND TIGHTLY-CLOSED EYES";
		break;
	case U'\U0001F607':
		nm = U"SMILING FACE WITH HALO";
		break;
	case U'\U0001F608':
		nm = U"SMILING FACE WITH HORNS";
		break;
	case U'\U0001F609':
		nm = U"WINKING FACE";
		break;
	case U'\U0001F60A':
		nm = U"SMILING FACE WITH SMILING EYES";
		break;
	case U'\U0001F60B':
		nm = U"FACE SAVOURING DELICIOUS FOOD";
		break;
	case U'\U0001F60C':
		nm = U"RELIEVED FACE";
		break;
	case U'\U0001F60D':
		nm = U"SMILLING FACE HEART-SHAPED EYES";
		break;
	case U'\U0001F60E':
		nm = U"SMILLING FACE WITH SUNGLASSES";
		break;
	case U'\U0001F60F':
		nm = U"SMIRKING FACE";
		break;
	case U'\U0001F610':
		nm = U"NEUTRAL FACE";
		break;
	case U'\U0001F611':
		nm = U"EXPRESSIONLESS FACE";
		break;
	case U'\U0001F612':
		nm = U"UNAMUSED FACE";
		break;
	case U'\U0001F613':
		nm = U"FACE WITH COLD SWEAT";
		break;
	case U'\U0001F614':
		nm = U"PENSIVE FACE";
		break;
	case U'\U0001F615':
		nm = U"CONFUSED FACE";
		break;
	case U'\U0001F616':
		nm = U"CONFOUNDED FACE";
		break;
	case U'\U0001F617':
		nm = U"KISSING FACE";
		break;
	case U'\U0001F618':
		nm = U"FACE THROWING A KISS";
		break;
	case U'\U0001F619':
		nm = U"KISSING FACE WITH SMILLING EYES";
		break;
	case U'\U0001F61A':
		nm = U"KISSING FACE WITH CLOSED EYES";
		break;
	case U'\U0001F61B':
		nm = U"FACE WITH STUCK-OUT TONGUE";
		break;
	case U'\U0001F61C':
		nm = U"FACE WITH STUCK-OUT TONGUE AND WINKING EYE";
		break;
	case U'\U0001F61D':
		nm = U"FACE WITH STUCK-OUT TONGUE AND TIGHTLY-CLOSED EYES";
		break;
	case U'\U0001F61E':
		nm = U"DISSAPOINTED FACE";
		break;
	case U'\U0001F61F':
		nm = U"WORRIED FACE";
		break;
	case U'\U0001F620':
		nm = U"ANGRY FACE";
		break;
	case U'\U0001F621':
		nm = U"POUTING FACE";
		break;
	case U'\U0001F622':
		nm = U"CRYING FACE";
		break;
	case U'\U0001F623':
		nm = U"PERSEVERING FACE";
		break;
	case U'\U0001F624':
		nm = U"FACE WITH LOOK OF TRIUMPH";
		break;
	case U'\U0001F625':
		nm = U"DISSAPOINTED BUT RELIEVED FACE";
		break;
	case U'\U0001F626':
		nm = U"FROWNING FACE WITH OPEN MOUTH";
		break;
	case U'\U0001F627':
		nm = U"ANGUISHED FACE";
		break;
	case U'\U0001F628':
		nm = U"FEARFUL FACE";
		break;
	case U'\U0001F629':
		nm = U"WEARY FACE";
		break;
	case U'\U0001F62A':
		nm = U"SLEEPY FACE";
		break;
	case U'\U0001F62B':
		nm = U"TIRED FACE";
		break;
	case U'\U0001F62C':
		nm = U"GRIMACING FACE";
		break;
	case U'\U0001F62D':
		nm = U"LOUDLY CRYING FACE";
		break;
	case U'\U0001F62E':
		nm = U"FACE WITH OPEN MOUTH";
		break;
	case U'\U0001F62F':
		nm = U"HUSHED FACE";
		break;
	case U'\U0001F630':
		nm = U"FACE WITH OPEN MOUTH AND COLD SWEAT";
		break;
	case U'\U0001F631':
		nm = U"FACE SCREAMING IN FEAR";
		break;
	case U'\U0001F632':
		nm = U"ASTONISHED FACE";
		break;
	case U'\U0001F633':
		nm = U"FLUSHED FACE";
		break;
	case U'\U0001F634':
		nm = U"SLEEPING FACE";
		break;
	case U'\U0001F635':
		nm = U"DIZZY FACE";
		break;
	case U'\U0001F636':
		nm = U"FACE WITHOUT MOUTH";
		break;
	case U'\U0001F637':
		nm = U"FACE WITH MEDICAL MASK";
		break;
	case U'\U0001F641':
		nm = U"SLIGHTLY FROWNING FACE";
		break;
	case U'\U0001F642':
		nm = U"SLIGHTLY SMILING FACE";
		break;
	case U'\U0001F643':
		nm = U"UPSIDE-DOWN FACE";
		break;
	case U'\U0001F644':
		nm = U"FACE WITH ROLLING EYES";
		break;
	/* CJK UNIFIED IDEOGRAPHS EXTENSION G: */
	case U'\U0003106C':
		nm = U"CJK UNIFIED IDEOGRAPH-3106C";
		break;
	}
	{
		struct u8c_strcp_tuple const tuple    = u8c_strcp(nm);
		                             ret.nm   = tuple.str;
	   	                             ret.nmsz = tuple.strsz;
	}
	return ret;
}
