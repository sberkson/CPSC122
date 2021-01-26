/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 
Assignment: Project 4
Description: 
*/

#include <iostream>
#include <fstream>

bool checkIfPrime(int);

bool checkIfPrime(int num)
	{
		if(num <= 1)
			{
				return false;
			}
		
		if(num <= 3)
			{
				return true;
			}
		
		for(int i = 2; i < num; i++)
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
		int numPrimes = atoi(argv[2]);
		int columns = atoi(argv[3]);
		int interval = 0;
		int primes = 0;
		std::string outputFileName = argv[1];
		
		std::ofstream outputFile;
		
		outputFile.open("Primes.txt");
		
		while(primes < numPrimes)
			{
				if(checkIfPrime(interval))
					{
						outputFile << interval << std::endl;
						std::cout << interval << std::endl;
						primes++;
					}		
				interval++;			
			}
			
		outputFile.close();
		
		return 0;
	}
