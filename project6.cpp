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
}
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
void fileControl(string keyFileName, string inFileName, string outFileName, int mode)
{
  fstream keyFile, inFile, outFile;
  string input;
  int alpha, beta;
  int MI[26];

  fileOpen(keyFile, keyFileName, 'r');
  keyFile >> alpha;
  getline(keyFile, input);
  keyFile >> beta;

  if(mode == 1)
    {
      fileOpen(inFile, inFileName, 'r');
      fileOpen(outFile, outFileName, 'w');

      while(inFile.peek() != EOF)
        {
          getline(inFile, input);

          for(int i = 0; i < input.length(); i++)
            {
              outFile << encrypt(input[i], alpha, beta);
            }

          outFile << endl;
        }
    }
  if(mode == 2)
    {
      for(int i = 0; i < 26; i++)
        {
          MI[i] = findInverse(alpha);
        }

      fileOpen(outFile, outFileName, 'r');
      fileOpen(inFile, inFileName, 'w');

      while(outFile.peek() != EOF)
        {
          getline(outFile, input);

          for(int i = 0; i < input.length(); i++)
            {
              inFile << decrypt(input[i], alpha, beta, MI);
            }

          inFile << endl;
        }
    }
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
