#include <iostream>
#include "8-MyStr.h"
#include <cstring>
using namespace std;

MyString::MyString(char const* strIn)
{
    length = 0;
    strIn = NULL;
}

MyString::~MyString()
{
    delete []str;
}

void MyString::myDisplay()
{
  cout << *strIn << endl;
}

int MyString::myStrlen()
{
    while(strIn > 0)
    {
        
    }
}

bool MyString::isEqual(char const* strIn)
{

}

int MyString::find(char const strIn)
{

}

void MyString::concat(char const* strIn)
{

}

bool MyString::isSub(char const* strIn, int idx)
{

}
