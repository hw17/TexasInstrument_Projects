/*
 * Timer.c
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#include <msp430.h>

#include "../Include/SysConfig.h"

/*                MSP430F552x
              -------------------
          /|\|                   |
           | |                   |
           --|RST                |
             |                   |
             |         P1.2/TA0.1|--> CCR1 - 75% PWM
             |         P1.3/TA0.2|--> CCR2 - 25% PWM
*/

void TIMER_Config(void){
    TA0CCR0 = PWM_PERIOD;               // PWM Period
    TA0CCTL1 = OUTMOD_7;                // CCR1 reset/set
    TA0CCR1 = DUTY_CYCLE_50_PERCENT;    // CCR1 PWM duty cycle 128=25%
    TA0CCTL2 = OUTMOD_7;                // CCR2 reset/set
    TA0CCR2 = DUTY_CYCLE_50_PERCENT;    // CCR2 PWM duty cycle
    TA0CTL = TASSEL_1 + MC_1 + TACLR;   // ACLK, up mode, clear TAR
}

