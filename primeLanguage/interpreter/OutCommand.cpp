#include "OutCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"

OutCommand::OutCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("OutCommand", _set, _sizeOfArray, 
						 _memory, _priority, 2)
{
	this->setEnum(OUT_STACK);
}

OutCommand::~OutCommand(void)
{
	set.clear();
}

void OutCommand::execute(int *program, int pos, int length)
{
	this->checkValidity(pos, length);
	int stackNo = program[pos+1];
	while(!memory->empty(stackNo))
	{
		std::cout << memory->top(stackNo);
		memory->pop(stackNo);
	}
#if DEBUG
	std::cout << "\nOutCommand::execute() " << program[pos] << "\n";
#endif
	// std::cout << stack.size() << " for OutCommand " 
	//           << this->getPriority() << std::endl;  
}
