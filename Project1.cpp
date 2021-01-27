/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 
Assignment: Project 4
Description: 
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(int);
void writeToFile(ofstream& outputFile,vector<int>& primeList, int);

bool isPrime(int number)
	{
		if(number <= 1)
			{
				return false;
			}
		
		for(int i = 2; i < number; i++)
			{
				if(number % i == 0)
					{
						return false;
						
					}
			}
		
		return true;
	}
	
void writeToFile(ofstream& outputFile, vector<int>& primeList, int cols)
	{
		int count = 0;
		int rowCount = 1;
		
		while (count < primeList.size())
			{
				outputFile << primeList[count] << '\t';
				
				if(count % cols == cols - 1)
					{
						outputFile << endl;
					}
				
				count++;
			}
	}

int main(int argc, char* argv[])
	{
		int numPrimes = atoi(argv[2]);
		int columns = atoi(argv[3]);
		int interval = 0;
		int primes = 0;
		vector<int> primeList;
		
		ofstream outputFile;
		
		outputFile.open(argv[1]);
		
		for(int num = 0; primes < numPrimes; num++)
			{
				if(isPrime(num))
					{
						primeList.push_back(num);
						primes++;
					}
			}
		
		writeToFile(outputFile, primeList, columns);	
		outputFile.close();
		
		return 0;
	}
