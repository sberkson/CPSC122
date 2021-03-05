#include <iostream>
#include "8-MyStr.h"
#include <cstring>
using namespace std;

MyString::MyString(char const* strIn)
{
  int i = 0;

  while(strIn[i] != '\0')
  {
    length = i;
    i++;
  }
  
  str = new char[length + 1];
  i = 0 ;

  while(i < (length + 1))
  {
    str[i] = strIn[i];
    i++;
  }
  
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
  str = new char[myStrlen(strIn) + 1];

  int i = 0;
  
  while(strIn[i] != '\0')
  {
    str[i] = strIn[i];
    i++;
  }
  cout << str;
}

int MyString::myStrlen()
{
  int i;

  while(str[i] != '\0')
  {
    i++;
  }
  return i;
}

int MyString::myStrlen(char const* strIn)
{
  int i = 0;

  while(strIn[i] != '\0')
  {
    i++;
  }
  return i;
}

bool MyString::isEqual(char const* strIn)
{
  int i = 0;
  bool equality = true;
  if(myStrlen() != myStrlen(strIn))
  {
    cout << "Not Equal" << endl;
    return false;
  }

  while(strIn[i] != '\0')
  {
    if(strIn[i] != str[i])
    {
      cout << "Not Equal" << endl;
      return false;
    }
    i++;
  } 
  equality = true;
  if(equality)
    cout << "Equal";
  else
    cout << "Not equal";

  return equality;
}

int MyString::find(char const* strIn)
{
  for(int i = 0; i < myStrlen(); i++)
  {
  
    if(str[i] == strIn[0])
    {
      for(int j = 0; j < myStrlen(strIn); j++)
      {
        if(str[i + j] != strIn[j])
        {
         break;
        }
        cout << j << ' ' << myStrlen(strIn) << endl;
        if(j+1 == (myStrlen(strIn) - 1))
        {
          cout << "Substring found starting at index " << i;
          return i;
        }
      }
    }
  }
  cout << "Substring not found";
  return -1;
}

void MyString::concat(char const* strIn)
{
  str = strcat(str, strIn);
  cout << str << endl;
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
