#include "device.h"

DeviceManager::DeviceManager (){
	init ();
}

void DeviceManager::init (){
	int i;
	for (i = 0; i<256; i++) holder_pid[i] = 0;
}

void DeviceManager::pinMode (Process* handler, uint32_t pin, MODE mode){
	acquire (handler, DeviceManager::GPIO + pin);
	GPIO::pinMode (pin, mode);
}

void DeviceManager::digitalWrite (Process* handler, uint32_t pin, VALUE value){
	acquire (handler, DeviceManager::GPIO + pin);
	GPIO::digitalWrite (pin, value);
}

DeviceManager::VALUE DeviceManager::digitalRead (Process* handler, uint32_t pin){
	acquire (handler, DeviceManager::GPIO + pin);
	return GPIO::digitalRead (pin);
}

void DeviceManager::acquire (Process* handler, uint32_t device_number){
	uint8_t pid = handler->get_pid ();
	if (holder_pid[device_number] != pid)
		while (holder_pid[device_number] != 0);
	holder_pid[device_number] = pid;
}

void DeviceManager::release (Process* handler, uint32_t device_number){
	uint8_t pid = handler->get_pid ();
	if (holder_pid[device_number] == pid) holder_pid[device_number] = 0;
}
