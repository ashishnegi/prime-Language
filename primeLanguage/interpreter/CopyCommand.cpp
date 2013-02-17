#include "CopyCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"

CopyCommand::CopyCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("CopyCommand", _set, _sizeOfArray, 
						 _memory, _priority, 3)
{
	this->setEnum(COPY_STACK);
}

CopyCommand::~CopyCommand(void)
{
	set.clear();
}

void CopyCommand::execute(int *program, int pos, int length)
{
	// push the next number
	this->checkValidity(pos, length);
	// write push operation here.
	int stackNoFrom = program[pos+1];
	int stackNoTo = program[pos+2];
	int toPush = memory->top(stackNoFrom);
	memory->push(stackNoTo, toPush);
#if DEBUG
	std::cout << "\nCopyCommand::execute() " << program[pos] << "\n";
#endif
	// std::cout << stack.size() << " for CopyCommand " 
	//           << this->getPriority() << std::endl;  
}
