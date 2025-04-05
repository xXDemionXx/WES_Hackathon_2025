/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --font C:/Users/karlo.saric/Documents/1_Code/hackathon/WES_Hackathon_2025/components/gui/squareline/project/assets/Inlanders Demo.otf -o C:/Users/karlo.saric/Documents/1_Code/hackathon/WES_Hackathon_2025/components/gui/squareline/project/assets\ui_font_FontStocks.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONTSTOCKS
#define UI_FONT_FONTSTOCKS 1
#endif

#if UI_FONT_FONTSTOCKS

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xf3, 0xc0,

    /* U+0022 "\"" */
    0xff,

    /* U+0023 "#" */
    0x19, 0x86, 0x47, 0xfd, 0xff, 0x33, 0x3f, 0xef,
    0xf8, 0x98, 0x26, 0x0,

    /* U+0024 "$" */
    0x30, 0x61, 0xff, 0xfc, 0x18, 0x3f, 0x3f, 0xf,
    0xff, 0xf1, 0x83, 0x0,

    /* U+0025 "%" */
    0x61, 0x1e, 0x63, 0xd8, 0x33, 0x0, 0xc0, 0x1b,
    0x86, 0x50, 0x8a, 0x31, 0xc0,

    /* U+0026 "&" */
    0x78, 0xfc, 0xfc, 0xf8, 0xf0, 0xfe, 0xfe, 0xfe,
    0x7e,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x7f, 0x6d, 0xb6, 0xdb, 0xb0,

    /* U+0029 ")" */
    0xdd, 0xb6, 0xdb, 0x6f, 0xe0,

    /* U+002A "*" */
    0x32, 0xdf, 0xde, 0x78, 0x0,

    /* U+002B "+" */
    0x37, 0xfe, 0x63, 0x0,

    /* U+002C "," */
    0xf4,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x19, 0xce, 0x63, 0x39, 0x8c, 0xe7, 0x0,

    /* U+0030 "0" */
    0x0,

    /* U+0031 "1" */
    0x0,

    /* U+0032 "2" */
    0x0,

    /* U+0033 "3" */
    0x0,

    /* U+0034 "4" */
    0x0,

    /* U+0035 "5" */
    0x0,

    /* U+0036 "6" */
    0x0,

    /* U+0037 "7" */
    0x0,

    /* U+0038 "8" */
    0x0,

    /* U+0039 "9" */
    0x0,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0xf0, 0xf4,

    /* U+003C "<" */
    0x11, 0x99, 0x86, 0x18, 0x40,

    /* U+003D "=" */
    0xff, 0xc1, 0xff, 0x80,

    /* U+003E ">" */
    0x47, 0x1c, 0x77, 0x71, 0x0,

    /* U+003F "?" */
    0x7b, 0xfe, 0xc6, 0x18, 0xc0, 0xc, 0x30,

    /* U+0040 "@" */
    0x1e, 0xf, 0xc6, 0x3b, 0xff, 0xf6, 0xfd, 0xbf,
    0x6f, 0xff, 0x70, 0xf, 0xc1, 0xe0,

    /* U+0041 "A" */
    0x7c, 0xf9, 0xb3, 0x6f, 0xdf, 0xfb, 0xf7, 0xee,

    /* U+0042 "B" */
    0xfd, 0xff, 0x3e, 0x7f, 0xff, 0xf3, 0xff, 0xfc,

    /* U+0043 "C" */
    0x7f, 0xfc, 0x30, 0xc3, 0xc, 0x3f, 0x7c,

    /* U+0044 "D" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0xf8,

    /* U+0045 "E" */
    0xff, 0xfe, 0x38, 0xfb, 0xee, 0x3f, 0xfc,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xfb, 0xec, 0x30, 0xc0,

    /* U+0047 "G" */
    0x7f, 0xfc, 0x30, 0xcf, 0x3c, 0xff, 0x7c,

    /* U+0048 "H" */
    0xcf, 0x3c, 0xf3, 0xff, 0xfc, 0xf3, 0xcc,

    /* U+0049 "I" */
    0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0xff, 0xf0, 0xc3, 0xc, 0x30, 0xff, 0xf8,

    /* U+004B "K" */
    0xdf, 0x7f, 0xbc, 0xfb, 0xed, 0xf7, 0xcc,

    /* U+004C "L" */
    0xc6, 0x31, 0x8c, 0x63, 0x1f, 0xf8,

    /* U+004D "M" */
    0xc3, 0xe7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xc3,
    0xc3,

    /* U+004E "N" */
    0xcf, 0xbf, 0xff, 0xff, 0xff, 0xf7, 0xcc,

    /* U+004F "O" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0x78,

    /* U+0050 "P" */
    0xfd, 0xff, 0x3e, 0x7f, 0xff, 0xb0, 0x60, 0xc0,

    /* U+0051 "Q" */
    0x79, 0xfb, 0x36, 0x6c, 0xd9, 0xb3, 0x7e, 0x7e,
    0x8,

    /* U+0052 "R" */
    0xfb, 0xfc, 0xf3, 0xff, 0xfc, 0xf3, 0xcc,

    /* U+0053 "S" */
    0x7f, 0xff, 0x6, 0xf, 0xcf, 0xc3, 0xff, 0xfc,

    /* U+0054 "T" */
    0xff, 0xfc, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,

    /* U+0055 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xff, 0x78,

    /* U+0056 "V" */
    0xcf, 0x3f, 0xff, 0x7d, 0xe7, 0x9e, 0x78,

    /* U+0057 "W" */
    0xe1, 0xf8, 0x76, 0x1d, 0xb7, 0x7f, 0xdf, 0xf7,
    0xfd, 0xef, 0x73, 0xc0,

    /* U+0058 "X" */
    0xec, 0xf9, 0xe3, 0xc3, 0x8f, 0x1e, 0x3e, 0xec,

    /* U+0059 "Y" */
    0xfd, 0xe7, 0x9e, 0x30, 0xc3, 0xc, 0x30,

    /* U+005A "Z" */
    0xff, 0xfc, 0x79, 0xe3, 0x8f, 0x3c, 0x7f, 0xfe,

    /* U+005B "[" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc7, 0xfe,

    /* U+005C "\\" */
    0xc7, 0x18, 0xc7, 0x38, 0xc6, 0x38, 0xc0,

    /* U+005D "]" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x1f, 0xfe,

    /* U+005E "^" */
    0x76, 0x80,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xf0,

    /* U+0061 "a" */
    0x7c, 0xf9, 0xb3, 0x6f, 0xdf, 0xfb, 0xf7, 0xee,

    /* U+0062 "b" */
    0xfd, 0xff, 0x3e, 0x7f, 0xff, 0xf3, 0xff, 0xfc,

    /* U+0063 "c" */
    0x7f, 0xfc, 0x30, 0xc3, 0xc, 0x3f, 0x7c,

    /* U+0064 "d" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0xf8,

    /* U+0065 "e" */
    0xff, 0xfe, 0x38, 0xfb, 0xee, 0x3f, 0xfc,

    /* U+0066 "f" */
    0xff, 0xfc, 0x30, 0xfb, 0xec, 0x30, 0xc0,

    /* U+0067 "g" */
    0x7f, 0xfc, 0x30, 0xcf, 0x3c, 0xff, 0x7c,

    /* U+0068 "h" */
    0xcf, 0x3c, 0xf3, 0xff, 0xfc, 0xf3, 0xcc,

    /* U+0069 "i" */
    0xff, 0xff, 0xc0,

    /* U+006A "j" */
    0xff, 0xf0, 0xc3, 0xc, 0x30, 0xff, 0xf8,

    /* U+006B "k" */
    0xdf, 0x7f, 0xbc, 0xfb, 0xed, 0xf7, 0xcc,

    /* U+006C "l" */
    0xc6, 0x31, 0x8c, 0x63, 0x1f, 0xf8,

    /* U+006D "m" */
    0xc3, 0xe7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xc3,
    0xc3,

    /* U+006E "n" */
    0xcf, 0xbf, 0xff, 0xff, 0xff, 0xf7, 0xcc,

    /* U+006F "o" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0x78,

    /* U+0070 "p" */
    0xfd, 0xff, 0x3e, 0x7f, 0xff, 0xb0, 0x60, 0xc0,

    /* U+0071 "q" */
    0x79, 0xfb, 0x36, 0x6c, 0xd9, 0xb3, 0x7e, 0x7e,
    0x8,

    /* U+0072 "r" */
    0xfb, 0xfc, 0xf3, 0xff, 0xfc, 0xf3, 0xcc,

    /* U+0073 "s" */
    0x7f, 0xff, 0x6, 0xf, 0xcf, 0xc3, 0xff, 0xfc,

    /* U+0074 "t" */
    0xff, 0xfc, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xff, 0x78,

    /* U+0076 "v" */
    0xcf, 0x3f, 0xff, 0x7d, 0xe7, 0x9e, 0x78,

    /* U+0077 "w" */
    0xe1, 0xf8, 0x76, 0x1d, 0xb7, 0x7f, 0xdf, 0xf7,
    0xfd, 0xef, 0x73, 0xc0,

    /* U+0078 "x" */
    0xec, 0xf9, 0xe3, 0xc3, 0x8f, 0x1e, 0x3e, 0xec,

    /* U+0079 "y" */
    0xfd, 0xe7, 0x9e, 0x30, 0xc3, 0xc, 0x30,

    /* U+007A "z" */
    0xff, 0xfc, 0x79, 0xe3, 0x8f, 0x3c, 0x7f, 0xfe,

    /* U+007B "{" */
    0x3e, 0xfd, 0xc3, 0x8f, 0x1e, 0x1c, 0x38, 0x70,
    0xfc, 0xf8,

    /* U+007C "|" */
    0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xf9, 0xf0, 0x70, 0xe1, 0xe3, 0xc7, 0xe, 0x1d,
    0xf3, 0xe0,

    /* U+007E "~" */
    0xed, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 48, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 49, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 74, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 5, .adv_w = 173, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 114, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 29, .adv_w = 175, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 134, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 38, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 52, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 57, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 62, .adv_w = 98, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 67, .adv_w = 92, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 71, .adv_w = 49, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 72, .adv_w = 84, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 74, .adv_w = 49, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 93, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 113, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 79, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 116, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 106, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 116, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 115, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 116, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 116, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 116, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 116, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 49, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 94, .adv_w = 50, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 96, .adv_w = 81, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 101, .adv_w = 85, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 105, .adv_w = 81, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 110, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 172, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 131, .adv_w = 120, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 49, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 90, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 252, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 158, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 114, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 90, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 331, .adv_w = 93, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 89, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 345, .adv_w = 84, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 347, .adv_w = 132, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 348, .adv_w = 38, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 349, .adv_w = 120, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 49, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 90, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 470, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 158, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 114, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 534, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 111, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 552, .adv_w = 49, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 555, .adv_w = 111, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 565, .adv_w = 104, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 2,
    2, 32,
    18, 21,
    32, 32,
    34, 36,
    34, 40,
    34, 48,
    34, 50,
    34, 53,
    34, 55,
    34, 56,
    34, 57,
    34, 58,
    37, 34,
    37, 38,
    37, 53,
    37, 55,
    37, 56,
    37, 57,
    37, 58,
    39, 34,
    39, 36,
    39, 48,
    39, 50,
    39, 57,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    45, 48,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    48, 34,
    48, 55,
    48, 57,
    48, 58,
    49, 34,
    49, 55,
    49, 57,
    49, 58,
    50, 36,
    50, 40,
    50, 48,
    50, 50,
    50, 53,
    50, 54,
    50, 55,
    50, 56,
    50, 58,
    51, 55,
    51, 58,
    52, 34,
    53, 34,
    54, 34,
    55, 34,
    55, 36,
    55, 40,
    55, 48,
    55, 52,
    55, 57,
    55, 58,
    56, 34,
    57, 36,
    57, 40,
    57, 48,
    58, 34,
    58, 36,
    58, 40,
    58, 48,
    58, 50,
    58, 52,
    58, 53,
    58, 55,
    66, 68,
    66, 72,
    66, 80,
    66, 82,
    66, 85,
    66, 87,
    66, 88,
    66, 89,
    66, 90,
    67, 66,
    67, 80,
    67, 85,
    67, 87,
    67, 89,
    67, 90,
    69, 87,
    69, 89,
    69, 90,
    71, 66,
    73, 90,
    76, 68,
    76, 72,
    76, 80,
    76, 82,
    77, 85,
    77, 87,
    77, 90,
    80, 87,
    80, 89,
    80, 90,
    81, 87,
    81, 89,
    81, 90,
    82, 66,
    82, 68,
    82, 72,
    82, 80,
    82, 82,
    82, 85,
    82, 86,
    82, 87,
    82, 88,
    82, 89,
    82, 90,
    83, 87,
    83, 89,
    83, 90,
    84, 90,
    85, 66,
    85, 68,
    85, 72,
    85, 84,
    87, 66,
    87, 68,
    87, 72,
    87, 80,
    87, 82,
    87, 84,
    88, 66,
    89, 72,
    89, 80,
    90, 66,
    90, 68,
    90, 72,
    90, 80,
    90, 82,
    90, 84
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    3, -6, -16, -3, -6, -6, -6, -6,
    -9, -16, -9, -4, -19, -6, -4, -3,
    -9, -6, -16, -16, -16, -3, -3, -3,
    -3, -12, -9, -9, -12, -5, -31, -23,
    -8, -31, -7, -7, -12, -16, -12, -9,
    -16, -16, -19, -19, -19, -19, -19, -19,
    -22, -13, -19, -9, -16, -9, -12, -6,
    -19, -9, -9, -8, -9, -5, -2, -9,
    -12, -16, -13, -17, -16, -16, -12, -14,
    -16, -6, -3, -6, -6, -6, -6, -9,
    -16, -9, -3, -19, -3, -3, -3, -6,
    -9, -12, -6, -9, -9, -9, -3, -9,
    -12, -16, -16, -34, -16, -34, -6, -16,
    -16, -6, -16, -9, -3, -16, -16, -16,
    -16, -16, -19, -19, -9, -3, -28, -9,
    -3, -9, -3, -9, -3, -3, -3, -16,
    -6, -6, -6, -6, -6, -9, -9, -16,
    -16, -9, -9, -16, -9, -9
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 142,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_FontStocks = {
#else
lv_font_t ui_font_FontStocks = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONTSTOCKS*/

