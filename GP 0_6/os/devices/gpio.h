#ifndef DEVICES_GPIO_H
#define DEVICES_GPIO_H

#include "../types.h"

class GPIO{
	public:
		enum MODE {INPUT, OUTPUT};
		enum VALUE {LOW, HIGH};
	protected:
		void pinMode (uint32_t pin, MODE mode);
		void digitalWrite (uint32_t pin, VALUE value);
		VALUE digitalRead (uint32_t pin);
};

#endif
