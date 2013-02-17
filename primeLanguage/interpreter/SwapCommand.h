#pragma once

#include "stackcommand.h"
#include "Memory.hpp"

class SwapCommand :
	public StackCommand
{
public:
	
	SwapCommand(const int _set[], const int sizeOfArray, 
		Memory<int> *_memory, const int priority);
	virtual void execute(int *program, int pos, int length);
	~SwapCommand(void);
};
