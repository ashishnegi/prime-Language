#include "Interpreter.h"

Interpreter::Interpreter(Command **_commands, int sizeOfArray)
	:errorCommandIndex(-1)
{
	for(int i=0;i<sizeOfArray; ++i)
	{
		this->commands.push_back(_commands[i]);
	}
}

Interpreter::~Interpreter(void)
{
}

void execute(const void *program, const int sizeInBytes)
{
}
