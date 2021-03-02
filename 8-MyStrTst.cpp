#include "8-MyStr.h"
#include <iostream>
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
    */

 delete str2;
 return 0;  
}
}