#ifndef MEMORY_MEMORY_H
#define MEMORY_MEMORY_H

#include "../types.h"

class MemoryManager {
	protected:
		uint32_t last;
	public:
		MemoryManager ();
		void init ();
	
		void* alloc (uint32_t size);
};

#endif
