#include "system.h"

System::System () : DeviceManager (), ProcessManager (), FileManager (), MemoryManager (){
	lib_number = 0;
	curr_dir_sector = 0;
	curr_dir[0] = '/';
	curr_dir[1] = '\0';
	//load libraries use location specificate
}

bool System::init (){
	DeviceManager::init ();
	ProcessManager::init ();
	FileManager::init ();
	MemoryManager::init ();
	
	lib_number = 0;
	curr_dir_sector = 0;
	curr_dir[0] = '/';
	curr_dir[1] = '\0';
	
	//load libraries use location specificate
	return true;
}

void test (){}
void System::run (){
	//format ();
	load ("test", &test);
	exec ("test");
}

void System::shutdown (){
}

void strcpy (char* dest, char* src){
	int i;
	for (i = 0; src[i] != '\0'; i++) dest[i] = src[i];
}

extern "C" uint32_t func2int (void (*func)());

void System::load (const char* command, void (*func_loc)()){
	strcpy ((char*)lib[lib_number].name, (char*)command);
	lib[lib_number].func_loc = func2int (func_loc);
	lib_number++;
}

bool strcmp (char* str1, char* str2){
	int i;
	for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
		if (str1[i] != str2[i]) return false;
	return (str1[i] =='\0') && (str2[i] == '\0');
}

void System::exec (const char* command){
	int i;
	for (i = 0; i<MAX_LIBRARY_NUMBER; i++)
		if (strcmp ((char*)lib[i].name, (char*)command)){
			execute (lib[i].func_loc);
			break;
		}
}

