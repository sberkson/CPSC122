/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 1/29/21
Assignment: Project 1
Description: Program is designed to generate X amount of prime numbers.  Program takes in an output file name, number of primes to be generated, and colums to display primes in as command line arguments. Program then generates prime numbers and writes to output file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//Function Prototypes
bool isPrime(int);

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

int main(int argc, char* argv[])
{
	//Variables and output file declared and initialized.  Variables using command line arguments are intitialized and converted to integers where necessary.  4 integers are used to keep track of important data, such as the number being checked and the number of primes generated, as well as the desired number of primes and the number of columns to be displayed.  If incorrect nmber of arguments inputted, program exits.
	if(argc != 4)
		{
			cout << "Incorrect number of arguments inputted. Exiting program." << endl;
			exit(EXIT_FAILURE);
		}
	
	int numPrimes = atoi(argv[1]);
	int columns = atoi(argv[2]);
	int interval = 0;
	int primes = 0;
	int count = 0;
	int numPerRow = numPrimes / columns;
	
	ofstream outputFile;
	outputFile.open(argv[3]);
	
	//Loops through until desired number of primes are generated.  When prime is found, it is printed to output file.  When the number of primes per row has been reached, a new line is started in the output file.
	for(int num = 0; primes < numPrimes; num++)
		{
			if(isPrime(num))
				{
					primes++;
					count++;
					outputFile << num << '\t';
					
					if(count == numPerRow)
						{
							count = 0;
							outputFile << endl;
						}
				}
				
		}
	
	outputFile.close();
	
	return 0;
}
