#include "Input.h"
#include <cstdio>
#include <cstring>
#include <fstream>

Input::Input(std::string _fileName):fileName(_fileName)
{
}

Input::~Input(void)
{
}

int Input::inputProgram()
{
	int n;
	std::fstream file(&fileName[0]);
	if(!file)
	{
		FileNotOpeningException exp;
		throw exp;
	}
	while(!file.eof())
	{
		file >> n;
		program.push_back(n);
	}
	return program.size();
}

void *Input::getProgram()
{
	if(program.size() > 0)
		return &program[0];
	NoProgramException exp;
	throw exp;
}

int Input::getProgramSize()
{
	int size = program.size();

	if(size > 0)
		return size*sizeof(int);
	
	NoProgramException exp;
	throw exp;
}