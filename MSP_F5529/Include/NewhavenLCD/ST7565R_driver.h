/*
 * ST7565R_driver.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef ST7565R_DRIVER_H_
#define ST7565R_DRIVER_H_

/* STANDARD HEADER FILES*/
#include <stdint.h>

/* USER HEADER FILES */
#include "../GeneralVariables.h"

/* Macros */
#define GLCD_A0_LOW  P1OUT &= ~A0		/* Send low state in PORT_1*/
#define GLCD_A0_HIGH P1OUT |= A0		/* Send high state in PORT_1*/

#define GLCD_RESET_LOW  P2OUT &= ~RESET /* Send low state in PORT_2*/
#define GLCD_RESET_HIGH P2OUT |= RESET  /* Send high state in PORT_2*/

#define GLCD_CS1_SELECT   P2OUT &= ~CS  /* Send low state in PORT_2*/
#define GLCD_CS1_UNSELECT P2OUT |= CS   /* Send high state in PORT_2*/

#define GLCD_SDI_LOW  P3OUT &= ~MOSI    /*Send low state in PORT_3*/
#define GLCD_SDI_HIGH P3OUT |= MOSI     /*Send high state in PORT_3*/

#define GLCD_SCKL_LOW  P3OUT &= ~SCLK   /*Send low state in PORT_3*/
#define GLCD_SCKL_HIGH P3OUT |= SCLK    /*Send high state in PORT_3*/

/* Commands */
#define ST7565R_DISPLAY_ON               0xAF /* 0b10101111 */
#define ST7565R_DISPLAY_OFF              0xAE /* 0b10101110 */
#define ST7565R_PAGE_ADDRESS_SET         0xB0 /* 0b10110000 */
#define ST7565R_COLUMN_ADDRESS_SET_LOWER 0x00
#define ST7565R_COLUMN_ADDRESS_SET_UPPER 0x10
#define ST7565R_DISPLAY_NORMAL           0xA4 /* 0b10100100 */
#define ST7565R_DISPLAY_ALL_ON           0xA5 /* 0b10100101 */
#define ST7565R_NORMAL                   0xA0 /* 0b10100000 */
#define ST7565R_REVERSE                  0xA1 /* 0b10100001 */
#define ST7565R_RESET                    0xE2 /* 0b11100010 */
#define ST7565R_SET_START_LINE           (1<<6)

/* These functions only available on ST7565 implementation (for now) */

/* Private functions */
void glcd_set_column_upper(uint8_t addr);
void glcd_set_column_lower(uint8_t addr);

/** All display points on (native) */
void glcd_all_on(void);

/** Set to normal mode */
void glcd_normal(void);

/** Set start line/page */
void glcd_set_start_line(uint8_t addr);

/** Clear the display immediately, does not buffer */
void glcd_clear_now(void);

/** Show a black and white line pattern on the display */
void glcd_pattern(void);

/** Init ST7565R controller / display */
void glcd_ST7565R_init(void);

/** Delay function **/
void DelayMs(unsigned int n);

#endif /* ST7565R_DRIVER_H_ */
