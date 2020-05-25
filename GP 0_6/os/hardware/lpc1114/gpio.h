#ifndef HARDWARE_LPC1114_GPIO_H
#define HARDWARE_LPC1114_GPIO_H

#include "../../types.h"

typedef struct {
	uint32_t DATA				[0x1000];
	uint32_t RESERVED0	[0x1000];
	uint32_t DIR;
	uint32_t IS;
	uint32_t IBE;
	uint32_t IEV;
	uint32_t IE;
	uint32_t RIS;
	uint32_t MIS;
	uint32_t IC;
	uint32_t RESERVED1	[0x1ff8];
} GPIO_Typedef;

#endif
