#ifndef HARDWARE_LPC1114_APB_H
#define HARDWARE_LPC1114_APB_H

#include "i2c.h"
#include "wdt.h"
#include "uart.h"
#include "ct16.h"
#include "ct32.h"
#include "adc.h"
#include "pmu.h"
#include "flash.h"
#include "spi.h"
#include "iocon.h"
#include "syscon.h"

typedef struct {
	I2C_Typedef			i2c;
	WDT_Typedef			wdt;
	UART_Typedef		uart;
	CT16_Typedef		ct16_0;
	CT16_Typedef		ct16_1;
	CT32_Typedef		ct32_0;
	CT32_Typedef		ct32_1;
	ADC_Typedef			adc;
	uint8_t					RESERVED0[0x4000];
	uint8_t					RESERVED1[0x4000];
	uint8_t					RESERVED2[0x4000][4];
	PMU_Typedef			pmu;
	FLASH_Typedef		flash;
	SPI_Typedef			spi_0;
	IOCON_Typedef		iocon;
	SYSCON_Typedef	syscon;
	uint8_t					RESERVED3[0x4000][3];
	SPI_Typedef			spi_1;
	uint8_t					RESERVED4[0x4000][9];
} APB_Typedef;

#endif
