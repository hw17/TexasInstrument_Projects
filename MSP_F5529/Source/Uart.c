/*
 * Uart.c
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */
#include <msp430.h>

#include "../Include/SysConfig.h"

void UART_Config(void){

    UCA1CTL1 |= UCSWRST;    // Colocar la maquina de estados en reset
    UCA1CTL1 |= UCSSEL_1;   // 32768 Hz
    UCA1BR0 = 3;            // baudrate 9600
    UCA1BR1 = 0x00;         // 32768 Hz
    UCA1MCTL = 0x06;        // Modulation UCBRSx=3, UCBRFx=0
    UCA1CTL0 = 0x00;        // not used
    UCA1CTL1 &= ~UCSWRST;   // colocar USCI en modo de operacion

    UCA1IE |= UCRXIE;       // Enable USCI_A0 RX interrupt
    __bis_SR_register(GIE);	// Enter LPM0, interrupts enabled
}

void UART_TX(unsigned char data){
    UCA1TXBUF = data;
    while(UCA1STAT&UCBUSY);
}
