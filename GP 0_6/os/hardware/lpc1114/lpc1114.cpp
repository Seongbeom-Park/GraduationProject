#include "../../system/system.h"

void* System::operator new (uint32_t size){
	return (void*)(RAM_BASE);
}

void System::boot (){
	System* system = new System ();
	
	system->run ();
	system->shutdown ();
}

#define IAP_LOCATION (0x1fff1ff1)
typedef void(*IAP)(uint32_t[], uint32_t[]);

void prepare (uint32_t start, uint32_t end){
	uint32_t command_param[5];
	uint32_t status_result[4];
	
	IAP iap_entry = (IAP)IAP_LOCATION;
	command_param[0] = 50;
	command_param[1] = start;
	command_param[2] = end;
	iap_entry (command_param, status_result);
}

void copy (void* dest, void* src, uint32_t number_of_bytes){
	uint32_t command_param[5];
	uint32_t status_result[4];
	
	IAP iap_entry = (IAP)IAP_LOCATION;
	
	command_param[0] = 51;
	command_param[1] = (uint32_t)dest;
	command_param[2] = (uint32_t)src;
	command_param[3] = number_of_bytes;
	command_param[4] = 50000;
	
	iap_entry (command_param, status_result);
}

void erase (uint32_t start, uint32_t end){
	uint32_t command_param[5];
	uint32_t status_result[4];
	
	IAP iap_entry = (IAP)IAP_LOCATION;
	command_param[0] = 52;
	command_param[1] = start;
	command_param[2] = end;
	command_param[3] = 50000;
	iap_entry (command_param, status_result);
}

void FileManager::init (){
	// erase usr lib(0x2000-0x2fff) and usr prog(0x3000-0x3fff)
	prepare (2, 3);
	erase (2, 3);
	
	sector = 0;
	temp = *(Sector*)(0x4000);
}

void FileManager::format (){
	int i;
	prepare (4, 7);
	erase (4, 7);
	
	temp.name[0] = '\0';
	temp.remain = 64-1;
	temp.first_clear = 1;
	for (i = 0; i<44; i++) temp.inside[i] = 0;
	
	write (0);
	
	for (i = 1; i<64; i++){
		read (i);
		temp.number_of_cont = 63-i;
		temp.prev_clear = i-1;
		temp.next_clear = i+1;
		
		write (i);
	}
}

void FileManager::write (uint32_t sector){
	uint32_t pos = 0x4000+(sector<<8);
	prepare (pos>>12, pos>>12);
	copy ((void*)(pos), (void*)&temp, 256);
}

void FileManager::read (uint32_t sector){
	write (this->sector);
	this->sector = sector;
	temp =  *(Sector*)(0x4000+(sector<<8));
}

uint32_t FileManager::get_clear (uint32_t size){
	read (0);
	while (temp.number_of_cont != 0)
		if (temp.number_of_cont > size) return sector;
		else read (temp.next_clear);
	return 0;
}

void FileManager::write_on_clear (uint32_t sector){
	if (sector == 0) return;
}

#include "lpc1114.h"
#include "../../devices/gpio.h"

void GPIO::pinMode (uint32_t pin, MODE mode){
	lpc1114.APB.syscon.SYSAHBCLKCTRL |= (1<<16);	// enable iocon
	switch (pin){
		case 0:
			if (mode) lpc1114.AHB.GPIO[0].DIR |= (1<<8);
			else lpc1114.AHB.GPIO[0].DIR &= ~(1<<8);
			break;
		case 1:
			if (mode) lpc1114.AHB.GPIO[0].DIR |= (1<<9);
			else lpc1114.AHB.GPIO[0].DIR &= ~(1<<9);
			break;
		case 2:
			if (mode) lpc1114.AHB.GPIO[1].DIR |= (1<<10);
			else lpc1114.AHB.GPIO[1].DIR &= ~(1<<10);
			break;
		case 3:
			if (mode) lpc1114.AHB.GPIO[1].DIR |= (1<<11);
			else lpc1114.AHB.GPIO[1].DIR &= ~(1<<11);
			break;
		case 4:
			if (mode) lpc1114.AHB.GPIO[3].DIR |= (1<<2);
			else lpc1114.AHB.GPIO[3].DIR &= ~(1<<2);
			break;
		case 5:
			if (mode) lpc1114.AHB.GPIO[3].DIR |= (1<<1);
			else lpc1114.AHB.GPIO[3].DIR &= ~(1<<1);
			break;
		case 6:
			if (mode) lpc1114.AHB.GPIO[3].DIR |= (1<<0);
			else lpc1114.AHB.GPIO[3].DIR &= ~(1<<0);
			break;
	}
	lpc1114.APB.syscon.SYSAHBCLKCTRL &= ~(1<<16); // disable iocon
}

void GPIO::digitalWrite (uint32_t pin, VALUE value){
	switch (pin){
		case 0:
			if (value) lpc1114.AHB.GPIO[0].DATA[1<<8] = 1<<8;
			else lpc1114.AHB.GPIO[0].DATA[1<<8] = 0;
			break;
		case 1:
			if (value) lpc1114.AHB.GPIO[0].DATA[1<<9] = 1<<9;
			else lpc1114.AHB.GPIO[0].DATA[1<<9] = 0;
			break;
		case 2:
			if (value) lpc1114.AHB.GPIO[1].DATA[1<<10] = 1<<10;
			else lpc1114.AHB.GPIO[1].DATA[1<<10] = 0;
			break;
		case 3:
			if (value) lpc1114.AHB.GPIO[1].DATA[1<<11] = 1<<11;
			else lpc1114.AHB.GPIO[1].DATA[1<<11] = 0;
			break;
		case 4:
			if (value) lpc1114.AHB.GPIO[3].DATA[1<<2] = 1<<2;
			else lpc1114.AHB.GPIO[3].DATA[1<<2] = 0;
			break;
		case 5:
			if (value) lpc1114.AHB.GPIO[3].DATA[1<<1] = 1<<1;
			else lpc1114.AHB.GPIO[3].DATA[1<<1] = 0;
			break;
		case 6:
			if (value) lpc1114.AHB.GPIO[3].DATA[1<<0] = 1<<0;
			else lpc1114.AHB.GPIO[3].DATA[1<<0] = 0;
			break;
	}
}

GPIO::VALUE GPIO::digitalRead (uint32_t pin){
	switch (pin){
		case 0:
			return lpc1114.AHB.GPIO[0].DATA[1<<8]?HIGH:LOW;
		case 1:
			return lpc1114.AHB.GPIO[0].DATA[1<<9]?HIGH:LOW;
		case 2:
			return lpc1114.AHB.GPIO[1].DATA[1<<10]?HIGH:LOW;
		case 3:
			return lpc1114.AHB.GPIO[1].DATA[1<<11]?HIGH:LOW;
		case 4:
			return lpc1114.AHB.GPIO[3].DATA[1<<2]?HIGH:LOW;
		case 5:
			return lpc1114.AHB.GPIO[3].DATA[1<<1]?HIGH:LOW;
		case 6:
			return lpc1114.AHB.GPIO[3].DATA[1<<0]?HIGH:LOW;
	}
	return LOW;
}

#include "../../devices/uart.h"


void UART::init (uint32_t baud){
	lpc1114.APB.syscon.SYSAHBCLKCTRL |= (1<<12);
	lpc1114.APB.syscon.UARTCLKDIV = 0x1;
	
	lpc1114.APB.syscon.SYSAHBCLKCTRL |= (1<<16);	// enable iocon
	
	lpc1114.APB.iocon.PIO1_6 = 0x01;	// use pio1_6 as RXD
	lpc1114.APB.iocon.PIO1_7 = 0x01;	// use pio1_7 as TXD
	
	lpc1114.APB.syscon.SYSAHBCLKCTRL &= ~(1<<16); // disable iocon
	
	lpc1114.APB.uart.LCR |= 0x80;	// DLAB = 1
	
	set_baud (baud);
	
	lpc1114.APB.uart.LCR = 0x03;	// DLAB = 0
	
	lpc1114.APB.uart.IER = 0x0;	// UART interrupt disable
	lpc1114.APB.uart.IIR = 0;
	lpc1114.APB.uart.FCR = 0x07;
	
	lpc1114.APB.uart.MCR = 0;
	
	lpc1114.APB.uart.MSR = 0;
	lpc1114.APB.uart.SCR = 0;
	lpc1114.APB.uart.FDR = 0x10;
}

void UART::set_baud (uint32_t baud){
	uint32_t Fdiv;
	
	Fdiv = 12000000;
	Fdiv /= lpc1114.APB.syscon.SYSAHBCLKDIV;
	Fdiv /= 16;
	Fdiv /= baud;
	
	lpc1114.APB.uart.DLL = Fdiv % 256;
	lpc1114.APB.uart.DLM = Fdiv / 256;
}

void UART::send (uint8_t data){
	while (!(lpc1114.APB.uart.LSR & 0x20));
	lpc1114.APB.uart.THR = data;
}

void UART::send (const char *str){
	int i;
	for (i = 0; str[i] != '\0'; i++) send (str[i]);
}

uint8_t UART::recv (){
	while (!(lpc1114.APB.uart.LSR & 0x01));
	return lpc1114.APB.uart.RBR;
}
