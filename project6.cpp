/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 2/13/2021
Assignment: Project 6
Description: Program encrypts/decrypts text file using an Affine Cipher key.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ios>

using namespace std;
//Function Prototypes
int findInverse(int);
void keyGen(string);
char encrypt(char, int, int);
char decrypt(char, int, int, int[]);
void fileControl(string, string, string, int);
void fileOpen(fstream&, string, char);
//Main
int main(int argc, char* argv[])
{
  int mode = atoi(argv[1]);

  if(mode == 0)
    {
      keyGen(argv[2]);
    }
  if(mode == 1 || mode == 2)
    {
      fileControl(argv[2], argv[3], argv[4], mode);
    }
  return 0;
}
//Finds multiplicative inverses of alphabet
int findInverse(int alpha)
{
  int inverse = 0;

  for(int i = 0; i < 26; i++)
    {
      if((alpha * i) % 26 == 1)
        {
          return i;
        }
    }
  return 0;
}
//Generates and writes to Keyfile the alpha and beta values for key
void keyGen(string keyFileName)
{
  srand(time(NULL));
  fstream keyFile;
  int alphaChoices[8] = {1,3,5,7,11,17,19,25};
  int alpha = alphaChoices[rand() % 8];
  int beta = (rand() % 26) + 1;

  fileOpen(keyFile, keyFileName, 'w');

  keyFile << alpha << endl << beta;
}
//Encrypts character
char encrypt(char ch, int alpha, int beta)
{
  if(ch == ' ')
    {
      return ' ';
    }

  if(islower(ch))
    { 
      ch -= 32;
    }
  cout << ch;
  ch = (char)((((alpha * (ch - 'A')) + beta) % 26) + 'A');

  return ch;
}
//Decrypts character
char decrypt(char ch, int alpha, int beta, int MI[])
{
  int inverse = MI[alpha];

  if(ch == ' ')
    {
      return ' ';
    }

  ch = (char)(((inverse * ((ch + 'A' - beta)) % 26)) + 'A');

  return ch;
}
//Controls file operations
void fileControl(string keyFileName, string inFileName, string outFileName, int mode)
{
  fstream keyFile, inFile, outFile;
  string input;
  int alpha, beta;
  int MI[26];
  //Base opening and assigning of keyfile, alpha, and beta values
  fileOpen(keyFile, keyFileName, 'r');
  keyFile >> alpha;
  getline(keyFile, input);
  keyFile >> beta;
  //Encrypt mode
  if(mode == 1)
    {
      //Opens files
      fileOpen(inFile, inFileName, 'r');
      fileOpen(outFile, outFileName, 'w');

      while(inFile.peek() != EOF)
        {
          getline(inFile, input); //Reads in line

          for(int i = 0; i < input.length(); i++)
            {
              outFile << encrypt(input[i], alpha, beta); //Writes encrypted character to outFile
            }

          outFile << endl;
        }
    }
  if(mode == 2)
    {
      for(int i = 0; i < 26; i++)
        {
          MI[i] = findInverse(alpha); //Fills MI array with multiplicative inverses
        }
      //Opens files
      fileOpen(outFile, outFileName, 'r');
      fileOpen(inFile, inFileName, 'w');

      while(outFile.peek() != EOF)
        {
          getline(outFile, input); //Reads in line

          for(int i = 0; i < input.length(); i++)
            {
              inFile << decrypt(input[i], alpha, beta, MI); //Writes decrypted character to inFile
            }

          inFile << endl;
        }
    }
}
//Open file function
void fileOpen(fstream& file, string name, char mode)
{
  string fileType;

  if(mode == 'r')
    {
      fileType = "input";
    }
  if(mode == 'w')
    {
      fileType = "output";
    }

  if(mode == 'r')
    {
      file.open(name, ios::in);  
    }
  if(mode == 'w')
    {
      file.open(name, ios::out);  
    }
  if(file.fail()) //error condition 
    {
      cout << "Error opening " << fileType << " file" << endl; 
      exit(EXIT_FAILURE);
    }
}
