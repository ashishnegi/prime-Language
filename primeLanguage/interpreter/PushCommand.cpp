#include "PushCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"

PushCommand::PushCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("PushCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(PUSH_STACK);
}

PushCommand::~PushCommand(void)
{
	set.clear();
}

void PushCommand::execute(int *program, int pos, int length)
{
	// push the next number
	this->checkValidity(pos, length);
	// write push operation here.
	int stackNo = program[pos+1];
	int toPush = program[pos+2];
	memory->push(stackNo, toPush);
#if DEBUG
	std::cout << "\nPushCommand::execute() " << program[pos] << "\n";
#endif
	// std::cout << stack.size() << " for PushCommand " 
	//           << this->getPriority() << std::endl;  
}
