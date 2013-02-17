#include "LoopCommand.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"

LoopCommand::LoopCommand(const int _set[], const int _sizeOfArray, 
						 Memory<int> *_memory, const int _priority)
						 :StackCommand("LoopForCommand", _set, _sizeOfArray, 
						 _memory, _priority, 2)
{
	this->setEnum(LOOP_FOR);
}

LoopCommand::~LoopCommand(void)
{
	set.clear();
}

void LoopCommand::execute(int *program, int pos, int length)
{
#if DEBUG
	std::cout << "\nLoopCommand::execute() " << program[pos] << "\n";
#endif
	// std::cout << stack.size() << " for LoopCommand " 
	//           << this->getPriority() << std::endl;  
}
