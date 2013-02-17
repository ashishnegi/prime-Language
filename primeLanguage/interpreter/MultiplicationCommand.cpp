#include "MultiplicationCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"
#include "AllExceptions.h"

MultiplicationCommand::MultiplicationCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("MultiplicationCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(MUL_STACK_TOP);
}

MultiplicationCommand::~MultiplicationCommand(void)
{
	set.clear();
}

void MultiplicationCommand::execute(int *program, int pos, int length)
{
	this->checkValidity(pos, length);

	//stack.push(program[pos+1]);
#if DEBUG
	std::cout << "\nMultiplicationCommand::execute() " << program[pos] << "\n";
#endif
	int stackNoFrom = program[pos+1];
	int stackNoTo = program[pos+2];
	int a = memory->top(stackNoFrom);
	int b = memory->top(stackNoTo);
	b /= a;
	memory->pop(stackNoTo);
	memory->push(stackNoTo, b);
	// std::cout << stack.size() << " for MultiplicationCommand " 
	//           << this->getPriority() << std::endl;  
}
