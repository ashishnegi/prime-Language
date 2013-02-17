#include "SwapCommand.h"
#include <iostream>

SwapCommand::SwapCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("SwapCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(SWAP_STACK_TOP2);
}

SwapCommand::~SwapCommand(void)
{
	set.clear();
}

void SwapCommand::execute(int *program, int pos, int length)
{
	this->checkValidity(pos, length);
	int stackNo1 = program[pos+1];
	int stackNo2 = program[pos+2];
	int a = memory->top(stackNo1);
	int b = memory->top(stackNo2);
	memory->pop(stackNo1);
	memory->pop(stackNo2);
	memory->push(stackNo1, b);
	memory->push(stackNo2, a);
#if DEBUG
	std::cout << "\nSwapCommand::execute() " << program[pos] << "\n";
#endif
	// std::cout << stack.size() << " for PushCommand " 
	//           << this->getPriority() << std::endl;  
}