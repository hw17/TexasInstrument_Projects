/*
 * main.c
 */

/*LIBRARIES*/
#include <msp430.h>

/*USER LIBRARIES*/
#include "Include/SysConfig.h"
#include "Include/NewhavenLCD/glcd.h"
#include "Include/NewhavenLCD/fonts/font5x7.h"
/*FUNCTION PROTOTYPES*/

/*GLOBAL VARIABLES*/
unsigned char datoRX = 0;
unsigned int TL1 = 0;
unsigned int TL2 = 0;
unsigned char counter = 1;



int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	IO_Config();
	TIMER_Config();
	UART_Config();
	SPI_Config();

	glcd_init();

	glcd_tiny_set_font(Font5x7,5,7,32,127);
	while(1){
	    //glcd_test_tiny_text();
	    //glcd_test_text_up_down();
	    //glcd_test_counter_and_graph();
	    //glcd_test_circles();
	    //glcd_test_scrolling_graph();
	    //glcd_test_glcdutils();
	    //glcd_test_rectangles();

	    glcd_clear_buffer();
	    glcd_bar_graph_vertical(0,0,10,53,(counter*3.5)+8);
	    glcd_write();

	    glcd_clear_buffer();
	    glcd_tiny_draw_string(11,0,"ROTATION_TEST CODE");
	    glcd_write();
	}
	return 0;
}

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    while (!(UCA1IFG & UCTXIFG));   // USCI_A0 TX buffer ready?
    UCA1TXBUF = UCA1RXBUF;          // TX -> RXed character (-32)
    datoRX = UCA1RXBUF;
    if(datoRX == 'a'){
        if(TL1 <= 83){ //max value
            TA0CCR1++;
            TA0CCR2++;
            counter--;
        }
        else{
            TA0CCR1 = 84;
            TA0CCR2 = 84;
        }
    }
    else{
        if(TL1 >= 15){ //min value
            TA0CCR1--;
            TA0CCR2--;
            counter++;
        }
        else{
            TA0CCR1 = 14;
            TA0CCR2 = 14;
        }
    }
    TL1 = TA0CCR1;
    TL2 = TA0CCR2;
}
