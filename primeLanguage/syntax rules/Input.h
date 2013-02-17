#pragma once
#include <vector>
#include <string>
class Input
{
	std::vector<int> program;
	std::string fileName;

public:
	class FileNotOpeningException{};
	class NoProgramException{};
	Input(std::string);
	/*
	inputProgram inputs the integers of the program.
	It returns the number of total integers inputted.
	*/
	int inputProgram();
	void *getProgram();
	int getProgramSize();
	~Input(void);
};
