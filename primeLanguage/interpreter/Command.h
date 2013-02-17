#pragma once
#include <string>
#include "CommandEnum.h"

class Command
{
	int priority;
	std::string name;
	int commandSize;
	enum CommandName enumName;
public:
	Command(std::string _name, const int _priority, const int _commandSize);
	bool operator<(const Command &command)const;
	std::string getName()const;
	int getPriority()const;
	enum CommandName getEnum()const;
	void setEnum(enum CommandName);

	virtual bool isInSet(int)const;
	virtual void execute(int *program, int pos, int length);
	virtual int sizeOfCommand()const;
	virtual ~Command(void);
};
