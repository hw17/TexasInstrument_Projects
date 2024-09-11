/*
 * Spi.c
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */
#include <msp430.h>

#include "../Include/SysConfig.h"

void SPI_Config(void){
    UCB0CTL1 = UCSWRST;
    UCB0CTL0 |= UCMST | UCSYNC | UCMODE_0 | UCMSB | UCCKPH;
    UCB0CTL1 |= UCSSEL_2;	// data rate:
    UCB0BR0 |= 0x02;		// division factor of clock source
    UCB0BR1 = 0x00;
    UCB0CTL1 &= ~UCSWRST;	// enable module or module initialization
}

void SPI_Write(unsigned char data){
    UCB0TXBUF = data;
    while(UCB0STAT & UCBUSY);
}
