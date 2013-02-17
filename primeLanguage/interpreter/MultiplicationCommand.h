#pragma once

#include "StackCommand.h"
#include <vector>
#include <stack>
#include "Memory.hpp"

class MultiplicationCommand :
	public StackCommand
{

public:
	
	MultiplicationCommand(const int _set[], const int sizeOfArray, 
		Memory<int> *_memory, const int priority);
	virtual void execute(int *program, int pos, int length);
	~MultiplicationCommand(void);
};
