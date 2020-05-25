#ifndef SYSTEM_FILESYS_H
#define SYSTEM_FILESYS_H

#include "../types.h"

#pragma anon_unions

union Sector {
	struct {//
		uint8_t RESERVED0[256];
	};
	struct {
		union {
			uint8_t name[64];
			struct {//header
				uint8_t RESERVED1[56];//header name = '\0'
				uint32_t remain;
				uint32_t first_clear;
			};
		};
		uint8_t extension[16];
		union {
			uint8_t data[176];
			uint32_t inside[44];
		};
	};
	struct {//clear
		uint32_t number_of_cont;
		uint32_t prev_clear;
		uint32_t next_clear;
		uint8_t RESERVED2[244];
	};
};

#pragma no_anon_unions

class FileManager {
	protected:
		uint32_t sector;
		Sector temp;
	
		void write (uint32_t sector);
		void read (uint32_t sector);
	
		uint32_t get_clear (uint32_t size);
		void write_on_clear (uint32_t sector);
	public:
		FileManager ();
		void init ();
	
		void format ();
};

#endif
