#pragma once
#include <string>

class MyException
{
	std::string message;
public:
	MyException(std::string);
	std::string getMessage();
	virtual ~MyException(void);
};