#pragma once
#include <vector>
#include <stack>
#include "AllExceptions.h"

template <class T, unsigned int primeUpto = 100>
class Memory
{
	std::vector<std::stack<T> > stacks;	
	std::vector<int> primeN;
	int nSize; // nSize is the prime no corresponding to size of stacks.

	int getStackNo(int stackNo)
	{
		if(stackNo >= 0 && (unsigned int)stackNo < primeN.size())
			return primeN[stackNo]-1;
		IllegalMemoryReference exp;
		throw exp;
	}
public:
		
	Memory(void):nSize(0)
	{
		for(int i=0;i<=primeUpto;++i)
		{
			primeN.push_back(0);
		}
		primeN[0] = primeN[1] = -1;
		int count = 0;
		for(int i=2;i<=primeUpto;++i)
		{
			if(primeN[i] != -1)
			{
				++count;
				primeN[i] = count;
				if((long long)i*i <= primeUpto)
				{
					for(int j=i*i;j<=primeUpto; j+=i)
					{
						primeN[j] = -1;
					}
				}
			}
		}
	}

	void generateStack()
	{
#if DEBUG
		std::cout << "\nGenreateStack()\n";
#endif
		int i;
		// sequential search for the next prime no.
		for(i = nSize+1;i<=primeUpto;++i)
		{
			if(primeN[i] != -1)
			{
				nSize = i;
				break;
			}
		}
		if(i == primeUpto+1)
		{
			OutOfMemoryException exp;
			throw exp;
		}
		std::stack<T> tstack;
		stacks.push_back(tstack);
	}
	
	T top(int stackNo)
	{
#if DEBUG
		std::cout << "\nStack Size: " << stacks.size()<< " TOP()";
#endif
		stackNo = getStackNo(stackNo);
#if DEBUG
		std::cout << "\nStackNo: " << stackNo;
#endif
		return stacks[stackNo].top();
	}
	
	void pop(int stackNo)
	{
		stackNo = getStackNo(stackNo);
#if DEBUG
		std::cout << "\nStackNo: " << stackNo << " POP()";
#endif
		stacks[stackNo].pop();
	}
	
	void push(int stackNo, T &value)
	{
		stackNo = getStackNo(stackNo);
#if DEBUG
		std::cout << "\nStackNo: " << stackNo << " PUSH()";
#endif
		stacks[stackNo].push(value);
	}
	
	bool empty(int stackNo)
	{
		stackNo = getStackNo(stackNo);
#if DEBUG
		std::cout << "\nStackNo: " << stackNo << " Empty()";
#endif
		return stacks[stackNo].empty();
	}
	
	int nStacks()
	{
		return nSize;
	}
	
	virtual ~Memory(void)
	{
		stacks.clear();
	}
};
