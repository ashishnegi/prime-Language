#include "IncrementCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"
#include "AllExceptions.h"

IncrementCommand::IncrementCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("IncrementCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(INC_STACK_TOP);
}

IncrementCommand::~IncrementCommand(void)
{
	set.clear();
}

void IncrementCommand::execute(int *program, int pos, int length)
{
	this->checkValidity(pos, length);

	//stack.push(program[pos+1]);
#if DEBUG
	std::cout << "\nIncrementCommand::execute() " << program[pos] << "\n";
#endif
	int stackNoFrom = program[pos+1];
	int stackNoTo = program[pos+2];
	int a = memory->top(stackNoFrom);
	int b = memory->top(stackNoTo);
	b += a;

	memory->pop(stackNoTo);
	memory->push(stackNoTo, b);
	// std::cout << stack.size() << " for IncrementCommand " 
	//           << this->getPriority() << std::endl;  
}
