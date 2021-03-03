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

int MyString::myStrlen()
{
    return (sizeof(str) / sizeof(str[0]));
}

bool MyString::isEqual(char const* strIn)
{
   bool equality = true;
   if(((sizeof(str) / sizeof(str[0])) != (sizeof(strIn) / sizeof(strIn[0]))))
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

int MyString::find(char const strIn)
{
    int num = 0;

    
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
