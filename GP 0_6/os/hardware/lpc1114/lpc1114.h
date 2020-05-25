#ifndef HARDWARE_LPC1114_LPC1114_H
#define HARDWARE_LPC1114_LPC1114_H

#ifndef CORTEX_M0
#define CORTEX_M0
#endif

#include "apb.h"
#include "ahb.h"
#include "ppb.h"

typedef struct{
	uint8_t			FLASH			[0x8000];
	uint8_t			RESERVED0	[0xFFF8000];
	uint8_t			SRAM			[0x2000];
	uint8_t			RESERVED1	[0xFFEE000];
	uint8_t			ROM				[0x4000];
	uint8_t			RESERVED2	[0xC000];
	uint8_t			RESERVED3	[0x20000000];
	APB_Typedef	APB;
	uint8_t			RESERVED4	[0xFF80000];
	AHB_Typedef	AHB;
	uint8_t			RESERVED5	[0x8FE00000];
	PPB_Typedef	PPB;
	//uint8_t		RESERVED6	[0x1FF00000];
} LPC1114;

#define lpc1114 (*(LPC1114*) 0)

#endif
