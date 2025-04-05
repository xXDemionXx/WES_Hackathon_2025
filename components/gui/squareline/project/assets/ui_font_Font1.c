/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font C:/Users/karlo.saric/Documents/1_Code/hackathon/WES_Hackathon_2025/components/gui/squareline/project/assets/BroncoPersonalUse.ttf -o C:/Users/karlo.saric/Documents/1_Code/hackathon/WES_Hackathon_2025/components/gui/squareline/project/assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf0, 0xf0,

    /* U+0022 "\"" */
    0xda, 0xd6, 0xb0,

    /* U+0023 "#" */
    0xc, 0x81, 0xb0, 0x26, 0x1f, 0xf7, 0xfc, 0x32,
    0x6, 0x40, 0xd8, 0x13, 0xf, 0xf9, 0xff, 0x19,
    0x83, 0x20, 0x4c, 0x0,

    /* U+0025 "%" */
    0x3, 0x0, 0xcf, 0x62, 0x58, 0x96, 0x3f, 0x80,
    0xc0, 0x30, 0x1f, 0xc6, 0x91, 0xa4, 0x6f, 0x30,
    0xc, 0x0,

    /* U+0027 "'" */
    0xd5,

    /* U+0028 "(" */
    0x7f, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,
    0x70,

    /* U+0029 ")" */
    0xef, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,
    0xe0,

    /* U+002A "*" */
    0x25, 0xff, 0xfb, 0x90,

    /* U+002B "+" */
    0x30, 0x63, 0xff, 0xf3, 0x6, 0xc, 0x0,

    /* U+002C "," */
    0xfd, 0x80,

    /* U+002D "-" */
    0xff, 0xfc,

    /* U+002E "." */
    0xfc,

    /* U+002F "/" */
    0x6, 0xc, 0x30, 0x60, 0xc3, 0x6, 0xc, 0x30,
    0x60, 0xc3, 0x6, 0xc, 0x30, 0x60,

    /* U+0030 "0" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0031 "1" */
    0x6e, 0xe6, 0x66, 0x66, 0x66, 0x66, 0x66,

    /* U+0032 "2" */
    0x7b, 0xfc, 0xf3, 0x4c, 0x31, 0xde, 0xe3, 0xc,
    0x30, 0xff, 0xf0,

    /* U+0033 "3" */
    0x7b, 0xfc, 0xf3, 0xc, 0x33, 0x8f, 0xc, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0034 "4" */
    0x6, 0xe, 0xe, 0x1e, 0x1e, 0x36, 0x36, 0x76,
    0x66, 0xff, 0xff, 0x6, 0x6, 0x6,

    /* U+0035 "5" */
    0xff, 0xfc, 0x30, 0xc3, 0xef, 0xc3, 0xf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0036 "6" */
    0x7b, 0xfc, 0xf3, 0xc3, 0xf, 0xbf, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0037 "7" */
    0xff, 0xff, 0x32, 0x60, 0xc3, 0x86, 0xc, 0x18,
    0x70, 0xc1, 0x83, 0xe, 0x0,

    /* U+0038 "8" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x37, 0x9f, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0039 "9" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3f, 0xdf, 0xc, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+003A ":" */
    0xfc, 0x3, 0xf0,

    /* U+003B ";" */
    0xfc, 0x3, 0xf6,

    /* U+003C "<" */
    0x18, 0xcc, 0xc6, 0x31, 0x86, 0x18, 0xc0,

    /* U+003D "=" */
    0xff, 0xfc, 0x7, 0xff, 0xe0,

    /* U+003E ">" */
    0x43, 0xc, 0x61, 0x8c, 0xc6, 0x62, 0x0,

    /* U+003F "?" */
    0x7b, 0xfc, 0xf3, 0xc, 0x31, 0xce, 0x30, 0xc3,
    0x0, 0x30, 0xc0,

    /* U+0041 "A" */
    0x1c, 0xe, 0x7, 0x6, 0x83, 0x61, 0xb1, 0xdc,
    0x6c, 0x7e, 0x3f, 0x18, 0xcc, 0x66, 0x37, 0x18,

    /* U+0042 "B" */
    0x7c, 0xfd, 0x9b, 0x36, 0x6c, 0xdf, 0x3f, 0x66,
    0xcd, 0x9b, 0x37, 0xef, 0x80,

    /* U+0043 "C" */
    0x3c, 0xfd, 0x9b, 0x36, 0x4c, 0x18, 0x30, 0x60,
    0xc9, 0x9b, 0x37, 0xe7, 0x80,

    /* U+0044 "D" */
    0x7c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x7c,

    /* U+0045 "E" */
    0x7e, 0xfd, 0x8b, 0x6, 0xc, 0x1f, 0x3e, 0x60,
    0xc1, 0x83, 0x17, 0xef, 0xc0,

    /* U+0046 "F" */
    0x7e, 0xfd, 0x8b, 0x6, 0xc, 0x1f, 0x3e, 0x60,
    0xc1, 0x83, 0x6, 0xc, 0x0,

    /* U+0047 "G" */
    0x3c, 0x7e, 0x66, 0x66, 0x64, 0x60, 0x6e, 0x6e,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c,

    /* U+0048 "H" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x7e,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,

    /* U+0049 "I" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,

    /* U+004A "J" */
    0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6, 0xc,
    0x9b, 0x36, 0x6f, 0xcf, 0x0,

    /* U+004B "K" */
    0x67, 0x66, 0x6e, 0x6c, 0x6c, 0x78, 0x78, 0x78,
    0x78, 0x6c, 0x6c, 0x6e, 0x66, 0x67,

    /* U+004C "L" */
    0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60,
    0xc1, 0x83, 0x17, 0xef, 0xc0,

    /* U+004D "M" */
    0x61, 0x98, 0x66, 0x39, 0xce, 0x73, 0x9c, 0xe7,
    0xf9, 0xfe, 0x6d, 0x9b, 0x66, 0xd9, 0x86, 0x61,
    0x98, 0x60,

    /* U+004E "N" */
    0x63, 0x39, 0x9c, 0xce, 0x67, 0xb3, 0xd9, 0xec,
    0xde, 0x6f, 0x33, 0x99, 0xcc, 0xe6, 0x33, 0x18,

    /* U+004F "O" */
    0x3c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c,

    /* U+0050 "P" */
    0x7c, 0xfd, 0x9b, 0x36, 0x6c, 0xd9, 0xbf, 0x7c,
    0xc1, 0x83, 0x6, 0xc, 0x0,

    /* U+0051 "Q" */
    0x3c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c, 0x8, 0xc,

    /* U+0052 "R" */
    0x7c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0xfe, 0x7c,
    0x6c, 0x6c, 0x6e, 0x66, 0x66, 0x66,

    /* U+0053 "S" */
    0x7b, 0xfc, 0xf3, 0xc3, 0x87, 0xe, 0xc, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0054 "T" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+0055 "U" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c,

    /* U+0056 "V" */
    0xe3, 0x31, 0x98, 0xcc, 0x66, 0x61, 0x31, 0xd8,
    0xec, 0x36, 0x1a, 0xf, 0x3, 0x81, 0xc1, 0xe0,

    /* U+0057 "W" */
    0xee, 0xec, 0xcd, 0xbb, 0x37, 0x66, 0xec, 0xdd,
    0x9a, 0xb3, 0x56, 0x3b, 0xc7, 0x70, 0xee, 0x1d,
    0xc3, 0xb8, 0x77, 0x0,

    /* U+0058 "X" */
    0xe7, 0x66, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
    0x3c, 0x3c, 0x3c, 0x66, 0x66, 0xe7,

    /* U+0059 "Y" */
    0xe7, 0x66, 0x66, 0x24, 0x3c, 0x3c, 0x3c, 0x3c,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0xf1, 0xc6, 0x18, 0xe7, 0x1c, 0x71, 0x86,
    0x39, 0xff, 0xf0,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0xff,

    /* U+005C "\\" */
    0xc1, 0x81, 0x83, 0x6, 0x6, 0xc, 0x18, 0x18,
    0x30, 0x60, 0x60, 0xc1, 0x81, 0x83,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0xff,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0061 "a" */
    0x1c, 0xe, 0x7, 0x6, 0x83, 0x61, 0xb1, 0xdc,
    0x6c, 0x7e, 0x3f, 0x18, 0xcc, 0x66, 0x37, 0x18,

    /* U+0062 "b" */
    0x7c, 0xfd, 0x9b, 0x36, 0x6c, 0xdf, 0x3f, 0x66,
    0xcd, 0x9b, 0x37, 0xef, 0x80,

    /* U+0063 "c" */
    0x3c, 0xfd, 0x9b, 0x36, 0x4c, 0x18, 0x30, 0x60,
    0xc9, 0x9b, 0x37, 0xe7, 0x80,

    /* U+0064 "d" */
    0x7c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x7c,

    /* U+0065 "e" */
    0x7e, 0xfd, 0x8b, 0x6, 0xc, 0x1f, 0x3e, 0x60,
    0xc1, 0x83, 0x17, 0xef, 0xc0,

    /* U+0066 "f" */
    0x7e, 0xfd, 0x8b, 0x6, 0xc, 0x1f, 0x3e, 0x60,
    0xc1, 0x83, 0x6, 0xc, 0x0,

    /* U+0067 "g" */
    0x3c, 0x7e, 0x66, 0x66, 0x64, 0x60, 0x6e, 0x6e,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c,

    /* U+0068 "h" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x7e,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,

    /* U+0069 "i" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,

    /* U+006A "j" */
    0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6, 0xc,
    0x9b, 0x36, 0x6f, 0xcf, 0x0,

    /* U+006B "k" */
    0x67, 0x66, 0x6e, 0x6c, 0x6c, 0x78, 0x78, 0x78,
    0x78, 0x6c, 0x6c, 0x6e, 0x66, 0x67,

    /* U+006C "l" */
    0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60,
    0xc1, 0x83, 0x17, 0xef, 0xc0,

    /* U+006D "m" */
    0x61, 0x98, 0x66, 0x39, 0xce, 0x73, 0x9c, 0xe7,
    0xf9, 0xfe, 0x6d, 0x9b, 0x66, 0xd9, 0x86, 0x61,
    0x98, 0x60,

    /* U+006E "n" */
    0x63, 0x39, 0x9c, 0xce, 0x67, 0xb3, 0xd9, 0xec,
    0xde, 0x6f, 0x33, 0x99, 0xcc, 0xe6, 0x33, 0x18,

    /* U+006F "o" */
    0x3c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c,

    /* U+0070 "p" */
    0x7c, 0xfd, 0x9b, 0x36, 0x6c, 0xd9, 0xbf, 0x7c,
    0xc1, 0x83, 0x6, 0xc, 0x0,

    /* U+0071 "q" */
    0x3c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c, 0x8, 0xc,

    /* U+0072 "r" */
    0x7c, 0x7e, 0x66, 0x66, 0x66, 0x66, 0xfe, 0x7c,
    0x6c, 0x6c, 0x6e, 0x66, 0x66, 0x66,

    /* U+0073 "s" */
    0x7b, 0xfc, 0xf3, 0xc3, 0x87, 0xe, 0xc, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0074 "t" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+0075 "u" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c,

    /* U+0076 "v" */
    0xe3, 0x31, 0x98, 0xcc, 0x66, 0x61, 0x31, 0xd8,
    0xec, 0x36, 0x1a, 0xf, 0x3, 0x81, 0xc1, 0xe0,

    /* U+0077 "w" */
    0xee, 0xec, 0xcd, 0xbb, 0x37, 0x66, 0xec, 0xdd,
    0x9a, 0xb3, 0x56, 0x3b, 0xc7, 0x70, 0xee, 0x1d,
    0xc3, 0xb8, 0x77, 0x0,

    /* U+0078 "x" */
    0xe7, 0x66, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
    0x3c, 0x3c, 0x3c, 0x66, 0x66, 0xe7,

    /* U+0079 "y" */
    0xe7, 0x66, 0x66, 0x24, 0x3c, 0x3c, 0x3c, 0x3c,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+007A "z" */
    0xff, 0xf1, 0xc6, 0x18, 0xe7, 0x9c, 0x71, 0x86,
    0x39, 0xff, 0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 67, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 57, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 87, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 8, .adv_w = 179, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 178, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 44, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 47, .adv_w = 76, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 56, .adv_w = 76, .box_w = 4, .box_h = 17, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 65, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 69, .adv_w = 126, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 76, .adv_w = 60, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 78, .adv_w = 124, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 80, .adv_w = 60, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 145, .box_w = 7, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 78, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 120, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 123, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 136, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 122, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 126, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 121, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 124, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 126, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 64, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 64, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 212, .adv_w = 94, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 219, .adv_w = 127, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 224, .adv_w = 92, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 231, .adv_w = 112, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 140, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 127, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 119, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 135, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 116, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 109, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 130, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 134, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 66, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 110, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 133, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 100, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 166, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 141, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 133, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 120, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 133, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 476, .adv_w = 131, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 112, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 105, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 135, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 139, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 182, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 129, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 123, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 104, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 74, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 610, .adv_w = 145, .box_w = 7, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 74, .box_w = 4, .box_h = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 633, .adv_w = 151, .box_w = 9, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 140, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 127, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 119, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 135, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 116, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 109, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 130, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 134, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 66, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 110, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 133, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 779, .adv_w = 100, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 166, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 810, .adv_w = 141, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 826, .adv_w = 133, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 120, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 853, .adv_w = 133, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 869, .adv_w = 131, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 883, .adv_w = 112, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 894, .adv_w = 105, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 135, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 919, .adv_w = 139, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 182, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 955, .adv_w = 129, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 969, .adv_w = 123, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 983, .adv_w = 104, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 2, 3, 0, 4
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 6, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 6, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 39, .range_length = 25, .glyph_id_start = 6,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 29, .glyph_id_start = 31,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 60,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 61,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1,
    2, 3, 4, 2, 5, 6, 7, 4,
    1, 0, 0, 0, 0, 0, 0, 8,
    9, 10, 11, 12, 13, 14, 15, 15,
    16, 17, 18, 15, 15, 11, 19, 11,
    20, 21, 22, 16, 23, 24, 25, 26,
    27, 0, 0, 0, 0, 8, 9, 10,
    11, 12, 13, 14, 15, 15, 16, 17,
    18, 15, 15, 11, 19, 11, 20, 21,
    22, 16, 23, 24, 25, 26, 27
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 1, 2,
    3, 4, 0, 0, 0, 0, 5, 6,
    7, 8, 9, 10, 11, 6, 12, 13,
    14, 0, 0, 0, 0, 0, 15, 16,
    17, 18, 17, 17, 17, 18, 17, 17,
    19, 17, 17, 17, 17, 18, 17, 18,
    17, 20, 21, 22, 23, 23, 24, 25,
    26, 0, 27, 28, 0, 16, 17, 18,
    17, 17, 17, 18, 17, 17, 19, 17,
    17, 17, 17, 18, 17, 18, 17, 20,
    21, 22, 23, 23, 24, 25, 26
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, -4, -2,
    -2, -2, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -6, -9, -9, -8, -8,
    -9, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -4, 0,
    -3, -5, 0, -3, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, -2, 0, 0, 0, -4,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, -3,
    -3, 0, 0, -4, -2, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -2, -2, 0, -2, -3,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, -2, -7,
    -4, -13, -2, 0, -6, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -20, 0, 0, -12,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, -5, 0, -3,
    -10, -5, -15, 0, -17, 0, -17, 0,
    -8, 0, -10, 0, -13, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    -2, 0, 0, 0, 0, 0, -5, -5,
    -6, 0, -16, -13, -4, 0, -8, 0,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -2, -2, -3, 0, -16, -11,
    -11, 0, -11, -3, -13, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, -5,
    0, 0, 0, 0, 0, 0, -4, -8,
    -9, -2, -16, -14, 0, 0, 0, 0,
    -7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, 0,
    0, 0, 0, 0, -14, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -11,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, -11, 0, -10, 0, -11, -3,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, -7, 0, 0, 0, 0,
    0, 0, -6, -8, -9, -2, -16, -14,
    0, 0, 0, -3, -7, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -13, 0, 0, 0, 0, -2,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -13, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -8, 2,
    0, -9, 0, -4, 0, 0, 0, 1,
    0, 0, -8, 0, -21, 0, 0, -13,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -13, 1, 0, 0, 0, 0,
    -9, 0, -18, 0, -18, 0, -18, 0,
    0, 0, -8, 0, -14, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, 0, -17, 0, 0, 0, 0, -4,
    0, 0, -16, -11, -10, -2, 0, -3,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, 0, -5, 0, -2,
    0, -5, -8, 0, -9, 0, -16, 0,
    -7, 0, -9, 0, -13, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -3,
    0, 0, 0, 0, 0, 0, -4, -4,
    -5, 0, -16, -12, 0, 0, 0, 0,
    -14, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -10, 0, 0, -17, 0,
    0, 0, 0, 0, 0, 0, -8, 0,
    0, 0, 0, 0, -14, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, -15,
    0, -4, -19, -4, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    -14, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -12, 0, 0, -16, -3,
    0, 0, 0, 0, 0, 0, -7, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -7, 0,
    0, -8, 0, -3, 0, 0, 0, 0,
    0, 0, -8, 0, 0, 0, 0, 0,
    -15, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, -18, 0, -9, -21, -4,
    0, 0, 0, 0, 0, 0, -4, 0,
    0, 0, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, -13, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 27,
    .right_class_cnt     = 28,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 5,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT1*/

