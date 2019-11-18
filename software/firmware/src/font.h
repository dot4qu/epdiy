// Font structures adapted from Adafruit_GFX (1.1 and later).

#ifndef _FONT_H_
#define _FONT_H_

#include "Arduino.h"
#include "EPD.hpp"

/// Font data stored PER GLYPH
typedef struct {
    uint8_t  width;            ///< Bitmap dimensions in pixels
    uint8_t  height;           ///< Bitmap dimensions in pixels
    uint8_t  advance_x;        ///< Distance to advance cursor (x axis)
    int16_t   left;             ///< X dist from cursor pos to UL corner
    int16_t   top;              ///< Y dist from cursor pos to UL corner
    uint16_t compressed_size;  ///< Size of the zlib-compressed font data.
    uint32_t data_offset;      ///< Pointer into GFXfont->bitmap
} GFXglyph;

/// Data stored for FONT AS A WHOLE
typedef struct {
    uint8_t  *bitmap;      ///< Glyph bitmaps, concatenated
    GFXglyph *glyph;       ///< Glyph array
    uint8_t   first;       ///< ASCII extents (first char)
    uint8_t   last;        ///< ASCII extents (last char)
    uint8_t   advance_y;   ///< Newline distance (y axis)
} GFXfont;



/*!
 * Get the text bounds for string, when drawn at (x, y).
 */
void getTextBounds(GFXfont* font, unsigned char* string, int x, int y, int* x1, int* y1, int* w, int* h);


/*!
 * Write a line of text to the EPD.
 */
void writeln(GFXfont* font, unsigned char* string, int* cursor_x, int* cursor_y, EPD* epd);

#endif // _FONT_H_
