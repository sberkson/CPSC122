#include <iostream>
#include "8-MyStr.h"
#include <cstring>
using namespace std;

MyString::MyString(char const* strIn)
{
  *str = *strIn; 
}

MyString::~MyString()
{
  delete []str;
}

void MyString::myDisplay()
{
  for(int i = 0; i < myStrlen(); i++)
  {
    cout << str[i];
  }
  cout << endl;
}

void myStrcpy(char const* strIn)
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
  int num = 0;

  for(int i = 0; i < myStrlen(); i++)
  {
    if(str[i] == strIn[0])
    {
      if(isSub(strIn, i))
      {
            
      }                
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
