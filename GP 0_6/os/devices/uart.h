#ifndef DEVICES_UART_H
#define DEVICES_UART_H

#include "../types.h"

class UART{
	protected:
		void init (uint32_t baud);
		void set_baud (uint32_t baud);
		void send (uint8_t data);
		void send (const char *str);
		uint8_t recv ();
};

#endif
