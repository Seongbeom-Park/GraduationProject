#ifndef SYSTEM_PROCESS_H
#define SYSTEM_PROCESS_H

#include "../types.h"

typedef uint8_t PID;

class Process;
class Thread {
	private:
		Process *parent;
	public:
		Thread (Process *parent);
};

class Process: protected Thread {
	private:
		PID pid;
	public:
		Process (PID pid);
	
		PID get_pid ();
};

class ProcessManager {
	private:
		PID curr_pid;
		uint8_t pid_counter;
	public:
		ProcessManager ();
		void init ();
};

#endif
