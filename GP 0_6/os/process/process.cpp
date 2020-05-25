#include "process.h"

#include "../process/process.h"

Thread::Thread (Process *parent){
	this->parent = parent;
}

Process::Process (PID pid): Thread (this){
	this->pid = pid;
}

PID Process::get_pid (){
	return pid;
}

ProcessManager::ProcessManager (){
	init ();
}

void ProcessManager::init (){
	pid_counter = 1;
}
