/*
	Copyright 2021 Gabriel Jensen

	This file is part of u8c.

	u8c is free software:   you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	u8c is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

	See the	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with u8c.

	If not, see <https://www.gnu.org/licenses/>.
*/
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <u8c/chk.h>
struct u8c_iscntrl_tuple u8c_iscntrl(char32_t const _chr) {
	struct u8c_iscntrl_tuple ret = {
		.stat = false,
	};
	switch(_chr) {
	default:
		ret.res = false;
		break;
	case U'\x0':    /* NULL */
	case U'\x1':    /* START OF HEADING */
	case U'\x2':    /* START OF TEXT */
	case U'\x3':    /* END OF TEXT */
	case U'\x4':    /* END OF TRANSMISSION */
	case U'\x5':    /* ENQUIRY */
	case U'\x6':    /* ACKNOWLEDGE */
	case U'\a':     /* BELL */
	case U'\b':     /* BACKSPACE */
	case U'\t':     /* HORIZONTAL TABULATION */
	case U'\n':     /* NEW LINE */
	case U'\v':     /* VERTICAL TABULATION */
	case U'\f':     /* FORM FEED */
	case U'\r':     /* CARRIAGE RETURN */
	case U'\xE':    /* SHIFT OUT */
	case U'\xF':    /* SHIFT IN */
	case U'\x10':   /* DATA LINK ESCAPE */
	case U'\x11':   /* DEVICE CONTROL ONE */
	case U'\x12':   /* DEVICE CONTROL TWO */
	case U'\x13':   /* DEVICE CONTROL THREE */
	case U'\x14':   /* DEVICE CONTROL FOUR */
	case U'\x15':   /* NEGATIVE ACKNOWLEDGE */
	case U'\x16':   /* SYNCHRONOUS IDLE */
	case U'\x17':   /* END OF TRANSMISSION BLOCK */
	case U'\x18':   /* CANCEL */
	case U'\x19':   /* END OF MEDIUM */
	case U'\x1A':   /* SUBSTITUTE */
	case U'\x1B':   /* ESCAPE */
	case U'\x1C':   /* FILE SEPERATOR */
	case U'\x1D':   /* GROUP SEPERATOR */
	case U'\x1E':   /* RECORD SEPERATOR */
	case U'\x1F':   /* UNIT SEPERATOR */
	case U'\x7F':   /* DELETE */
	case U'\x80':   /* <CONTROL> */
	case U'\x81':   /* <CONTROL */
	case U'\x82':   /* BREAK PERMITTED HERE */
	case U'\x83':   /* NO BREAK HERE */
	case U'\x84':   /* <CONTROL> */
	case U'\x85':   /* NEXT LINE */
	case U'\x86':   /* START OF SELECTED AREA */
	case U'\x87':   /* END OF SELECTED AREA */
	case U'\x88':   /* CHARACTER TABULATION SET */
	case U'\x89':   /* CHARACTER TABULATION SET WITH JUSTIFICATION */
	case U'\x8A':   /* LINE TABULATION SET */
	case U'\x8B':   /* PARTIAL LINE FORWARD */
	case U'\x8C':   /* PARTIAL LINE BACKWARD */
	case U'\x8D':   /* REVERSE LINE FEED */
	case U'\x8E':   /* SINGLE SHIFT TWO */
	case U'\x8F':   /* SINGLE SHIFT THREE */
	case U'\x90':   /* DEVICE CONTROL STRING */
	case U'\x91':   /* PRIVATE USE ONE */
	case U'\x92':   /* PRIVATE USE TWO */
	case U'\x93':   /* SET TRANSMIT STATE */
	case U'\x94':   /* CANCEL CHARACTER */
	case U'\x95':   /* MESSAGE WAITING */
	case U'\x96':   /* START OF GUARDED AREA */
	case U'\x97':   /* END OF GUARDED AREA */
	case U'\x98':   /* START OF STRING */
	case U'\x99':   /* <CONTROL> */
	case U'\x9A':   /* SINGLE CHARACTER INTRODUCER */
	case U'\x9B':   /* CONTROL SEQUENCE INTRODUCER */
	case U'\x9C':   /* STRING TERMINATOR */
	case U'\x9D':   /* OPERATING SYSTEM COMMAND */
	case U'\x9E':   /* PRIVACY MESSAGE */
	case U'\x9F':   /* APPLICATION PROGRAM COMMAND */
	case U'\xA0':   /* NO-BREAK SPACE */
	case U'\u2028': /* LINE SEPERATOR */
	case U'\u2029': /* PARAGRAPH SEPERATOR */
	case U'\u202D': /* LEFT-TO-RIGHT OVERRIDE */
	case U'\u202E': /* RIGHT-TO-LEFT OVERRIDE */
	case U'\u2068': /* FIRST STRONG ISOLATE */
	case U'\u2069': /* POP DIRECTIONAL ISOLATE */
		ret.res = true;
		break;
	}
	return ret;
}
