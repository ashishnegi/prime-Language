#include "Interpreter.h"
#include <algorithm>
#include <iostream>
#include "CommandEnum.h"
#include <stack>
#include <vector>

bool sortCommandsByPriority(const Command *com1, const Command *com2)
{
	return (*com1) < (*com2);
}

Interpreter::Interpreter(Command *_commands[], const int sizeOfArray, 
						 Memory<int> *_memory):memory(_memory)
{
	for(int i=0;i<sizeOfArray; ++i)
	{
		this->commands.push_back(_commands[i]);
	}
	sort(commands.begin(), commands.end(), sortCommandsByPriority);
#if DEBUG
	for(int i=0;i<sizeOfArray;++i)
		std::cout << commands[i]->getName()<< " "
				  << commands[i]->getPriority() << std::endl;
#endif
}

void Interpreter::setMemory(Memory<int> *_memory)
{
	memory = _memory;
}

Interpreter::~Interpreter(void)
{
}

void Interpreter::decTop(int stackNo)
{
	int a = memory->top(stackNo);
	--a;
	memory->pop(stackNo);
	memory->push(stackNo, a);
}

void Interpreter::execute(const void *_program, const int sizeInBytes)
{
	int *program = (int *)_program;
	int size = sizeInBytes/sizeof(int);
	int comIndex, stackNo;
	int commandSize = commands.size();
	std::vector<int> loopArray;

	for(int i=1;i<size-1;++i)
	{
#if DEBUG
		std::cout << "\nProgram[i] " << i << " " << program[i];
#endif
		comIndex = this->getCommand(program[i]);
		switch(commands[comIndex]->getEnum())
		{
			case LOOP_FOR:
				++i;
				int k;
				loopArray.clear();
				while(!(commands[comIndex]->isInSet(program[i])))
				{
					loopArray.push_back(program[i]);
					++i;
				}
				k = loopArray.size();
#if DEBUG
				std::cout <<  "\nK: " << k;
#endif
				if(k>0)
				{
					stackNo = loopArray[0];
#if DEBUG
					std::cout <<  "\n..>>" << stackNo; 
					std::cout << "\nFOR FOR LOOP <>><><><><><";
#endif
					for(;memory->top(stackNo);)
					{
						for(int h=1;h<k;)
						{
							int comI = getCommand(loopArray[h]);
							commands[comI]->execute(&loopArray[0], h, k);
							h += commands[comI]->sizeOfCommand();
						}
						this->decTop(stackNo);
					}
#if DEBUG
					std::cout << "\nEND END END FOR FOR LOOP <>><><><><><";					
#endif
				}
				break;
			default:
				commands[comIndex]->execute(program, i, size);
				i += (commands[comIndex]->sizeOfCommand()-1);
				break;
		}
#if DEBUG
		std::cout << "\nI: " << i << "\n";
#endif
	}
}

int Interpreter::getCommand(int prog)
{
	int j=0, commandSize = commands.size();
	while((j < commandSize) && !(commands[j]->isInSet(prog)))
		++j;
	
	if(j == commandSize)
	{
#if DEBUG
		std::cout << "Throwing exception for " << prog << std::endl ;
#endif
		IllegalCommandException exp;
		throw exp;
	}
	return j;
}

/*
void Interpreter::execute(const void *_program, const int sizeInBytes)
{
	int *program = (int *)_program;
	int size = sizeInBytes/sizeof(int);
	int j,stackSize;
	int commandSize = commands.size();
	// put these stacks into the interpreter.
	std::vector<std::stack<int> > stacks;
	std::vector<int> loopArray;

	for(int i=1;i<size-1;++i)
	{
#if DEBUG
		std::cout << "\n" << i << " : " << program[i] << "\n";
		std::cout << "\n-->";
#endif
		j=0;
		while((j < commandSize) && !(commands[j]->isInSet(program[i])))
			++j;
		
		if(j == commandSize)
		{
#if DEBUG
			std::cout << "Throwing exception for " << program[i] << std::endl ;
#endif
			IllegalCommandException exp;
			throw exp;
		}

		int stackNo, toPush;
		switch(commands[j]->getEnum())
		{
			case PUSH_STACK :
#if DEBUG
				std::cout << "\nPush Stack";
#endif
				++i;
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					++i;
					toPush = program[i];
					stacks[stackNo].push(toPush);
					//std::cout << "\nPush Stack";
				}
				break;
			case POP_STACK:
#if DEBUG
				std::cout << "\nPop Stack";
#endif
				++i;
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					stacks[stackNo].pop();
					//std::cout << "\nPop Stack";
				}
				break;
			case OUT_STACK:
				//std::cout << "\nOut Stack";
				++i;
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					stackSize = stacks[stackNo].size();
					for(int j=0;j<stackSize;++j)
					{
						std::cout << stacks[stackNo].top();
						stacks[stackNo].pop();
					}
				}
				break;
			case SWAP_STACK_TOP2:
				++i;
				// ALWAYS check if i is in limits.. make a separete function.
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					if(stacks[stackNo].size() >= 2)
					{
						int a = stacks[stackNo].top();
						stacks[stackNo].pop();
						int b = stacks[stackNo].top();
						stacks[stackNo].pop();
						stacks[stackNo].push(a);
						stacks[stackNo].push(b);
					}
					// throw exceptions
				}
				break;
			case INC_STACK_TOP:
				++i;
#if DEBUG
				std::cout << "\n" << stacks.size() << "\n";
				std::cout << "\nI: " << i << "\n";
#endif
				// ALWAYS check if i is in limits.. make a separete function.
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					int a = stacks[stackNo].top();
					stacks[stackNo].pop();
					stacks[stackNo].push(a+1);
				}
				break;
			case LOOP_FOR:
				++i;
				int k;
				loopArray.clear();
				while(!commands[j]->isInSet(program[i]))
				{
					// unless an endfor is written
					// ALWAYS check if i is in limits.. make a separete function.
					loopArray.push_back(program[i]);
					++i;
				}
				k = loopArray.size();
				std::cout << "\nK: " << k << "\n";
				if(k>0)
				{
					stackNo = getStackNo(loopArray[0]);
					std::cout << "\nStackNo: " << stackNo << "\n";
					for(;stacks[stackNo].top();)
					{
						for(int h=1;h<k;++h)
						{
							// oh gosh all the other cases want to come here..
							// so cases should be in a separate function ?
							// 1. make separate fucntion to find which command satisfys.
							// 2. make separate funciton to send the token to and having switch
							// 3. make separate function for each case.
							CommandName comName = getCommandEnum(loopArray[h]);
							h += executeEnum(comName, &loopArray[0], h,stacks);
						}
						--stacks[stackNo].top();
					}
				}
				break;
			case GENERATE_STACK:
				
#if DEBUG
				std::cout << "\nStacks: " << program[i] << " " << i << "\n";
				std::cout << "\nGenerating Stack";
#endif
				std::stack<int> newStack;
				stacks.push_back(newStack);
				break;
		}
#if DEBUG
		std::cout << "\n<--";
#endif
		//commands[j]->execute(program, i, size);
		//i += commands[j]->sizeOfCommand();
	}
}

int Interpreter::executeEnum(CommandName command, int program[], int i, 
				 std::vector<std::stack<int> > &stacks)
{
	int stackMulSize = 0;
	int stackNo, toPush,stackSize;
	switch(command)
	{
		case PUSH_STACK :
#if DEBUG
				std::cout << "\nPush Stack";
#endif
				++i;
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					++i;
					toPush = program[i];
					stacks[stackNo].push(toPush);
					//std::cout << "\nPush Stack";
				}
				break;
			case POP_STACK:
#if DEBUG
				std::cout << "\nPop Stack";
#endif
				++i;
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					stacks[stackNo].pop();
					//std::cout << "\nPop Stack";
				}
				break;
			case OUT_STACK:
				//std::cout << "\nOut Stack";
				++i;
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					stackSize = stacks[stackNo].size();
					for(int j=0;j<stackSize;++j)
					{
						std::cout << stacks[stackNo].top();
						stacks[stackNo].pop();
					}
				}
				break;
			case SWAP_STACK_TOP2:
				++i;
				// ALWAYS check if i is in limits.. make a separete function.
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					if(stacks[stackNo].size() >= 2)
					{
						int a = stacks[stackNo].top();
						stacks[stackNo].pop();
						int b = stacks[stackNo].top();
						stacks[stackNo].pop();
						stacks[stackNo].push(a);
						stacks[stackNo].push(b);
					}
					// throw exceptions
				}
				break;
			case INC_STACK_TOP:
				++i;
#if DEBUG
				std::cout << "\n" << stacks.size() << "\n";
				std::cout << "\nI: " << i << "\n";
#endif
				// ALWAYS check if i is in limits.. make a separete function.
				stackNo = getStackNo(program[i]);
				if(stackNo >= 0 && stacks.size() > stackNo)
				{
					int a = stacks[stackNo].top();
					stacks[stackNo].pop();
					stacks[stackNo].push(a+1);
				}
				break;
			case GENERATE_STACK:
				
#if DEBUG
				std::cout << "\nStacks: " << program[i] << " " << i << "\n";
				std::cout << "\nGenerating Stack";
#endif
				std::stack<int> newStack;
				stacks.push_back(newStack);
				break;
	}
	return i;
}
*/
/*
CommandName Interpreter::getCommandEnum(int prog)
{
	int j=0, commandSize = commands.size();
	while((j < commandSize) && !(commands[j]->isInSet(prog)))
		++j;
	
	if(j == commandSize)
	{
#if DEBUG
		std::cout << "Throwing exception for " << prog << std::endl ;
#endif
		IllegalCommandException exp;
		throw exp;
	}
	return commands[j]->getEnum();
}
*/
