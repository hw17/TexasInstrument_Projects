/*
 * Gpio.c
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */
#include "../Include/GeneralVariables.h"
#include "../Include/SysConfig.h"

void IO_Config(void){

    //Timer
    P1DIR |= BIT2|BIT3; // P1.2 and P1.3 output
    P1SEL |= BIT2|BIT3; // P1.2 and P1.3 options select

    //UART
    P4SEL |= U_TX|U_RX; // P4.4, P4.5 = USCI_A1 TXD/RXD 0011 0000

    /*SPI
      MISO -> P3.1 - UCB0SOMI Slave out, master in USCI_B0 SPI mode
      MOSI -> P3.0 - UCB0SIMO Slave in, master out USCI_B0 SPI mode
      SCLK -> P3.2 - UCB0CLK  Clock signal output USCI_B0 SPI master mode
      CS_N -> P2.5 */
    P3SEL |= MOSI|MISO|SCLK;// Configures SPI
    P3DIR |= MOSI|SCLK;     // Set P3.0 P3.2 as outputs

    P3OUT |= MISO;      // Set P3.1 High
    P3DIR &= ~MISO;     // Set P3.1 as input

    //DISPLAY CTRL
    P1DIR |= A0;        // P1.5 as output for A0
    P2DIR |= RESET|CS;  // P2.4(/RESET) and P2.5(/CS) as output

    P2OUT &= ~CS;       // Set P2.5 Low
    P2OUT &= ~RESET;    // Set P2.4 Low
    P1OUT &= ~A0;       // Set P1.5 Low
}

