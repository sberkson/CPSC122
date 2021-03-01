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
void sort(int&);
void closeFiles(fstream&, fstream&, fstream&);
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

void keyGen(string keyFileName)
{
  fstream keyFile;
  int pos = 0;
  int key[26];
  bool validate[26] = {false};

  fileOpen(keyFile, keyFileName, 'w');

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
  
  for(int i = 0; i < 26; i++)
  {
    keyFile << i << " " << key[i] << endl;
  }
}

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

  if(mode == 1)
  {
    fileOpen(keyFile, keyFileName, 'r');
    fileOpen(inFile, inFileName, 'r');
    fileOpen(outFile, outFileName, 'w');
    
    for(int i = 0; i < 26; i++)
    {
      keyFile >> encDec[i][0];
      keyFile.get();
      keyFile >> encDec[i][1];
      getline(keyFile, input);
    }

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
  if(mode == 2)
  {
    int tempMatrix[26][2];
    
    fileOpen(keyFile, keyFileName, 'r');
    fileOpen(inFile, inFileName, 'w');
    fileOpen(outFile, outFileName, 'r');

    for(int i = 0; i < 26; i++)
    {
      keyFile >> encDec[i][0];
      keyFile.get();
      keyFile >> encDec[i][1];
      getline(keyFile, input);
    }

    for(int i = 0; i < 2; i++)
    {
      int temp = 1;
      for(int j = 0; j < 26; j++)
      {
        tempMatrix[j][i] = encDec[j][temp];
      }
    }

    sort(tempMatrix);

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
  closeFiles(keyFile, inFile, outFile);
}

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
void sort(int& tempMatrix)
{
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
      if(!swap)
      {
        break;
      }
    }
}
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