/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 2/8/21
Assignment: Project 5
Description: Program operates on 3 modes: 0 = generate key, 1 = encrypt, 2 = decrypt. Program can generate a number between 0-25 to serve as encryption cipher key.  Program can read in a plain text file, encrypts characters using a caeser cipher, stores the key in a separate text file, and then outputs the encrypted characters to a cipher text file.  Program can decrypt the cipher text file and then write decrypted text to a separate text file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;
//Function Prototypes
void fileOpen(fstream&, string, int);
void keyGen(fstream& keyFile);
int generateKey();
char encrypt (char, int);
char decrypt(char, int);
void keyGenWrite(char* argv, fstream& keyFile);
void encryptFile(char* argv, fstream& keyFile, fstream& PTfile, fstream& CTfile);
void decryptFile(char* argv, fstream& keyFile, fstream& CTfile, fstream& PTEfile);
//Function opens file for either reading or writing
void fileOpen(fstream& file, string name, char mode)
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
  			file.open(name, ios::in);  
  		}
		if (mode == 'w')
			{
  			file.open(name, ios::out);  
  		}
		if (file.fail()) //error condition 
 			{
  			cout << "Error opening " << fileType << " file" << endl; 
  			exit(EXIT_FAILURE);
 			}
 	} 
//Generates and returns random number 0-25
int generateKey()
	{
		int key = rand() % 26;
		return key;
	}
//Writes cipher key to keyFile
void keyGen(char* argv[], fstream& keyFile)
	{
		string keyFileName = argv[2];
		fileOpen(keyFile, keyFileName, 'w');
		keyFile << generateKey();
	}
//Encrypt file option, reads from PTfile and writes encrypted text to CTfile
void encryptFile(char* argv[], fstream& keyFile, fstream& PTfile, fstream& CTfile)
	{
		//Variable initializations
		int key = 5;
		string input = "";
		string keyFileName = argv[2];
		string ptFileName = argv[3];
		string ctFileName = argv[4];
		//Opens files
		fileOpen(keyFile, keyFileName, 'r');
		fileOpen(PTfile, ptFileName, 'r');
		fileOpen(CTfile, ctFileName, 'w');
		keyFile >> key;
		//Loops through plain text
		while(PTfile.peek() != EOF)
			{
				getline(PTfile, input);
				
				for(int i = 0; i < input.length(); i++)
					{
						CTfile << encrypt(input[i], key); //Encrypts each line
					}
				CTfile << endl;
			}
	}
//Decrypt file option, reads from CTfile and writes decrypted text to PTEfile
void decryptFile(char* argv[], fstream& keyFile, fstream& CTfile, fstream& PTEfile)
	{
		//Variable initializations
		int key = 5;
		string input = "";
		string keyFileName = argv[2];
		string ctFileName = argv[3];
		string pteFileName = argv[4];
		//Opens files and reads in key
		fileOpen(keyFile, keyFileName, 'r');
		fileOpen(CTfile, ctFileName, 'r');
		fileOpen(PTEfile, pteFileName, 'w');	
		keyFile >> key;
		//Loops through encrypted text
		while(CTfile.peek() != EOF)
			{
				getline(CTfile, input);
				
				for(int i = 0; i < input.length(); i++)
					{
						PTEfile << decrypt(input[i], key); //Decrypts each line
					}
				PTEfile << endl;
			}		
		
	}
//Encrypts character based on the cipher key, returns encrypted character
char encrypt(char ch, int key)
	{
		if(ch == ' ')
			{
				return ' ';
			}
		if(islower(ch)) // Converts to upper case
			{
				toupper(ch);
			}
		ch += key;
		
		if(ch > 90) //Recurses through alphabet if limit reached
			{
				ch -= 26;
			}
		return ch;
	}
//Decrypted character based on the cipher key, returns decrypted character
char decrypt(char ch, int key)
	{
		if(ch == ' ')
			{
				return ' ';
			}
		
		ch -= key;
	
		if(ch < 65) //Resurses through alphabet if limit reached
			{
				ch += 26;
			}
		
		return ch;
	}

int main(int argc, char* argv[])
	{
		//Selects mode and declares file names
		int mode = atoi(argv[1]);
		fstream keyFile, PTfile, CTfile, PTEfile;
		//Command line input protection
		if(argc < 3 || argc > 5)
			{
				cout << "Incorrect number of arguments. Exiting program" << endl;
				exit(EXIT_FAILURE);
			}
		//Generate key mode
		if(mode == 0)
			{
				keyGen(argv, keyFile);
			} 
		//Encrypt mode
		if(mode == 1)
			{
				encryptFile(argv, keyFile, PTfile, CTfile);
			}
		//Decrypt mode
		if(mode == 2)
			{
				decryptFile(argv, keyFile, CTfile, PTEfile);
			}
		
		return 0;
	}
