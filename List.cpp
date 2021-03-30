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

List::List()
{
  length = 0;
  head = NULL;
}

List::~List()
{
  while(length > 0)
  {
    DeleteItemH();
  }
}

bool List::IsEmpty() const
{
  int tempLength = GetLength();
  cout << tempLength << endl;
  if(!(tempLength - 1))
  {
    return false;
  }
 return true;
}

int List::GetLength() const
{
  node* temp = new node;
  temp -> next = head;
  int length = 0;
  while(temp != NULL)
  {
    ++length;
    temp = temp -> next;
    
  }

 return length;
}

void List::PutItemH(const itemType newItem)
{
  node* temp = new node;
  temp -> item = newItem;
  temp -> next = head;

  head = temp;
  length += 1;
  temp = NULL;
}

itemType List::GetItemH() const
{
  return head -> item;
}

void List::DeleteItemH()
{
  node* current;

  current = head;
  head = current -> next;
  current -> next = NULL;
  length--;

  delete current;
  current = NULL;
}
	
void List::Print() const
{
  node* current = head;

  while(current != NULL)
  {
    cout << current -> item << endl;
    current = current -> next;
  }
}

int List::Find(const itemType item) const
{
	int index = 0;              
	node* temp = head;

	while(temp!=NULL){
		if(temp->item == item){         
			return index;               
		}
		temp = temp->next;
		index++;
	}   
 return -1;
}

void List::DeleteItem(const int pos)
{
  node *temp = head;
    if(pos == 0)
    {
        head = temp->next;
        free(temp);
    }
    else{
        node* temp1 = head;
        for(int i = 0;i < pos;i++)
        {
            temp1 = temp1->next;
        }
        while(temp->next != temp1)
        {
            temp= temp->next;
        }
        temp->next=temp1->next;
        free(temp1);
}
}