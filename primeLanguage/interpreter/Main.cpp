#define DEBUG 0

#include "Interpreter.h"
#include "Command.h"
#include "PushCommand.h"
#include "PopCommand.h"
#include "Input.h"
#include "GenerateStackCommand.h"
#include "OutCommand.h"
#include "SwapCommand.h"
#include "IncrementCommand.h"
#include "LoopCommand.h"
#include "Memory.hpp"
#include "DecrementCommand.h"
#include "MultiplicationCommand.h"
#include "DivisionCommand.h"
#include "MyException.h"
#include "InputCommand.h"
#include "CopyCommand.h"
#include "PrimeGenerator.h"
#include "CommandEnum.h"
#include <iostream>

int main(int argc, char *argv[])
{
	PrimeGenerator generator(0,1000);
	
	std::vector<int> allCommandsInts[COMMAND_END];
	/*
	PUSH_STACK, POP_STACK, GENERATE_STACK, SWAP_STACK_TOP2, INC_STACK_TOP,
	DEC_STACK_TOP, MUL_STACK_TOP, DIV_STACK_TOP, LOOP_FOR, OUT_STACK,
	COPY_STACK, INPUT_STACK
	*/
	int nthprime[COMMAND_END] = {3,4,5,15,7,8,9,10,11,12,13,14};
	int priority[COMMAND_END] = {14,13,12,11,10,9,8,7,6,5,4,3};
	
	int psize = generator.noOfPrimes(), highestPriorityCommand;
	for(int i=0;i<psize;++i)
	{
		highestPriorityCommand = -1;
		for(int j=0;j<COMMAND_END;++j)
		{
			if((i+1)%nthprime[j]==0)
			{
				// should sort by priority and then just break
				if((highestPriorityCommand == -1) 
					|| priority[j] < priority[highestPriorityCommand])
				{
					highestPriorityCommand = j;
				}
			}
		}
		if(highestPriorityCommand != -1)
		{
			allCommandsInts[highestPriorityCommand].
				push_back(generator.getIthPrime(i+1));
		}
	}
	
	for(int i=0;i<COMMAND_END;++i)
	{
		if(allCommandsInts[i].size() == 0)
		{
			std::cerr << "\nError: Command of index " << i+1
					  << " is not having any number";
			return -2;
		}
		else
		{
			std::cout << "\nCOmmand " << i+1 << "\n";
			int comSize = allCommandsInts[i].size();
			for(int j=0;j<comSize;++j)
			{
				std::cout << allCommandsInts[i][j] << " " ;
			}
		}
	}

	if(argc < 2)
	{
		std::cerr << "Error:\nUsage: " << argv[0] << " program_name [ < input_filename ] [ > output_filename ]";
		return -1;
	}
	// static for NULL
	static Command *command[COMMAND_END]={NULL};
	
	Memory<int> memory;

	command[0] = new PushCommand(&(allCommandsInts[PUSH_STACK][0]), allCommandsInts[PUSH_STACK].size(), 
		&memory, priority[PUSH_STACK]);
	command[1] = new PopCommand(&(allCommandsInts[POP_STACK][0]),  allCommandsInts[POP_STACK].size(), 
		&memory, priority[POP_STACK]);
	command[2] = new GenerateStackCommand(&(allCommandsInts[GENERATE_STACK][0]), allCommandsInts[GENERATE_STACK].size(), 
		&memory, priority[GENERATE_STACK]);
	command[3] = new OutCommand(&(allCommandsInts[OUT_STACK][0]), allCommandsInts[OUT_STACK].size(), 
		&memory, priority[OUT_STACK]);
	command[4] = new SwapCommand(&(allCommandsInts[SWAP_STACK_TOP2][0]), allCommandsInts[SWAP_STACK_TOP2].size(),
		&memory, priority[SWAP_STACK_TOP2]);
	command[5] = new IncrementCommand(&(allCommandsInts[INC_STACK_TOP][0]), allCommandsInts[INC_STACK_TOP].size(),
		&memory, priority[INC_STACK_TOP]);
	command[6] = new LoopCommand(&(allCommandsInts[LOOP_FOR][0]), allCommandsInts[LOOP_FOR].size(),
		&memory, priority[LOOP_FOR]);
	command[7] = new DecrementCommand(&(allCommandsInts[DEC_STACK_TOP][0]), allCommandsInts[DEC_STACK_TOP].size(),
		&memory, priority[DEC_STACK_TOP]);
	command[8] = new MultiplicationCommand(&(allCommandsInts[MUL_STACK_TOP][0]), allCommandsInts[MUL_STACK_TOP].size(),
		&memory, priority[MUL_STACK_TOP]);
	command[9] = new DivisionCommand(&(allCommandsInts[DIV_STACK_TOP][0]), allCommandsInts[DIV_STACK_TOP].size(),
		&memory, priority[DIV_STACK_TOP]);	
	command[10] = new InputCommand(&(allCommandsInts[INPUT_STACK][0]), allCommandsInts[INPUT_STACK].size(),
		&memory, priority[INPUT_STACK]);
	command[11] = new CopyCommand(&(allCommandsInts[COPY_STACK][0]), allCommandsInts[COPY_STACK].size(),
		&memory, priority[COPY_STACK]);

	Interpreter interpreter(command,COMMAND_END);
	interpreter.setMemory(&memory);

	Input input(argv[1]);

	input.inputProgram();
	
	void *pg = input.getProgram();
	int sizeInBytes = input.getProgramSize();

	int *p = (int *)pg;
	int size = sizeInBytes/sizeof(int);

#if DEBUG
	std::cout << "\nSize is: " << size << std::endl;
	for(int i=0;i<size;++i)
		std::cout << p[i] << " ";
#endif	
	try
	{
		interpreter.execute(pg, sizeInBytes);
	}catch(MyException exp)
	{
		std::cout << "Exception occured\n" << exp.getMessage();
	}

	for(int i=0;i<COMMAND_END;++i)
	{
		//std::cout << "\nDeleting " << i;
		delete command[i];
	}
	return 0;
}