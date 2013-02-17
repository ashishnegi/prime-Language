#pragma once

#include "StackCommand.h"
#include <vector>
#include <stack>
#include "Memory.hpp"

class PopCommand :
	public StackCommand
{
public:

	PopCommand(const int _set[], const int sizeOfArray, 
		Memory<int> *_memory, const int priority);
	virtual void execute(int *, int, int);
	~PopCommand(void);
};
