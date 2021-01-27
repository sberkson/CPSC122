/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 1/29/21
Assignment: Project 1
Description: Program is designed to generate X amount of prime numbers.  Program takes in an output file name, number of primes to be generated, and colums to display primes in as command line arguments. Program then generates prime numbers and writes to output file.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Function Prototypes
bool isPrime(int);
void writeToFile(ofstream& outputFile,vector<int>& primeList, int);

//Determines if number is prime
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
	
//Writes prime numbers to output file	
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
		//Variables and output file declared and initialized.  Variables using command line arguments are intitialized and converted to integers where necessary.  4 integers are used to keep track of important data, such as the number being checked and the number of primes generated, as well as the desired number of primes and the number of columns to be displayed.
		int numPrimes = atoi(argv[2]);
		int columns = atoi(argv[3]);
		int interval = 0;
		int primes = 0;
		vector<int> primeList;
		
		ofstream outputFile;
		outputFile.open(argv[1]);
		
		//Loops through until desired number of primes are generated.  When prime is found, it is added to vector list.
		for(int num = 0; primes < numPrimes; num++)
			{
				if(isPrime(num))
					{
						primeList.push_back(num);
						primes++;
					}
			}
		
		//Writes primes to output file and closes output file.
		writeToFile(outputFile, primeList, columns);	
		outputFile.close();
		
		return 0;
	}
