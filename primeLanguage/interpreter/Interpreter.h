#pragma once
#include "Command.h"
#include <vector>
#include <stack>
#include "Memory.hpp"
// #include <boost/shared_ptr.hpp>

class Interpreter
{
	// std::vector<boost::shared_ptr<Command> > commands;
	std::vector<Command *> commands;
	Memory<int> *memory;

	int getCommand(int);
	void decTop(int);
public:
	class IllegalCommandException{};

	Interpreter(Command *_commands[], const int sizeOfArray,
		Memory<int> *_memory=NULL);
	
	virtual void execute(const void *program, const int sizeInBytes);
	CommandName getCommandEnum(int prog);
	int executeEnum(CommandName command, int program[], int i, 
				 std::vector<std::stack<int> > &stacks);
	void setMemory(Memory<int> *memory);
	~Interpreter(void);
};
