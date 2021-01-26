/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 
Assignment: Project 4
Description: 
*/

#include iostream
#include fstream
#include cmath

int checkIfPrime(int);

bool checkIfPrime(int num)
	{
		for(int i = 2; i <= num; i++)
			{
				if(num % i == 0)
					{
						return false;
					}
				else
					{
						return true;
					}
			}
	}

int main(int argc, char* argv[])
	{
		int numPrimes = atoi(argv[1]);
		int columns = atoi(argv[2]);
		int interval = 0;
		int primes = 0;
		ofstream outputFile;
		
		outputFile.open(argv[3]);
		
		while(primes < numPrimes)
			{
				if(checkIfPrime(interval))
					{
						outputFile << interval;
						primes++;
					}		
				interval++			
			}
			
		outputFile.close();
		
		return 0;
	}
