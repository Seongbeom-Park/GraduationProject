#ifndef SYSTEM_SYSTEM_H
#define SYSTEM_SYSTEM_H

#include "../types.h"

#include "../devices/device.h"
#include "../process/process.h"
#include "../filesys/filesys.h"
#include "../memory/memory.h"

struct Library {
	char name[28];
	uint32_t func_loc;
};

class System:public DeviceManager, public ProcessManager, public FileManager, public MemoryManager {
	protected:
		uint8_t lib_number;
		Library lib[MAX_LIBRARY_NUMBER];
		uint32_t curr_dir_sector;
		char curr_dir[64];
		
	public:
		void* operator new (uint32_t size);
		System ();
	
		static void boot () asm ("boot");
		bool init ();
		void run ();
		void shutdown ();
	
		void load (const char* command, void (*func_loc)());
		void exec (const char* command);
		void execute (uint32_t func_loc) asm ("execute");

		void mkdir (const char* dir_name);
		void cd (const char* dir_name);
};

#endif
