#include <iostream>
#include <string>
#include "Input.h"
#include "Rule.h"
#include "SyntaxAnalyzer.h"
#include "StartAndEndRule.h"
#include "NumberFrequencyNotMoreThanNumberRule.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		std::cout << "Error:\nUsage: " << argv[0] << " program_name [ < input_filename ] [ > output_filename ]";
		return -1;
	}

	Input input(argv[1]);
	input.inputProgram();

	// put all of your syntaxRules here.
	Rule *syntaxRules[2];// = new Rule*[2];
	syntaxRules[0] = new StartAndEndRule();
	syntaxRules[1] = new NumberFrequencyNotMoreThanNumberRule();
	
	SyntaxAnalyzer compiler(syntaxRules, 2);

	void *pg = input.getProgram();
	int sizeInBytes = input.getProgramSize();

	bool success = compiler.compileSyntax(pg, sizeInBytes);

	// int *p = (int *)pg;
	// int size = sizeInBytes/sizeof(int);
	/*
	std::cout << "\nSize is: " << size << std::endl;
	for(int i=0;i<size;++i)
		std::cout << p[i] << " ";
	*/

	if(success)
	{
		std::cout << "Compiled successfully\n";
	}
	else
	{
		std::cout << "Not Compiled successfully\n"
			<< compiler.getErrorRule()->getName();
		delete syntaxRules[0];
		delete syntaxRules[1];
		return -1;
	}
	/*
	Interpreter interpreter(pg, sizeInBytes);
	try
	{
		interpreter.execute();
	}
	catch(Exception exp)
	{
		std::cout << "Execution error: " << exp.getExpMessage() << endl;
	}
	*/
	delete syntaxRules[0];
	delete syntaxRules[1];
	return 0;
}