#include "PrimeGenerator.h"
#include <iostream>
#include "AllExceptions.h"

PrimeGenerator::PrimeGenerator(int _start, int _end):start(_start),end(_end)
{
	std::vector<int> primeN;
#ifdef DEBUG
	std::cout << "\nConstructor(): " << start << " " << end << " \n";
#endif
	if((end < start) || (start < 0))
	{
		WrongRangeException exp;
		throw exp;
	}
	int i;
	for(i=start; i<=end;++i)
	{
		primeN.push_back(0);
	}
	if(start==0)
		primeN[0] = -1;
	if(end >= 1 && start < 2)
			primeN[1-start] = -1;

	int j, count=0;
	for(i=2;i<=end;++i)
	{
		if((start <= i) && (primeN[i-start] != -1))
		{
			primeN[i-start] = ++count;
			primes.push_back(i);
			j = i*i;
		}
		else 
		if(start > i)
		{
			j = start;
			while((j%i) && (j<=end)) ++j;
		}

		for(;j<=end;j+=i)
		{
			primeN[j-start] = -1;
		}
	}
}

void PrimeGenerator :: displayPrimes()
{
	std::cout << "\nPrimeGenerator: " << start << " " << end << " \n";
	int size = primes.size();
	for(int i=0;i<size;++i)
	{
		std::cout << i+1 << " : " << primes[i] << "\n";
	}
}

PrimeGenerator::~PrimeGenerator(void)
{
}

int PrimeGenerator::noOfPrimes()
{
	return primes.size();
}

int PrimeGenerator::getIthPrime(int i)
{
	if((i>0) && (i<=noOfPrimes()))
	{
		return primes[i-1];
	}

	IndexOutOfArrayException exp;
	throw exp;
}