#pragma once
#include "MyException.h"

class IndexOutOfArrayException : public MyException
{
public:
	IndexOutOfArrayException():MyException("IndexOutOfArrayException"){}
};
class IllegalCommandException : public MyException
{
public:
	IllegalCommandException():MyException("IllegalCommandException"){}
};


class DivisionByZeroException : public MyException
{
public:
	DivisionByZeroException():MyException("DivisionByZeroException"){}
};

class IllegalMemoryReference : public MyException
{
public:
	IllegalMemoryReference():MyException("IllegalMemoryReference"){}
};

class OutOfMemoryException : public MyException
{
public:
	OutOfMemoryException():MyException("OutOfMemoryException"){}
};

class FileNotOpeningException{};
class NoProgramException{};

class WrongRangeException: public MyException
{
public:
	WrongRangeException():MyException("WrongRangeException"){}
};