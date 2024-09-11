/*
 * glcd_controllers.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef GLCD_CONTROLLERS_H_
#define GLCD_CONTROLLERS_H_

/**
 * Send command byte to LCD.
 * \param c Command byte to be written to LCD
 */
void glcd_command(uint8_t c);

/**
 *  Send data byte to LCD.
 *  \param c Data byte to be written to LCD
 */
void glcd_data(uint8_t c);

/**
 * Set contrast.
 * \param val Value from 0 to 127.  This should be experimentally determined. Supported by PCD8544 only.
 */
void glcd_set_contrast(uint8_t val);

/**
 * Power down the device.
 */
void glcd_power_down(void);

/**
 * Power up the device.
 */
void glcd_power_up(void);

/**
 * Set Y address of RAM (select bank).
 * \param y page address of RAM (0 <= Y < GLCD_LCD_HEIGHT/8)
 * \see   GLCD_LCD_HEIGHT
 * \see   GLCD_NUMBER_OF_BANKS
 *
 * \note Update: \p y is actually bank number, not pixel number!
 */
void glcd_set_y_address(uint8_t y);

/**
 * Set X address of RAM (column). Device must be under basic instruction set mode before using this.
 * \param x X address of RAM (0 <= X <= GLCD_LCD_WIDTH-1)
 * \see   GLCD_LCD_WIDTH
 */
void glcd_set_x_address(uint8_t x);

/**
 * Update the display within the specified bounding box. This physically writes data to the device's RAM.
 */
void glcd_write(void);

/** @}*/

#endif /* GLCD_CONTROLLERS_H_ */
