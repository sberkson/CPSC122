#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int keyGen();
char encrypt (char, int);
char decrypt(char, int);
void fileOpen(fstream&, string, char);

int keyGen()
	{
		int key = rand() % 26;
		return key;
	}

char encrypt(char ch, int key)
	{
		char encryptedChar = ch + key;
		return encryptedChar;
	}

char decrypt(char ch, int key)
	{
		char decryptedChar = ch - key;
		return decryptedChar;
	}

void fileOpen(fstream&, string name, char mode)
	{
		string fileType;

 		if (mode == 'r')
 			{
  			fileType = "input";
  		}
 		if (mode == 'w')
 			{
  			fileType = "output";
  		}

 		if (mode == 'r')
 			{
  			file.open(name, ios::in);  //available thorugh fstream
  		}
		if (mode == 'w')
			{
  			file.open(name, ios::out);  //available through fstream;
  		}
		if (file.fail()) //error condition 
 			{
  			cout << "Error opening " << fileType << " file" << endl; 
  			exit(EXIT_FAILURE);
 			}
 	} 

int main()
	{
		return 0;
	}
