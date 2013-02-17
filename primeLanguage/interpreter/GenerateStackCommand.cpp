#include "GenerateStackCommand.h"
#include "CommandEnum.h"
#include <iostream>

GenerateStackCommand::GenerateStackCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("GenerateStackCommand", _set, _sizeOfArray, 
						 _memory, _priority, 1)
{
	this->setEnum(GENERATE_STACK);
}

GenerateStackCommand::~GenerateStackCommand(void)
{
}

void GenerateStackCommand::execute(int *program, int pos, int length)
{
#if DEBUG
	std::cout << "\nGenerateCommand::execute() " << program[pos] << "\n";
#endif
	this->checkValidity(pos,length);
	memory->generateStack();
}