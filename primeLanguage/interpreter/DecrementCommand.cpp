#include "DecrementCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"
#include "AllExceptions.h"

DecrementCommand::DecrementCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("DecrementCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(DEC_STACK_TOP);
}

DecrementCommand::~DecrementCommand(void)
{
	set.clear();
}

void DecrementCommand::execute(int *program, int pos, int length)
{
	this->checkValidity(pos, length);

	//stack.push(program[pos+1]);
#if DEBUG
	std::cout << "\nDecrementCommand::execute() " << program[pos] << "\n";
#endif

	int stackNoFrom = program[pos+1];
	int stackNoTo = program[pos+2];
	int a = memory->top(stackNoFrom);
	int b = memory->top(stackNoTo);
	b -= a;

	memory->pop(stackNoTo);
	memory->push(stackNoTo, b);
	// std::cout << stack.size() << " for DecrementCommand " 
	//           << this->getPriority() << std::endl;  
}
