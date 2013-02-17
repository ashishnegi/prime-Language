#include "MyException.h"

MyException::MyException(std::string _str):message(_str)
{
}

MyException::~MyException(void)
{
}

std::string MyException::getMessage()
{
	return message;
}