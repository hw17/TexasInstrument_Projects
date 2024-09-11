/*
 * SysConfig.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef SYSCONFIG_H_
#define SYSCONFIG_H_

#define DUTY_CYCLE_25_PERCENT 128U
#define DUTY_CYCLE_50_PERCENT 256U
#define DUTY_CYCLE_75_PERCENT 384U
#define PWM_PERIOD (512U -1U)

void IO_Config(void);
void TIMER_Config(void);
void SPI_Config(void);
void SPI_Write(unsigned char data);
void UART_Config(void);
void UART_TX(unsigned char data);

#endif /* SYSCONFIG_H_ */
