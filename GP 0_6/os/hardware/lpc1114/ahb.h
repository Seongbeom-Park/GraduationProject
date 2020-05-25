#ifndef HARDWARE_LPC1114_AHB_H
#define HARDWARE_LPC1114_AHB_H

#include "../../types.h"
#include "gpio.h"

typedef struct {
	GPIO_Typedef GPIO	[4];
	uint8_t RESERVED	[0x1C0000];
} AHB_Typedef;

#endif
