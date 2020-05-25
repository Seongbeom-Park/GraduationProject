#ifndef HARDWARE_LPC1114_UART_H
#define HARDWARE_LPC1114_UART_H

#include "../../types.h"

#pragma anon_unions

typedef struct {
	union {
		uint32_t	RBR;
		uint32_t	THR;
		uint32_t	DLL;
	};
	union {
		uint32_t	DLM;
		uint32_t	IER;
	};
	union {
		uint32_t	IIR;
		uint32_t	FCR;
	};
	uint32_t	LCR;
	uint32_t	MCR;
	uint32_t	LSR;
	uint32_t	MSR;
	uint32_t	SCR;
	uint32_t	ACR;
	uint32_t	RESERVED0;
	uint32_t	FDR;
	uint32_t	RESERVED1;
	uint32_t	TER;
	uint32_t	RESERVED2[6];
	uint32_t	RS485CTRL;
	uint32_t	RS485ADRMATCH;
	uint32_t	RS485DLY;
	uint8_t		RESERVED3[0x3FA8];
} UART_Typedef;

#pragma no_anon_unions

#endif
