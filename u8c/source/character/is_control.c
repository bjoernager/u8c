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

bool u8c_is_control(uint_least32_t const code_point) {
	switch(code_point) {
	default:
		return false;

	case UINT32_C(0x0000): // NULL
	case UINT32_C(0x0001): // START OF HEADING
	case UINT32_C(0x0002): // START OF TEXT
	case UINT32_C(0x0003): // END OF TEXT
	case UINT32_C(0x0004): // END OF TRANSMISSION
	case UINT32_C(0x0005): // ENQUIRY
	case UINT32_C(0x0006): // ACKNOWLEDGE
	case UINT32_C(0x0007): // BELL
	case UINT32_C(0x0008): // BACKSPACE
	case UINT32_C(0x0009): // HORIZONTAL TABULATION
	case UINT32_C(0x000A): // NEW LINE
	case UINT32_C(0x000B): // VERTICAL TABULATION
	case UINT32_C(0x000C): // FORM FEED
	case UINT32_C(0x000D): // CARRIAGE RETURN
	case UINT32_C(0x000E): // SHIFT OUT
	case UINT32_C(0x000F): // SHIFT IN
	case UINT32_C(0x0010): // DATA LINK ESCAPE
	case UINT32_C(0x0011): // DEVICE CONTROL ONE
	case UINT32_C(0x0012): // DEVICE CONTROL TWO
	case UINT32_C(0x0013): // DEVICE CONTROL THREE
	case UINT32_C(0x0014): // DEVICE CONTROL FOUR
	case UINT32_C(0x0015): // NEGATIVE ACKNOWLEDGE
	case UINT32_C(0x0016): // SYNCHRONOUS IDLE
	case UINT32_C(0x0017): // END OF TRANSMISSION BLOCK
	case UINT32_C(0x0018): // CANCEL
	case UINT32_C(0x0019): // END OF MEDIUM
	case UINT32_C(0x001A): // SUBSTITUTE
	case UINT32_C(0x001B): // ESCAPE
	case UINT32_C(0x001C): // FILE SEPERATOR
	case UINT32_C(0x001D): // GROUP SEPERATOR
	case UINT32_C(0x001E): // RECORD SEPERATOR
	case UINT32_C(0x001F): // UNIT SEPERATOR
	case UINT32_C(0x007F): // DELETE
	case UINT32_C(0x0080): // PADDING CHARACTER
	case UINT32_C(0x0081): // HIGH OCTET PRESET
	case UINT32_C(0x0082): // BREAK PERMITTED HERE
	case UINT32_C(0x0083): // NO BREAK HERE
	case UINT32_C(0x0084): // INDEX
	case UINT32_C(0x0085): // NEXT LINE
	case UINT32_C(0x0086): // START OF SELECTED AREA
	case UINT32_C(0x0087): // END OF SELECTED AREA
	case UINT32_C(0x0088): // CHARACTER TABULATION SET
	case UINT32_C(0x0089): // CHARACTER TABULATION SET WITH JUSTIFICATION
	case UINT32_C(0x008A): // LINE TABULATION SET
	case UINT32_C(0x008B): // PARTIAL LINE FORWARD
	case UINT32_C(0x008C): // PARTIAL LINE BACKWARD
	case UINT32_C(0x008D): // REVERSE LINE FEED
	case UINT32_C(0x008E): // SINGLE SHIFT TWO
	case UINT32_C(0x008F): // SINGLE SHIFT THREE
	case UINT32_C(0x0090): // DEVICE CONTROL STRING
	case UINT32_C(0x0091): // PRIVATE USE ONE
	case UINT32_C(0x0092): // PRIVATE USE TWO
	case UINT32_C(0x0093): // SET TRANSMIT STATE
	case UINT32_C(0x0094): // CANCEL CHARACTER
	case UINT32_C(0x0095): // MESSAGE WAITING
	case UINT32_C(0x0096): // START OF GUARDED AREA
	case UINT32_C(0x0097): // END OF GUARDED AREA
	case UINT32_C(0x0098): // START OF STRING
	case UINT32_C(0x0099): // SINGLE GRAPHIC CHARACTER INTRODUCER
	case UINT32_C(0x009A): // SINGLE CHARACTER INTRODUCER
	case UINT32_C(0x009B): // CONTROL SEQUENCE INTRODUCER
	case UINT32_C(0x009C): // STRING TERMINATOR
	case UINT32_C(0x009D): // OPERATING SYSTEM COMMAND
	case UINT32_C(0x009E): // PRIVACY MESSAGE
	case UINT32_C(0x009F): // APPLICATION PROGRAM COMMAND
	case UINT32_C(0x00A0): // NO-BREAK SPACE
	case UINT32_C(0x2028): // LINE SEPERATOR
	case UINT32_C(0x2029): // PARAGRAPH SEPERATOR
	case UINT32_C(0x202D): // LEFT-TO-RIGHT OVERRIDE
	case UINT32_C(0x202E): // RIGHT-TO-LEFT OVERRIDE
	case UINT32_C(0x2068): // FIRST STRONG ISOLATE
	case UINT32_C(0x2069): // POP DIRECTIONAL ISOLATE
		return true;
	}
}
