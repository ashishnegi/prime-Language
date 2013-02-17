#include "StackCommand.h"
#include <algorithm>
#include <iostream>
#include "AllExceptions.h"

StackCommand::StackCommand(std::string _name, const int _set[], 
						   const int sizeOfArray, Memory<int> *_memory, 
						   const int _priority, const int sizeOfCommand)
						 :Command(_name, _priority, sizeOfCommand),memory(_memory)
{
	for(int i=0;i<sizeOfArray;++i)
	{
		this->set.push_back(_set[i]);
	}
	sort(set.begin(), set.end());
}

StackCommand::~StackCommand(void)
{
	set.clear();
}

bool StackCommand::isInSet(int num) const
{
#if DEBUG
	std::cout << "\nStackCommand isInSet() of " << this->getName() << " : " << num;
#endif
	int size = set.size();
	int l = 0, r = size-1;	
	int mid;

	while(l<=r)
	{
		mid = (l+r)/2;
		if(num == set[mid])
			return true;
		else
		if(num < set[mid])
			r = mid-1;
		else
			l = mid+1;
	}
	return false;
}

void StackCommand::checkValidity(int pos, int length)
{
	if(pos < 0 || pos >= length)
	{
		IndexOutOfArrayException exp;
		throw exp;
	}
	if(pos > length - (this->sizeOfCommand()))
	{
		IllegalCommandException exp;
		throw exp;
	}	
}