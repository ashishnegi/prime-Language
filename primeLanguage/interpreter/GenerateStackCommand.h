#pragma once
#include "StackCommand.h"
#include "Memory.hpp"

class GenerateStackCommand :
	public StackCommand
{
public:
	GenerateStackCommand(const int _set[], const int sizeOfArray, 
		Memory<int> *_memory, const int priority);

	void execute(int *program, int pos, int length);
	~GenerateStackCommand(void);
};
