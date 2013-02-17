#include "PopCommand.h"
#include <algorithm>
#include <iostream>

PopCommand::PopCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("PopCommand", _set, _sizeOfArray, 
						 _memory, _priority, 2)
{
	this->setEnum(POP_STACK);
}

PopCommand::~PopCommand(void)
{
	set.clear();
}

void PopCommand::execute(int *program, int pos, int length)
{
#if DEBUG
	std::cout << "\nPopCommand::execute() " << program[pos] << "\n";
#endif
	// write pop here
	this->checkValidity(pos, length);
	int stackNo = program[pos+1];
	memory->pop(stackNo);
	// std::cout << stack.size() << " for PopCommand " 
	//           << this->getPriority() << std::endl;  
}