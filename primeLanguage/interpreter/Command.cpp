#include "Command.h"
#include <iostream>

Command::Command(std::string _name, const int _priority, const int _commandSize)
:name(_name), priority(_priority), commandSize(_commandSize)
{
}

Command::~Command(void)
{
}

bool Command::operator <(const Command &command)const
{
	return this->priority < command.priority;
}

bool Command::isInSet(int n) const
{
	return false;
}

void Command::execute(int *program, int pos, int length)
{
	std::cout << "\nCommand::execute() " << program[pos] << "\n";
}

std::string Command::getName() const
{
	return name;
}

int Command::getPriority() const
{
	return priority;
}

int Command::sizeOfCommand() const
{
	return commandSize;
}

enum CommandName Command::getEnum()const
{
	return enumName;
}

void Command::setEnum(enum CommandName name)
{
	enumName = name;
}