/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 3/01/2021
Assignment: Project 7
Description: Program encrypts/decrypts text file using a transposition cipher.  Uses a 2d array to hold the key, switching columns and sorting to change between encryption and decryption. Takes in input from inFile and writes to outFile for encrypt, takes in input from outFile and writes to inFile for decryption mode.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ios>

using namespace std;
//Function Prototypes
void keyGen(string);
char transform(char, int[][2]);
void fileControl(string, string, string, int);
void fileOpen(fstream&, string, char);
void sortyBoi(int (&tempMatrix)[26][2]);
void closeFiles(fstream&, fstream&, fstream&);
//Main
int main(int argc, char* argv[]) 
{
  int mode = atoi(argv[1]);
  //Mode selector
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
//Generates key
void keyGen(string keyFileName)
{
  fstream keyFile;
  int pos = 0;
  int key[26];
  bool validate[26] = {false};

  fileOpen(keyFile, keyFileName, 'w');
  //Finds number that hasnt been found between 0-25 and adds to key[]
  while(pos < 26)
  {
    while(true)
    {
      int random = rand() % 26;
      
      if(!validate[random])
      {
        key[pos] = random;
        validate[random] = true;
        pos++;
        break;
      }
    }
  }
  //Writes key to keyFile
  for(int i = 0; i < 26; i++)
  {
    keyFile << i << " " << key[i] << endl;
  }
}
//Encrypt/Decrypt function
char transform(char ch, int encDec[26][2])
{
  if(ch == ' ')
  {
    return ' ';
  }
  if(islower(ch))
  {
    ch = toupper(ch);
  }

  ch -= 65;

  return encDec[ch][1] + 65;
}

void fileControl(string keyFileName, string inFileName, string outFileName, int mode)
{
  fstream keyFile, inFile, outFile;
  string input;
  int encDec[26][2];
  //Encrypt mode
  if(mode == 1)
  {
    fileOpen(keyFile, keyFileName, 'r');
    fileOpen(inFile, inFileName, 'r');
    fileOpen(outFile, outFileName, 'w');
    //Grabs key
    for(int i = 0; i < 26; i++)
    {
      keyFile >> encDec[i][0];
      keyFile.get();
      keyFile >> encDec[i][1];
      getline(keyFile, input);
    }
    //Grabs input from inFile using string i/o and encrypts, then writes to outFile
    while(inFile.peek() != EOF)
    {
      getline(inFile, input); 

      for(int i = 0; i < input.length(); i++)
      {
        outFile << transform(input[i], encDec); 
      }

      outFile << endl;
    }
  
  }
  //Decrypt mode
  if(mode == 2)
  {
    int tempMatrix[26][2]; //Used to switch sides of array

    fileOpen(keyFile, keyFileName, 'r');
    fileOpen(inFile, inFileName, 'w');
    fileOpen(outFile, outFileName, 'r');
    //Grabs key
    for(int i = 0; i < 26; i++)
    {
      keyFile >> encDec[i][0];
      keyFile.get();
      keyFile >> encDec[i][1];
      getline(keyFile, input);
    }
    //Fills temp matrix (encDec but flipped columns)
    for(int i = 0; i < 26; i++)
    {
      int temp = 1;
      for(int j = 0; j < 2; j++)
      {
        tempMatrix[i][j] = encDec[i][temp];
        temp--;
      }  
    }
    //Sorts the flipped encDec matrix
    sortyBoi(tempMatrix);
    //Grabs input from outFile using string i/o, then decrypts and writes back to inFile
    while(outFile.peek() != EOF)
    {
      getline(outFile, input); 

      for(int i = 0; i < input.length(); i++)
      {
        inFile << transform(input[i], tempMatrix); 
      }

      inFile << endl;
    }     
  }
  //Closes files
  closeFiles(keyFile, inFile, outFile);
}
//Opens files
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
//Sorting function
void sortyBoi(int (&tempMatrix)[26][2])
{
  //Loops through 2d array, sorting the first column and bringing the 2nd column along for the ride
  for(int i = 0; i < 26; i++)
    {
      bool swap = false;
      for(int j = 0; j < 25 - i; j++)
      {
        if(tempMatrix[j][0] > tempMatrix[j + 1][0])
        {
          int temp0 = tempMatrix[j][0];
          int temp1 = tempMatrix[j][1];

          tempMatrix[j][0] = tempMatrix[j+1][0];
          tempMatrix[j][1] = tempMatrix[j+1][1];
          tempMatrix[j+1][0] = temp0;
          tempMatrix[j+1][1] = temp1;          
          swap = true;
        }
      }
      if(!swap) //If no swap, break and repeat loop
      {
        break;
      }
    }
}
//Closes files
void closeFiles(fstream& keyFile, fstream& inFile, fstream& outFile)
{
  if(keyFile.is_open())
    {
      keyFile.close();
    }
  if(inFile.is_open())
    {
      inFile.close();
    }
  if(outFile.is_open())
    {
      outFile.close();
    }
}