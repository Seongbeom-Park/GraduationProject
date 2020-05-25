#include "memory.h"

MemoryManager::MemoryManager (){
	init ();
}

void MemoryManager::init (){
	last = RAM_SIZE - STACK_SIZE;
}

void* MemoryManager::alloc (uint32_t size){
	last-=size;
	return (void*)(RAM_BASE + ((last>>3)<<3));
}
