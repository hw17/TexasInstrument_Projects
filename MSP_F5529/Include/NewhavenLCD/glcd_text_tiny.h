/*
 * glcd_text_tiny.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef GLCD_TEXT_TINY_H_
#define GLCD_TEXT_TINY_H_

/** \addtogroup TinyText Tiny Text
 *  Functions relating to using tiny 5x7 text fonts.
 *
 * Tiny text functions are usually used on a line by line basis. Each line being 8 bits high.
 * Characters start on the top most bit and are 7 bits high, leaving a one bit space underneath.
 *
 *  @{
 */

/** Set font to be used from now on. This is the tiny 5x7 monospace font.
 *  \param font_table flash pointer to start from font table
 *  \param width      width of each character
 *  \param height     height of each character
 *  \param start_char start character
 *  \param end_char   end character
 *  \note Only suitable for Stang font storage format. For MikroElektronika format, use
 *        glcd_set_font()
 *  \see glcd_set_font()
 */
void glcd_tiny_set_font(const char *font_table, uint8_t width, uint8_t height, char start_char, char end_char);

/** Write character to LCD in tiny 5x7 font.
 *  \param x    column position to start
 *  \param line line number to be written (each line is 8 pixels high)
 *  \param c    char to be written
 */
void glcd_tiny_draw_char(uint8_t x, uint8_t line, char c);

/** Write string to display buffer in tiny 5x7 font.
 *  Will wrap to next line if needed. Screen is not updated. Use glcd_write() to physically update display.
 *  \param x    column position to start
 *  \param line line number to be written (each line is 8 pixels high)
 *  \param str  string to be written
 */
void glcd_tiny_draw_string(uint8_t x, uint8_t line, char *str);

/** Write flash string to display buffer in tiny 5x7 font.
 *  Will wrap to next line if needed. Screen is not updated. Use glcd_write() to physically update display.
 *  \param x    column position to start
 *  \param line line to be written (each line is 8 pixels high)
 *  \param str  string stored in flash memory to be written
 */
void glcd_tiny_draw_string_P(uint8_t x, uint8_t line, const char *str);

/** Write string to bottom row of display.
 *  Screen buffer is scrolled up by one line. Screen is then physically updated.
 *  \param str string to be written
 */
void glcd_tiny_draw_string_ammend(char *str);

/** Write string from flash memory to bottom row of display.
 *  Screen buffer is scrolled up by one line. Screen is then physically updated.
 *  \param str string to be written
 */
void glcd_tiny_draw_string_ammend_P(const char *str);


/**
 * Invert all contents of line number. Line 0 is the top most line.
 * \param line Line number (0 is top most line)
 */
void glcd_tiny_invert_line(uint8_t line);

/** Write character to LCD in tiny 5x7 font to specified X, Y location.
 *  If position is aligned with 8 bit line heights, use glcd_tiny_draw_char() instead
 *  as it will be faster.
 *
 *  \param x    column position to start
 *  \param y    row position to start (pixel based, not 8 bit high rows)
 *  \param c    char to be written
 *  \see  glcd_tiny_draw_char()
 *  \note This does the same thing as glcd_tiny_draw_char_xy() but is limited to Stang format
 *        font tables.
 */
void glcd_tiny_draw_char_xy(uint8_t x, uint8_t y, char c);

/** Initialise 5x7 text */
#define GLCD_TEXT_INIT()  glcd_tiny_set_font(Font5x7,5,7,32,127);

/** Write string to bottom-most line after scrolling everything else up */
#define GLCD_WRITE(str)   glcd_tiny_draw_string_ammend(str)

/** Write string from program memory to bottom-most line after scrolling everything else up */
#define GLCD_WRITE_P(str) glcd_tiny_draw_string_ammend_P(str)

/** @}*/



#endif /* GLCD_TEXT_TINY_H_ */
