#include "8-MyStr.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  MyString str1(argv[1]);
  MyString* str2 = new MyString(argv[1]);

  
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
  cout << "output should be the command line input" << endl;
  str1.myStrcpy();
  cout << endl;
  cout << "*****Test 2  myStrcpy*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of myStrcpy

  //Test of myStrlen
  cout << "***************************************" << endl;
  cout << "*****Test 1 myStrlen*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  myStrlen*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of myStrlen

  //Test of isEqual
  cout << "***************************************" << endl;
  cout << "*****Test 1 isEqual*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  isEqual*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of isEqual

  //Test of find
   cout << "***************************************" << endl;
  cout << "*****Test 1 find*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2 find*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of find

  //Test of concat
   cout << "***************************************" << endl;
  cout << "*****Test 1 concat*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  concat*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of concat

  //Test of isSub
   cout << "***************************************" << endl;
  cout << "*****Test 1 isSub*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  isSub*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of isSub
 
  delete str2;

  return 0;  
}
