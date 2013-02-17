#include "DivisionCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"
#include "AllExceptions.h"

DivisionCommand::DivisionCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("DivisionCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(MUL_STACK_TOP);
}

DivisionCommand::~DivisionCommand(void)
{
	set.clear();
}

void DivisionCommand::execute(int *program, int pos, int length)
{
	this->checkValidity(pos, length);

	//stack.push(program[pos+1]);
#if DEBUG
	std::cout << "\nDivisionCommand::execute() " << program[pos] << "\n";
#endif
	int stackNoFrom = program[pos+1];
	int a = memory->top(stackNoFrom);
	
	if(a == 0)
	{
		DivisionByZeroException exp;
		throw exp;
	}

	int stackNoTo = program[pos+2];
	int b = memory->top(stackNoTo);
	b /= a;

	memory->pop(stackNoTo);
	memory->push(stackNoTo, b);
	// std::cout << stack.size() << " for DivisionCommand " 
	//           << this->getPriority() << std::endl;  
}
