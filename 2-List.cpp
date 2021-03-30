/*
Mason Manca and Sam Berkson
CPSC 122 Section 1
Project 10
Linked List functions
Dr.DePalma
Comments: We are not supposed to edit the source code, as we are supposed to treat it as unchangeable.
So, without argc, argv, graders will need to hardcode for find, and deleteItem
*/
#include <iostream>
using namespace std;

#include "List.h"

ListT::ListT()
{
 length = 0;
 head = NULL;
 tail = NULL;
}

ListT::~ListT()
{
 while(length > 0)
   DeleteItemH();
}

bool ListT::IsEmpty() const
{
 if(length == 0)
   return true;
 return false;
}

int ListT::GetLength() const
{
 return length;
}

void ListT::PutItemH(itemType newItem)
{ 
 node* cur = new node;
 if (length == 0)
   tail = cur;
 cur->item = newItem;
 cur->next = head;
 head = cur;
 length++;
 cur = NULL;
}

itemType ListT::GetItemH() const
{
 return head->item;
}

void ListT::DeleteItemH()
{
 node* cur;

 cur = head;
 head = cur->next;
 cur->next = NULL;
 length--;
 if (length == 0)
   tail = NULL;
 delete cur;
 cur = NULL;
}

void ListT::PutItemT(itemType newItem)
{
 node* cur = new node;
 cur->item = newItem;
 cur->next = NULL;
 if (length == 0 )
   head = cur;
 else
   tail->next = cur;
 tail = cur;
 length++;
 cur = NULL;
}

itemType ListT::GetItemT() const
{
 return tail->item;
}

void ListT::DeleteItemT()
{
 node* cur = tail;
 length--;
 delete cur;
 cur = NULL;
 tail = PtrTo();
 tail->next = NULL;
}

int ListT::DeleteItem(const itemType target)
{
  int index = 0;              
	node* temp = head;
  node* cur;

  if(target == 1)
    DeleteItemH();
  if(target == length)
    DeleteItemT();

	while(temp!=NULL){
    cur = temp->next;
		if(temp->item == target){         
			index++;
      temp->next = cur->next;
      delete cur;
      length--;
		}
		temp = temp->next;
  }
  return index;
  }

node* ListT::PtrTo()
{
 node* temp = new node;
 temp = head;
 while(temp->next != tail-> next)
  temp = temp->next;
 return temp;

}
int ListT::FindItem(const itemType target) const
  {
  int index = 0;              
	node* temp = head;

	while(temp!=NULL){
		if(temp->item == target){         
			index++;              
		}
		temp = temp->next;
  }
  return index;
  }
void ListT::Print() const
{
 node* cur = head;
 for(int i = 0; i < length; i++)
 {
   cout << cur->item << endl;
   cur = cur->next;
 }
}