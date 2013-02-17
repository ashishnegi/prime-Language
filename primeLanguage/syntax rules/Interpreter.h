#pragma once
#include "Command.h"
// #include <boost/shared_ptr.hpp>

class Interpreter
{
	// std::vector<boost::shared_ptr<Command> > commands;
	std::vector<Command *> commands;

public:
	Interpreter(Command **_commands, int sizeOfArray);
	
	virtual void execute(const void *program, const int sizeInBytes);
	
	Command *getErrorCommand();
	
	~Interpreter(void);
};
