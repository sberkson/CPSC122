/*
Name: Sam Berkson and Mason Manca
Class: CPSC 122, Section 1
Date Submitted: February 25, 2021
Assignment: N/A 
Description: header file for a doubly linked list with dummy notes at head and tail
*/

#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.cpp"

int main()
{
//PrintForward(); Test
/*
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintForward();

 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>(lst);

 lst1->PrintForward();
*/

//PrintBackwards() Test
/*
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintBackward();

 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>(lst);

 lst1->PrintBackward();
*/



//Delete() Test
/*
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintForward();
 cout << endl;
  lst->Delete(2);
  lst->PrintForward();

 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>;

for (int i = 1; i <= 10; i++)
   lst1->Insert(i,i);

 lst1->PrintForward();
  cout << endl;

  lst1->Delete(2);
  lst1->PrintForward();

*/

 //DeleteAll(); Test
 /*
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

  lst->PrintForward();
  cout << endl;
  cout << lst->DeleteAll(1) << endl;;
  cout << endl;
  lst->PrintForward();
  cout << endl;

ListD<int>* lst1 = new ListD<int>;

for (int i = 1; i <= 10; i++)
   lst1->Insert(i,i);

  lst1->PrintForward();
  cout << endl;
  cout << lst1->DeleteAll(2) << endl;;
  cout << endl;  
  lst1->PrintForward();
  */


/*
//Sort(); Test
 ListD<int>* lst = new ListD<int>;
 for (int i = 1; i <= 10; i++)
   lst->Insert(15-i,i);

 lst->PrintForward();
 lst->Sort();
 cout << endl;
 lst->PrintForward();

 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>;
for (int i = 1; i <= 10; i++)
   lst1->Insert(20-i,i);

lst1->PrintForward();
 lst1->Sort();
 cout << endl;
 lst1->PrintForward();
 */
return 0;
}