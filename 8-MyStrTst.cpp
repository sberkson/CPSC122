/*
Name: Sam Berkson
Class: CPSC 122-01
Date Submitted: 3/05/2021
Assignment: Project 8
Description: Runs tests for each of the public MyString member functions.
*/

#include "8-MyStr.h"
#include <iostream>
#include <ios>
using namespace std;

int main(int argc, char* argv[])
{ 
  MyString str1(argv[1]);
  MyString* str2 = new MyString(argv[1]);

/*
//Test of myDisplay
cout << "***************************************" << endl;
cout << "*****Test 1 myDisplay*****" << endl;
cout << "static test" << endl;
cout << "output should be the command line input" << endl;
str1.myDisplay();
cout << endl;
cout << "*****Test 2  myDisplay*****" << endl;
cout << "dynamic test" << endl;
cout << "output should be the command line input" << endl;
str2->myDisplay();
cout << endl;
cout << "***************************************" << endl;
//End Test of myDisplay

//Test of myStrcpy
cout << "***************************************" << endl;
cout << "*****Test 1 myStrcpy*****" << endl;
cout << "static test" << endl;
cout << "output should be the second string in command line input" << endl;
str1.myStrcpy(argv[2]);
cout << endl;
cout << "*****Test 2  myStrcpy*****" << endl;
cout << "dynamic test" << endl;
cout << "output should be the second string in command line input" << endl;
str2->myStrcpy(argv[2]);
cout << endl;
cout << "***************************************" << endl;
//End Test of myStrcpy

//Test of myStrlen
cout << "***************************************" << endl;
cout << "*****Test 1 myStrlen*****" << endl;
cout << "static test" << endl;
cout << "output should be the length of the command line input" << endl;
cout <<str1.myStrlen();
cout << endl;
cout << "*****Test 2  myStrlen*****" << endl;
cout << "dynamic test" << endl;
cout << "output should be the length of the command line input" << endl;
cout << str2->myStrlen();
cout << endl;
cout << "***************************************" << endl;
//End Test of myStrlen

//Test of isEqual
cout << "***************************************" << endl;
cout << "*****Test 1 isEqual*****" << endl;
cout << "static test" << endl;
cout << "output should be whether the two command line inputs are equal" << endl;
str1.isEqual(argv[2]);
cout << endl;
cout << "*****Test 2  isEqual*****" << endl;
cout << "dynamic test" << endl;
cout << "output should be whether the two command line inputs are equal" << endl;
str2->isEqual(argv[2]);
cout << endl;
cout << "***************************************" << endl;
//End Test of isEqual

//Test of find
cout << "***************************************" << endl;
cout << "*****Test 1 find*****" << endl;
cout << "static test" << endl;
cout << "output should be whether a substring of the second command line input exists in the first input, and the starting index if it does" << endl;
str1.find(argv[2]);
cout << endl;
cout << "*****Test 2  find*****" << endl;
cout << "dynamic test" << endl;
cout << "output should be whether a substring of the second command line input exists in the first input, and the starting index if it does" << endl;
str2->find(argv[2]);
cout << endl;
cout << "***************************************" << endl;
//End Test of find

//Test of concat
cout << "***************************************" << endl;
cout << "*****Test 1 concat*****" << endl;
cout << "static test" << endl;
cout << "output should be the concatination of two command line inputs" << endl;
str1.concat(argv[2]);
cout << endl;
cout << "*****Test 2  concat*****" << endl;
cout << "dynamic test" << endl;
cout << "output should be the concatination of two command line inputs" << endl;
str2->concat(argv[2]);
cout << endl;
cout << "***************************************" << endl;
//End Test of concat
*/
  delete str2;

  return 0;  
}
