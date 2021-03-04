#include <iostream>
#include "8-MyStr.h"
#include <cstring>
using namespace std;

MyString::MyString(char const* strIn)
{
  str = new char[myStrlen(strIn) + 1];
  strcpy(str, strIn);
  length = 0;
}

MyString::~MyString()
{
  delete []str;
}

void MyString::myDisplay()
{
  cout << str << endl;
}

void MyString::myStrcpy(char const* strIn)
{
  
}

int MyString::myStrlen()
{
  int i;

  for(int i = 0; str[i]; i++)
  {
    return i;
  }
  return -1;
}

int MyString::myStrlen(char const* strIn)
{
  int i;

  for(int i = 0; strIn[i]; i++)
  {
    return i;
  }
  length = i;
  return -1;
}

bool MyString::isEqual(char const* strIn)
{
  bool equality = true;
  if(myStrlen() != myStrlen(strIn))
  {
    return false;
  }

  for(int i = 0; i < myStrlen(); i++)
  {
    if(str[i] != strIn[i])
    {
      equality = false;
    }
  } 
  
  return equality;
}

int MyString::find(char const* strIn)
{
  for(int i = 0; i <= myStrlen() - myStrlen(strIn); i++)
  {
    int j;

    for(j = 0; j < myStrlen(strIn); j++)
    {
      if(str[i + j] != strIn[j])
      {
        break;
      }
    }
    
    if(j == myStrlen(strIn))
    {
      return i;
    }
  }

  return -1;
}

void MyString::concat(char const* strIn)
{
  str = strcat(str, strIn);
}

bool MyString::isSub(char const* strIn, int idx)
{
  bool equality = true;

  for(int i = idx + 1; i < myStrlen(); i++)
  {
    if(str[i] != strIn[i])
    {
      equality = false;
    }
  }

  return equality;
}
