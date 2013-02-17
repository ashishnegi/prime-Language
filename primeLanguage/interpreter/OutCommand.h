#pragma once
#include "stackcommand.h"
#include "Memory.hpp"

class OutCommand :
	public StackCommand
{

public:
	
	OutCommand(const int _set[], const int sizeOfArray, 
		Memory<int> *_memory, const int priority);
	virtual void execute(int *program, int pos, int length);
	~OutCommand(void);
};
