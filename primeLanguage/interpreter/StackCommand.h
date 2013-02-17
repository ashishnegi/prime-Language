#pragma once
#include "Command.h"
#include <stack>
#include <vector>
#include <string>
#include "Memory.hpp"

class StackCommand :
	public Command
{
	/*
		We can precompute all the possible pairs for this Pop command.
		and do Binary serch on it.
		OR
		We can write the logic in isInSet() only
	*/

protected:
	std::vector<int> set;
	Memory<int> *memory;

	void checkValidity(int, int);
public:
	StackCommand(std::string _name, const int _set[], const int sizeOfArray, 
		Memory<int> *_memory, const int priority, const int sizeOfCommand);

	virtual bool isInSet(int num)const;
	virtual ~StackCommand(void);
};
