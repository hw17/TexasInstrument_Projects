/*
 * ST7565R_driver.c
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */
#include <string.h>

#include "../../Include/SysConfig.h"
#include "../../Include/NewhavenLCD/ST7565R_driver.h"
#include "../../Include/NewhavenLCD/glcd.h"

void glcd_spi_write(uint8_t data){
	GLCD_CS1_SELECT;
	SPI_Write(data);
	GLCD_CS1_UNSELECT;
}

void glcd_command(uint8_t c)
{
    GLCD_A0_LOW;
	glcd_spi_write(c);
}

void glcd_data(uint8_t c)
{
    GLCD_A0_HIGH;
	glcd_spi_write(c);
}

void glcd_set_contrast(uint8_t val) {
	/* Can set a 6-bit value (0 to 63)  */

	/* Must send this command byte before setting the contrast */
	glcd_command(0x81);

	/* Set the contrast value ("electronic volume register") */
	if (val > 63) {
		glcd_command(63);
	} else {
		glcd_command(val);
	}
	return;
}

void glcd_power_down(void)
{
	/* Command sequence as in ST7565 datasheet */
	glcd_command(0xac);	// Static indicator off
	glcd_command(0x00);	// Static indicator register, not blinking
	glcd_command(0xae); // Display OFF
	glcd_command(0xa5); // Display all points ON

	/* Display is now in sleep mode */
}

void glcd_power_up(void)
{
	glcd_command(0xa4); // Display all points OFF
	glcd_command(0xad);	// Static indicator ON
	glcd_command(0x00);	// Static indicator register, not Blinking
	glcd_command(0xaf);

	return;
}

void glcd_set_y_address(uint8_t y)
{
	glcd_command(ST7565R_PAGE_ADDRESS_SET | (0x0F & y)); /* 0x0F = 0b00001111 */
}

void glcd_set_x_address(uint8_t x)
{
	glcd_set_column_upper(x);
	glcd_set_column_lower(x);
}

void glcd_all_on(void)
{
	glcd_command(ST7565R_DISPLAY_ALL_ON);
}

void glcd_normal(void)
{
	glcd_command(ST7565R_DISPLAY_NORMAL);
}

void glcd_set_column_upper(uint8_t addr)
{
	glcd_command(ST7565R_COLUMN_ADDRESS_SET_UPPER | (addr >> 4));
}

void glcd_set_column_lower(uint8_t addr)
{
	glcd_command(ST7565R_COLUMN_ADDRESS_SET_LOWER | (0x0f & addr));
}

void glcd_set_start_line(uint8_t addr)
{
	glcd_command( ST7565R_SET_START_LINE | (0x3F & addr)); /* 0x3F == 0b00111111 */
}

/** Clear the display immediately, does not buffer */
void glcd_clear_now(void)
{
	uint8_t page;
	for (page = 0; page < GLCD_NUMBER_OF_BANKS; page++) {
		uint8_t col;
		glcd_set_y_address(page);
		glcd_set_x_address(0);
		for (col = 0; col < GLCD_NUMBER_OF_COLS; col++) {
			glcd_data(0);
		}
	}
}

void glcd_pattern(void)
{
	uint8_t page;
	for (page = 0; page < GLCD_NUMBER_OF_BANKS; page++) {
		uint8_t col;
		glcd_set_y_address(page);
		glcd_set_x_address(0);
		for (col = 0; col < GLCD_NUMBER_OF_COLS; col++) {
			glcd_data( (col / 8 + 2) % 2 == 1 ? 0xff : 0x00 );
		}
	}
}

void glcd_write()
{
	uint8_t bank;

	for (bank = 0; bank < GLCD_NUMBER_OF_BANKS; bank++) {
		/* Each bank is a single row 8 bits tall */
		uint8_t column;

		if (glcd_bbox_selected->y_min >= (bank+1)*8) {
			continue; /* Skip the entire bank */
		}

		if (glcd_bbox_selected->y_max < bank*8) {
			break;    /* No more banks need updating */
		}

		glcd_set_y_address(bank);
		glcd_set_x_address(glcd_bbox_selected->x_min);

		for (column = glcd_bbox_selected->x_min; column <= glcd_bbox_selected->x_max; column++)
		{
			glcd_data( glcd_buffer_selected[GLCD_NUMBER_OF_COLS * bank + column] );
		}
	}

	glcd_reset_bbox();

}

void glcd_ST7565R_init(void) {

	/* Init sequence based on datasheet example code for NHD-C12864A1Z-FSW-FBW-HTT */
	/* Datasheet says max SCK frequency 2.5MHz for this LCD */
	/* We use "reverse direction" for common output mode, as opposed to datasheet specifying "normal direction" */

	glcd_command(0xa0); /* ADC select in normal mode */
	glcd_command(0xae); /* Display OFF */
	glcd_command(0xc8); /* Common output mode select: reverse direction (last 3 bits are ignored) */
	glcd_command(0xa2); /* LCD bias set at 1/9 */
	glcd_command(0x2f); /* Power control set to operating mode: 7 */
	glcd_command(0x26); /* Internal resistor ratio, set to: 6 */
	glcd_set_contrast(20); /* Set contrast, value experimentally determined */
	glcd_command(0xaf); /* Display on */
}

void glcd_reset(void){
    GLCD_CS1_SELECT;
    GLCD_RESET_LOW;
    DelayMs(GLCD_RESET_TIME);
    GLCD_RESET_HIGH;
   // Wait until the byte is sent before deselecting
    SPI_Write(0x00);	//dummy
    GLCD_CS1_UNSELECT;
}

void glcd_init(void){
    GLCD_CS1_UNSELECT;

    // Send the reset pulse to LCD
    glcd_reset();
    DelayMs(1);

    // Begin sending data for initialization sequence
    glcd_ST7565R_init();

    // Set all dots black and hold for 0.5s, then clear it,
    // we do this so we can visually check init sequence is working
    glcd_all_on();
    DelayMs(500);
    glcd_normal();

    glcd_set_start_line(0);
    glcd_clear_now();
    glcd_select_screen(glcd_buffer, &glcd_bbox);

    glcd_clear();
}

void DelayMs(unsigned int n){
    volatile unsigned int i;

    for(i=65530;i>0;i--);

    n--;
}
