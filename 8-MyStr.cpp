/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 3/05/21
Assignment: Project 8
Description: File contains member functions of MyString class, performing different roles to operate on a char* array.
*/

#include <iostream>
#include "8-MyStr.h"
#include <cstring>
using namespace std;

MyString::MyString(char const* strIn) //Constructor for MyString objects
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

MyString::~MyString() //Destructor
{
  delete []str;
}

void MyString::myDisplay() //Prints str object
{
  cout << str << endl;
}

void MyString::myStrcpy(char const* strIn) //Copies input string to str object
{
  str = new char[myStrlen(strIn) + 1];

  int i = 0;
  
  while(strIn[i] != '\0') //Loops through until null character found
  {
    str[i] = strIn[i];
    i++;
  }
  cout << str;
}

int MyString::myStrlen() //Returns length of str object
{
  int i;

  while(str[i] != '\0') //Loops through until null character found
  {
    i++;
  }
  return i;
}

int MyString::myStrlen(char const* strIn) //Returns length of input string
{
  int i = 0;

  while(strIn[i] != '\0') //Loops through until null character found
  {
    i++;
  }
  return i;
}

bool MyString::isEqual(char const* strIn) //Returns true if input string and str are equal
{
  cout << endl; //For some reason, this only works when i print something so :)
  int i = 0;
  bool equality = true;
  if(myStrlen() != myStrlen(strIn)) //False if not same size
  {
    cout << "Not Equal" << endl;
    return false;
  }

  while(strIn[i] != '\0')
  {
    if(strIn[i] != str[i]) // Returns false if unequal character found
    {
      cout << "Not Equal" << endl;
      return false;
    }
    i++;
  } 
  equality = true; //Prints equality value
  if(equality)
    cout << "Equal";
  else
    cout << "Not equal";

  return equality; //Returns true if made this far

}

int MyString::find(char const* strIn) //Finds a substring of strIn in str, and returns starting index of substring if it exists
{
  for(int i = 0; i < myStrlen(); i++) //Loops through str
  {
    if(str[i] == strIn[0])
    {
      for(int j = 0; j < myStrlen(strIn); j++) //Loops through strIn
      {
        if(str[i + j] != strIn[j])
        {
         break; //Breaks if unequal
        }
        if(j+1 == (myStrlen(strIn) - 1)) //If condition met, substring exists and returns index
        {
          cout << "Substring found starting at index " << i;
          return i;
        }
      }
    }
  }
  cout << "Substring not found"; //Returns -1 if substring not found
  return -1;
}

void MyString::concat(char const* strIn)
{
  char* temp = new char[myStrlen() + 1]; //Made to hold str values
  temp = str;

  str = new char[myStrlen() + myStrlen(strIn) + 1]; //Re initializes str to size of str + strIn + 1
  int i = 0;
  while(temp[i] != '\0')
  {
    str[i] = temp[i];
    i++; //Moves in original str values into new str
  }
  int j = 0;
  while(strIn[i] != '\0') //Moves in strIn values into str;
  {
    str[i] = strIn[j];
    i++;
    j++;
  }
  cout << str << endl; //Prints new str
}

bool MyString::isSub(char const* strIn, int idx) //Checks to see if a substring exists
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
