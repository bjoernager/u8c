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
# include <u8c/main.h>
# include <u8c/str.h>
# include <uchar.h>
# define u8c_uniblk_isinrng(val,start,end) (val >= start && val <= end)
struct u8c_uniblk_tuple u8c_uniblk(char32_t const _chr) {
	struct u8c_uniblk_tuple ret = {
		.stat = false,
	};
	char32_t const * blk = U"UNDEFINED IN UNICODE";
	if(_chr <= U'\x7F') {
		blk = U"BASIC LATIN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\x80',U'\u00FF')) {
		blk = U"LATIN-1 SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0100',U'\u017F')) {
		blk = U"LATIN EXTENDED-A";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0180',U'\u024F')) {
		blk = U"LATIN EXTENDED-B";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0250',U'\u02AF')) {
		blk = U"IPA EXTENSIONS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u02B0',U'\u02FF')) {
		blk = U"SPACING MODIFIER LETTERS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0300',U'\u036F')) {
		blk = U"COMBINING DIRACITICAL MARKS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0370',U'\u03FF')) {
		blk = U"GREEK AND COPTIC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0400',U'\u04FF')) {
		blk = U"CYRILLIC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0500',U'\u052F')) {
		blk = U"CYRILLIC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0530',U'\u058F')) {
		blk = U"ARMENIAN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0590',U'\u05FF')) {
		blk = U"HEBREW";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0600',U'\u06FF')) {
		blk = U"ARABIC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0700',U'\u074F')) {
		blk = U"SYRIAC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0750',U'\u077F')) {
		blk = U"ARABIC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0780',U'\u07BF')) {
		blk = U"THAANA";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u07C0',U'\u07FF')) {
		blk = U"NKO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0800',U'\u083F')) {
		blk = U"SAMARITAN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0840',U'\u085F')) {
		blk = U"MANDAIC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0860',U'\u086F')) {
		blk = U"SYRIAC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u08A0',U'\u08FF')) {
		blk = U"ARABIC EXTENDED-A";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0900',U'\u097F')) {
		blk = U"DEVANAGARI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0980',U'\u09FF')) {
		blk = U"BENGALI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0A00',U'\u0A7F')) {
		blk = U"GURMUKHI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0A80',U'\u0AFF')) {
		blk = U"GUJARATI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0B00',U'\u0B7F')) {
		blk = U"ORIYAS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0B80',U'\u0BFF')) {
		blk = U"TAMIL";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0C00',U'\u0C7F')) {
		blk = U"TELUGU";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0C80',U'\u0CFF')) {
		blk = U"KANNADA";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0D00',U'\u0D7F')) {
		blk = U"MALAYALAM";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0D80',U'\u0DFF')) {
		blk = U"SINHALA";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0E00',U'\u0E7F')) {
		blk = U"THAI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0E80',U'\u0EFF')) {
		blk = U"LAO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u0F00',U'\u0FFF')) {
		blk = U"TIBETAN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1000',U'\u109F')) {
		blk = U"MYANMAR";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u10A0',U'\u10FF')) {
		blk = U"GEORGIAN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1100',U'\u11FF')) {
		blk = U"HANGUL JAMO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1200',U'\u137F')) {
		blk = U"ETHIOPIC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1380',U'\u139F')) {
		blk = U"ETHIOPIC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u13A0',U'\u13FF')) {
		blk = U"CHEROKEE";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1400',U'\u167F')) {
		blk = U"UNIFIED CANADIAN ABORIGINAL SYLLABICS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1680',U'\u169F')) {
		blk = U"OGHAM";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u16A0',U'\u16FF')) {
		blk = U"RUNIC";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\u1700',U'\u171F')) {
		blk = U"TAGALOG";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011A00',U'\U00011A4F')) {
		blk = U"ZANABAZAR SQUARE";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011A50',U'\U00011AAF')) {
		blk = U"SOYOMBO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011AC0',U'\U00011AFF')) {
		blk = U"PAU CIN HAU";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011C00',U'\U00011C6F')) {
		blk = U"BHAIKSUKI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011C70',U'\U00011CBF')) {
		blk = U"MARCHEN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011D00',U'\U00011D5F')) {
		blk = U"MASARAM GONDI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011D60',U'\U00011DAF')) {
		blk = U"GUNJALA GONDI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011EE0',U'\U00011EFF')) {
		blk = U"MAKASAR";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011FB0',U'\U00011FBF')) {
		blk = U"LISU SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00011FC0',U'\U00011FFF')) {
		blk = U"TAMIL SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00012000',U'\U000123FF')) {
		blk = U"CUNEIFORM";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00012400',U'\U0001247F')) {
		blk = U"CUNEIFORM NUMBERS AND PUNCTUATION";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00012480',U'\U0001254F')) {
		blk = U"EARLY DYNASTIC CUNEIFORM";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00013000',U'\U0001342F')) {
		blk = U"EGYPTIAN HIEROGLYPHS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00013430',U'\U0001343F')) {
		blk = U"EGYPTIAN HIEROGLYPH FORMAT CONTROLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00014400',U'\U0001467F')) {
		blk = U"ANATOLIAN HIEROGLYPHS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016800',U'\U00016A3F')) {
		blk = U"BAMUM SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016A40',U'\U00016A6F')) {
		blk = U"MRO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016AD0',U'\U00016AFF')) {
		blk = U"BASSA VAH";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016B00',U'\U00016B8F')) {
		blk = U"PAHAWH HMONG";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016E40',U'\U00016E9F')) {
		blk = U"MEDEFAIDRIN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016F00',U'\U00016F9F')) {
		blk = U"MIAO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00016FE0',U'\U00016FFF')) {
		blk = U"IDEOGRAPHIC SYMBOLS AND PUNCTUATION";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00017000',U'\U000187FF')) {
		blk = U"TANGUT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00018800',U'\U00018AFF')) {
		blk = U"TANGUT COMPONENTS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00018B00',U'\U00018CFF')) {
		blk = U"KHITAN SMALL SCRIPT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00018D00',U'\U00018D8F')) {
		blk = U"TANGUT SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001B000',U'\U0001B0FF')) {
		blk = U"KANA SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001B100',U'\U0001B12F')) {
		blk = U"KANA EXTENDED-A";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001B130',U'\U0001B16F')) {
		blk = U"SMALL KANA EXTENSION";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001B170',U'\U0001B2FF')) {
		blk = U"NUSHU";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001BC00',U'\U0001BC9F')) {
		blk = U"DUPLOYAN";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001BCA0',U'\U0001BCAF')) {
		blk = U"SHORTHAND FORMAT CONTROLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D000',U'\U0001D0FF')) {
		blk = U"BYZANTINE MUSICAL SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D100',U'\U0001D1FF')) {
		blk = U"MUSICAL SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D200',U'\U0001D24F')) {
		blk = U"ANCIENT GREEK MUSICAL NOTATION";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D2E0',U'\U0001D2FF')) {
		blk = U"MAYAN NUMERALS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D300',U'\U0001D35F')) {
		blk = U"TAI XUAN JING SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D360',U'\U0001D37F')) {
		blk = U"COUNTING ROD NUMERALS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D400',U'\U0001D7FF')) {
		blk = U"MATHEMATICAL ALPHANUMERIC SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001D800',U'\U0001DAAF')) {
		blk = U"SUTTON SIGNWRITING";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001E000',U'\U0001E02F')) {
		blk = U"GLAGOLITIC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001E100',U'\U0001E14F')) {
		blk = U"NYIAKENG PUACHUE HMONG";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001E2C0',U'\U0001E2FF')) {
		blk = U"WANCHO";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001E800',U'\U0001E8DF')) {
		blk = U"MENDE KIKAKUI";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001E900',U'\U0001E95F')) {
		blk = U"ADLAM";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001EC70',U'\U0001ECBF')) {
		blk = U"INDIC SIYAQ NUMBERS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001ED00',U'\U0001ED4F')) {
		blk = U"OTTOMAN SIYAQ NUMBERS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001EE00',U'\U0001EEFF')) {
		blk = U"ARABIC MATHEMATICAL ALPHABETIC SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F000',U'\U0001F02F')) {
		blk = U"MAHJONG TILES";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F030',U'\U0001F09F')) {
		blk = U"DOMINO TILES";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F0A0',U'\U0001F0FF')) {
		blk = U"PLAYING CARDS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F100',U'\U0001F1FF')) {
		blk = U"ENCLOSED ALPHANUMERIC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F200',U'\U0001F2FF')) {
		blk = U"ENCLOSED IDEOGRAPHIC SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F300',U'\U0001F5FF')) {
		blk = U"MISCELLANEOUS SYMBOLS AND PICTOGRAPHS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F600',U'\U0001F64F')) {
		blk = U"EMOTICONS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F650',U'\U0001F67F')) {
		blk = U"ORNAMENTAL DINGBATS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F680',U'\U0001F6FF')) {
		blk = U"TRANSPORT AND MAP SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F700',U'\U0001F77F')) {
		blk = U"ALCHEMICAL SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F780',U'\U0001F7FF')) {
		blk = U"GEOMETRIC SHAPES EXTENDED";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F800',U'\U0001F8FF')) {
		blk = U"SUPPLEMENTAL ARROWS-C";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001F900',U'\U0001F9FF')) {
		blk = U"SUPPLEMENTAL SYMBOLS AND PICTOGRAPHS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001FA00',U'\U0001FA6F')) {
		blk = U"CHESS SYMBOLS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001FA70',U'\U0001FAFF')) {
		blk = U"SYMBOLS AND PICTOGRAPHS EXTENDED-A";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0001FB00',U'\U0001FBFF')) {
		blk = U"SYMBOLS FOR LEGACY COMPUTING";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00020000',U'\U0002A6DF')) {
		blk = U"CJK UNIFIED IDEOGRAPHS EXTENSION B";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0002A700',U'\U0002B73F')) {
		blk = U"CJK UNIFIED IDEOGRAPHS EXTENSION C";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0002B740',U'\U0002B81F')) {
		blk = U"CJK UNIFIED IDEOGRAPHS EXTENSION D";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0002B820',U'\U0002CEAF')) {
		blk = U"CJK UNIFIED IDEOGRAPHS EXTENSION E";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0002CEB0',U'\U0002EBEF')) {
		blk = U"CJK UNIFIED IDEOGRAPHS EXTENSION F";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U0002F800',U'\U0002FA1F')) {
		blk = U"CJK COMPATIBILITY IDEOGRAPHS SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00030000',U'\U0003134F')) {
		blk = U"CJK UNIFIED IDEOGRAPHS EXTENSION G";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U000E0000',U'\U000E007F')) {
		blk = U"TAGS";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U000E0100',U'\U000E1EFF')) {
		blk = U"VARIATION SELECTORS SUPPLEMENT";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U000F0000',U'\U000FFFFF')) {
		blk = U"SUPPLEMENTARY PRIVATE USE AREA-A";
		goto end;
	}
	if(u8c_uniblk_isinrng(_chr,U'\U00100000',U'\U0010FFFF')) {
		blk = U"SUPPLEMENTARY PRIVATE USE AREA-B";
		goto end;
	}
	if(_chr > u8c_unimax) {
		ret.stat = true;
		return ret;
	}
end:;
	{
		struct u8c_strcp_tuple const tuple     = u8c_strcp(blk);
		                             ret.blk   = tuple.str;
	   	                             ret.blksz = tuple.strsz;
	}
	return ret;
}
