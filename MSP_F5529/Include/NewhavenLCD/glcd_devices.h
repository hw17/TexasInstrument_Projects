/*
 * glcd_devices.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef GLCD_DEVICES_H_
#define GLCD_DEVICES_H_

/**
 * Initialise the LCD. This function is platform and controller specific.
 */
void glcd_init(void);

/**
 * Write a byte to the connected SPI slave.
 * \param c Byte to be written
 * \return Returned value from SPI (often not used)
 */
void glcd_spi_write(uint8_t c);

/**
 *  Reset the LCD.
 *  \note Not all LCD controllers support reset.
 */
void glcd_reset(void);

/** @}*/


#endif /* GLCD_DEVICES_H_ */
