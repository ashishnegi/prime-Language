#include "InputCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"

InputCommand::InputCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("InputCommand", _set, _sizeOfArray, 
						 _memory, _priority, 1)
{
	this->setEnum(INPUT_STACK);
}

InputCommand::~InputCommand(void)
{
	set.clear();
}

void InputCommand::execute(int *program, int pos, int length)
{
	// push the next number
	this->checkValidity(pos, length);
	// write push operation here.
	int stackNo = memory->nStacks();
	int toPush = -1;
	std::cin >> toPush;
	memory->push(stackNo, toPush);
#if DEBUG
	std::cout << "\nInputCommand::execute() " << program[pos] << "\n";
#endif
	// std::cout << stack.size() << " for InputCommand " 
	//           << this->getPriority() << std::endl;  
}
