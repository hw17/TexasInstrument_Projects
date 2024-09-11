/*
 * glcd_text.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef GLCD_TEXT_H_
#define GLCD_TEXT_H_

/** \addtogroup Text
 *  Functions relating to using text fonts.
 *  @{
 */

/** \addtogroup StandardText Standard Text
 *  Functions relating to using text fonts of all sizes.
 *  @{
 */

/** Set GLCD font to predefined font table. Only suitable for MikroElektronika font storage format.
 *
 *  \param font_table pointer to font table to be used
 *  \param width width of each character
 *  \param height height of each character
 *  \param start_char first character of font table
 *  \param end_char last character of font table
 *  \note Only suitable for MikroElektronika font storage format. For Stang format, use
 *        glcd_tiny_set_font()
 *  \see glcd_tiny_set_font()
 */

void glcd_set_font(const char * font_table, uint8_t width, uint8_t height, char start_char, char end_char);

/** Set GLCD font to predefined font table. Suitable for different different types of font tables.
 *
 *  \param font_table pointer to font table to be used
 *  \param width width of each character
 *  \param height height of each character
 *  \param start_char first character of font table
 *  \param end_char last character of font table
 *  \param type font table type
 *  \note Only suitable for MikroElektronika font storage format. For Stang format, use
 *        glcd_tiny_set_font()
 *  \see glcd_tiny_set_font()
 */

void glcd_font(const char * font_table, uint8_t width, uint8_t height, char start_char, char end_char, font_table_type_t type);


/** Draw a char at specified location.
 *  \param x x location to place top-left of character frame
 *  \param y y location to place top-left of character frame
 *  \param c character to be drawn
 *  \return width of character, 0 on error (e.g could not read font table)
 */
uint8_t glcd_draw_char_xy(uint8_t x, uint8_t y, char c);

/** Draw a string at specified location.
 *  \param x x location to place top-left of character frame
 *  \param y y location to place top-left of character frame
 *  \param c pointer to string to be drawn
 */
void glcd_draw_string_xy(uint8_t x, uint8_t y, char *c);

/** Draw a string from program memory at specified location.
 *  \param x x location to place top-left of character frame
 *  \param y y location to place top-left of character frame
 *  \param str pointer to string in program memory to be drawn
 */
void glcd_draw_string_xy_P(uint8_t x, uint8_t y, const char *str);

/** @}*/

/** @}*/


#endif /* GLCD_TEXT_H_ */
