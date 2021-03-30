/*
Mason Manca and Sam Berkson
CPSC 122 Section 1
Project 9
Linked List functions
Dr.DePalma
Comments: We are not supposed to edit the source code, as we are supposed to treat it as unchangeable.
So, without argc, argv, graders will need to hardcode for find, and deleteItem
*/
#include <iostream>
using namespace std;

#include "List.h"

int main()
{

//*****************************************************************************
/* 
//TEST FOR PUTITEMH
{
 //Use of a static list 
 List lst;
 for (int i = 0; i < 5; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;

 delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;
 return 0;
}
*/
//*****************************************************************************
//TEST FOR GETLENGTH
/*
//Test for listLength
List lst;
 for (int i = 0; i < 6; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 int listLength = lst.GetLength();
 cout << "List length: " << listLength -1;
 cout << endl;
 //Dynamic Test
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 listLength = lst1->GetLength();
 cout << "List length: " << listLength -1;
}
*/

//*****************************************************************************
/*
//TEST FOR IS EMPTY
//Test for isEmpty
List lst;
 for (int i = 0; i < 6; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 bool tempBool = false;
 tempBool = lst.IsEmpty();
if(!tempBool)
  cout << "Empty \n";
else
{
  cout << "Not Empty \n";
}
//Dynamic Test
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 tempBool = lst1->IsEmpty();
if(!tempBool)
  cout << "Empty \n";
else
{
  cout << "Not Empty \n";
}
*/
//*****************************************************************************
//TEST FOR GETITEM

/*
//Test for GetItem
List lst;
 for (int i = 0; i < 6; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
itemType tempHead = lst.GetItemH();
cout << "The current header of the list holds the value: " << tempHead << endl;
//Dynamic Test
List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 tempHead = lst1 ->GetItemH();
 cout << "The current header of the list holds the value: " << tempHead << endl;
*/

//*****************************************************************************
//TEST FOR DELETE ITEM H

/*
//Test for DeleteItemH
List lst;
 for (int i = 0; i < 6; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 lst.DeleteItemH();
cout << "Header has been deleted from list.\n";
//Dynamic Test
List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 lst1 ->DeleteItemH();
 cout << "Header has been deleted from list.\n";
*/

//*****************************************************************************
// TEST FOR FIND
/*
//Static Test
List lst;
 for (int i = 0; i < 6; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 int idx = lst.Find(10);
 if(idx == -1)
  cout << "Element not found in list" << endl;

 else
  {
    cout << "Element found at index: " << idx << endl;
  }

 //dynamic Test
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 idx = lst1->Find(23);
 if(idx == -1)
  cout << "Element not found in list" << endl;

 else
  {
    cout << "Element found at index: " << idx << endl;
  }
  
  */

//*****************************************************************************
//TEST FOR DELETE ITEM
//Will need to hardcode to test, since no command line input, and shouldn't ask for input from terminal
/*
 //static test for DeleteItem
 List lst;
 for (int i = 0; i < 6; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 lst.DeleteItem(3);
 lst.Print();
cout << endl;
//dynamic Test
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 lst1->DeleteItem(1);
 lst1->Print();

}
*/

