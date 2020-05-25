#ifndef SYSTEM_DEVICE_H
#define SYSTEM_DEVICE_H

#include "../types.h"

#include "gpio.h"
#include "uart.h"
#include "../process/process.h"

class DeviceManager: public GPIO, public UART {
	private:
		uint8_t holder_pid[256];
	protected:
		void init ();
	public:
		enum DEVICE_ID {
			UART0 = 0x00,
			GPIO = 0x40 //upto 64 pins
		};
		DeviceManager ();
	
		void pinMode (Process* handler, uint32_t pin, MODE mode);
		void digitalWrite (Process* handler, uint32_t pin, VALUE value);
		VALUE digitalRead (Process* handler, uint32_t pin);
		
		void acquire (Process* handler, uint32_t device_number);
		void release (Process* handler, uint32_t device_number);
};

#endif
