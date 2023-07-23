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

u8c_NO_DISCARD u8c_NO_THROW u8c_UNSEQUENCED static bool u8c_is_alphabetic_internal(uint_least32_t code_point);

bool u8c_is_alphabetic(uint_least32_t const code_point) {
	return u8c_is_minuscule(code_point) || u8c_is_majuscule(code_point) || u8c_is_alphabetic_internal(code_point);
}

static bool u8c_is_alphabetic_internal(uint_least32_t const code_point) {
	switch(code_point) {
	default:
		return false;

	case UINT32_C(0x16A0): // RUNIC LETTER FEHU FEOH FE F
	case UINT32_C(0x16A1): // RUNIC LETTER V
	case UINT32_C(0x16A2): // RUNIC LETTER URUZ UR U
	case UINT32_C(0x16A3): // RUNIC LETTER YR
	case UINT32_C(0x16A4): // RUNIC LETTER Y
	case UINT32_C(0x16A5): // RUNIC LETTER W
	case UINT32_C(0x16A6): // RUNIC LETTER THURISAZ THURS THORN
	case UINT32_C(0x16A7): // RUNIC LETTER ETH
	case UINT32_C(0x16A8): // RUNIC LETTER ANSUZ A
	case UINT32_C(0x16A9): // RUNIC LETTER OS O
	case UINT32_C(0x16AA): // RUNIC LETTER AC A
	case UINT32_C(0x16AB): // RUNIC LETTER AESC
	case UINT32_C(0x16AC): // RUNIC LETTER LONG-BRANCH-OSS O
	case UINT32_C(0x16AD): // RUNIC LETTER SHORT-TWIG-OSS O
	case UINT32_C(0x16AE): // RUNIC LETTER O
	case UINT32_C(0x16AF): // RUNIC LETTER OE
	case UINT32_C(0x16B0): // RUNIC LETTER ON
	case UINT32_C(0x16B1): // RUNIC LETTER RAIDO RAD REID R
	case UINT32_C(0x16B2): // RUNIC LETTER KAUNA
	case UINT32_C(0x16B3): // RUNIC LETTER CEN
	case UINT32_C(0x16B4): // RUNIC LETTER KAUN K
	case UINT32_C(0x16B5): // RUNIC LETTER G
	case UINT32_C(0x16B6): // RUNIC LETTER ENG
	case UINT32_C(0x16B7): // RUNIC LETTER GEBO GYFU G
	case UINT32_C(0x16B8): // RUNIC LETTER GAR
	case UINT32_C(0x16B9): // RUNIC LETTER WUNJO WYNN W
	case UINT32_C(0x16BA): // RUNIC LETTER HAGLAZ H
	case UINT32_C(0x16BB): // RUNIC LETTER HAEGL H
	case UINT32_C(0x16BC): // RUNIC LETTER LONG-BRANCH-HAGALL H
	case UINT32_C(0x16BD): // RUNIC LETTER SHORT-TWIG-HAGALL H
	case UINT32_C(0x16BE): // RUNIC LETTER NAUDIZ NYD NAUD N
	case UINT32_C(0x16BF): // RUNIC LETTER SHORT-TWIG-NAUD N
	case UINT32_C(0x16C0): // RUNIC LETTER DOTTED-N
	case UINT32_C(0x16C1): // RUNIC LETTER ISAZ IS ISS I
	case UINT32_C(0x16C2): // RUNIC LETTER E
	case UINT32_C(0x16C3): // RUNIC LETTER JERAN J
	case UINT32_C(0x16C4): // RUNIC LETTER GER
	case UINT32_C(0x16C5): // RUNIC LETTER LONG-BRANCH-AR AE
	case UINT32_C(0x16C6): // RUNIC LETTER SHORT-TWIG-AR A
	case UINT32_C(0x16C7): // RUNIC LETTER IWAZ EOH
	case UINT32_C(0x16C8): // RUNIC LETTER PERTHO PEORTH P
	case UINT32_C(0x16C9): // RUNIC LETTER ALGIZ EOLHX
	case UINT32_C(0x16CA): // RUNIC LETTER SOWILO S
	case UINT32_C(0x16CB): // RUNIC LETTER SIGEL LONG-BRANCH-SOL S
	case UINT32_C(0x16CC): // RUNIC LETTER SHORT-TWIG-SOL S
	case UINT32_C(0x16CD): // RUNIC LETTER C
	case UINT32_C(0x16CE): // RUNIC LETTER Z
	case UINT32_C(0x16CF): // RUNIC LETTER TIWAZ TIR TYR T
	case UINT32_C(0x16D0): // RUNIC LETTER SHORT-TWIG-TYR T
	case UINT32_C(0x16D1): // RUNIC LETTER D
	case UINT32_C(0x16D2): // RUNIC LETTER BERKANAN BEORC BJARKAN B
	case UINT32_C(0x16D3): // RUNIC LETTER SHORT-TWIG-BJARKAN B
	case UINT32_C(0x16D4): // RUNIC LETTER DOTTED-P
	case UINT32_C(0x16D5): // RUNIC LETTER OPEN-P
	case UINT32_C(0x16D6): // RUNIC LETTER EHWAZ EH E
	case UINT32_C(0x16D7): // RUNIC LETTER MANNAZ MAN M
	case UINT32_C(0x16D8): // RUNIC LETTER LONG-BRANCH-MADR M
	case UINT32_C(0x16D9): // RUNIC LETTER SHORT-TWIG-MADR M
	case UINT32_C(0x16DA): // RUNIC LETTER LAUKAZ LAGU LOGR L
	case UINT32_C(0x16DB): // RUNIC LETTER DOTTED-L
	case UINT32_C(0x16DC): // RUNIC LETTER INGWAZ
	case UINT32_C(0x16DD): // RUNIC LETTER ING
	case UINT32_C(0x16DE): // RUNIC LETTER DAGAZ DAEG D
	case UINT32_C(0x16DF): // RUNIC LETTER OTHALAN ETHEL O
	case UINT32_C(0x16E0): // RUNIC LETTER EAR
	case UINT32_C(0x16E1): // RUNIC LETTER IOR
	case UINT32_C(0x16E2): // RUNIC LETTER CWEORTH
	case UINT32_C(0x16E3): // RUNIC LETTER CALC
	case UINT32_C(0x16E4): // RUNIC LETTER CEALC
	case UINT32_C(0x16E5): // RUNIC LETTER STAN
	case UINT32_C(0x16E6): // RUNIC LETTER LONG-BRANCH-YR
	case UINT32_C(0x16E7): // RUNIC LETTER SHORT-TWIG-YR
	case UINT32_C(0x16E8): // RUNIC LETTER ICELANDIC-YR
	case UINT32_C(0x16E9): // RUNIC LETTER Q F
	case UINT32_C(0x16EA): // RUNIC LETTER X
		return true;
	}
}
