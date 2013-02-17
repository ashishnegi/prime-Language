#pragma once
#include <vector>

class PrimeGenerator
{
	int start, end;
	std::vector<int> primes; 
	//primeN[i] = n => n is the (i+1)th prime No. in [start, end]

public:
	PrimeGenerator(int,int);
	void displayPrimes();
	int noOfPrimes();
	int getIthPrime(int);
	virtual ~PrimeGenerator(void);
};
