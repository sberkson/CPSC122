#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ios>

using namespace std;

int keyGen();
char encrypt (char, int);
char decrypt(char, int);
void fileOpen(fstream&, string, int);

int keyGen(fstream& keyFile)
	{
		srand(time(NULL));
		int key = rand() % 26;
		keyFile << key;
		return key;
	}

char encrypt(char ch, int key)
	{
		if(ch == ' ')
			{
				return ' ';
			}
		
		ch += key;
		
		if(ch > 90)
			{
				ch -= 26;
			}
		return ch;
	}

char decrypt(char ch, int key)
	{
		if(ch == ' ')
			{
				return ' ';
			}
		
		ch -= key;
	
		if(ch < 65)
			{
				ch += 26;
			}
		
		return ch;
	}

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

int main(int argc, char* argv[])
	{
		int mode = atoi(argv[1]);
		int key;
		string input;
		string keyFileName = argv[2];
		string ptFileName, ctFileName = "";
		fstream keyFile, ptFile, ctFile;

		if(argc < 3 || argc > 5)
			{
				cout << "Incorrect number of arguments. Exiting program" << endl;
				exit(EXIT_FAILURE);
			}
		if(mode == 0)
			{
				fileOpen(keyFile, keyFileName, 'w');
				key = keyGen(keyFile);
			} 
		if(mode == 1)
			{
				ptFileName = argv[3];
				ctFileName = argv[4];

				fileOpen(keyFile, keyFileName, 'r');
				fileOpen(ptFile, ptFileName, 'r');
				fileOpen(ctFile, ctFileName, 'w');
				
				keyFile >> key;	
				getline(ptFile, input);
				
				for(int i = 0; i < input.length(); i++)
					{
						ctFile << encrypt(input[i], key);
					}
			}
		if(mode == 2)
			{
				ctFileName = argv[3];
				ptFileName = argv[4];
				
				fileOpen(keyFile, keyFileName, 'r');
				fileOpen(ctFile, ctFileName, 'r');
				fileOpen(ptFile, ptFileName, 'w');
				
				keyFile >> key;
				getline(ctFile, input);
				
				for(int i = 0; i < input.length(); i++)
					{
						ptFile << decrypt(input[i], key);
					}
			}
					
		return 0;
	}
