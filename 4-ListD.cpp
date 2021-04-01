/*
Name: Sam Berkson and Mason Manca
Class: CPSC 122, Section 1
Date Submitted: March 31, 2021
Assignment: Project 11
Description: function definition for a templated doubly linked list
*/

#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"
 
template <typename T>
ListD<T>::ListD()
{
  length = 0;

  //create dummy nodes;
  head = new doubleNode<T>;
  tail = new doubleNode<T>;

  //set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  //set values for tail dummy node;
  tail->prev = head; 
  tail->item = INT_MAX;
  tail->next = NULL;
}

template <typename T>
ListD<T>::ListD(ListD* lst)
{
  length = 0; 

  //create dummy nodes;
  head = new doubleNode<T>;
  tail = new doubleNode<T>;

  //set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  //set values for tail dummy node;
  tail->prev = head; 
  tail->item = INT_MAX;
  tail->next = NULL;

  //returns pointer to the first node, which is what we want here
  doubleNode<T>* cur = lst->FindPosition(2);
  for (int i = 1; i <= lst->length; i++)
  {
    Insert(cur->item,i);
    cur = cur->next;
  }
}

template <typename T>
ListD<T>::~ListD()
{
  while (head != NULL) 
  {
    doubleNode<T>* cur = head->next;
    delete head;
    head = cur;
  }
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
  //Inserting at the tail is a special case.  It can be made much more efficient than
  //this.
  doubleNode<T>* cur = head;
  int i = 0;  //begin at the dummy node
  while (i < pos - 1)
  {
    cur = cur->next;
    i++;
  }
  return cur;
} 
  
template <typename T>
void ListD<T>::Insert(T item, int pos)
{
  //new node goes between these two nodes
  doubleNode<T>* insertPtA = FindPosition(pos);  
  doubleNode<T>* insertPtB = insertPtA->next; 

  //create new node and set its values
  doubleNode<T>* tmp = new doubleNode<T>; 
  tmp->prev = insertPtA;
  tmp->item = item;
  tmp->next = insertPtB;

  //set pointers for nodes before and after the insertion point
  insertPtA->next = tmp;
  insertPtB->prev = tmp;

  length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
  doubleNode<T>* cur = head->next;

  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->next;
    i++;
  }
}

template <typename T>
void ListD<T>::PrintBackward()
{
  doubleNode<T>* cur = tail->prev;

  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->prev;
    i++;
  }
}

template <typename T>
void ListD<T>::Delete(int pos)
{
  doubleNode<T>* cur = head;

  for (int i = 0; i < pos&& cur  != NULL; i++)
  {
    cur = cur->next;
  }
  if (pos == 0)
    deleteFirst();

  else if (cur == tail)
    deleteLast();

  else if (cur != NULL)
  {
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete(cur);
    length--;
  }
}

template <typename T>
void ListD<T>::deleteFirst()
{
	doubleNode<T>* cur = head;
	head = head->next;
	head->prev = NULL;
	delete(cur);
	length--;
}

template <typename T>
void ListD<T>::deleteLast()
{
  doubleNode<T>* cur = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete(cur);
  length--;
} 

template <typename T>
int ListD<T>::DeleteAll(T target)
{
  int index = 0;
  doubleNode<T>* cur = head;
  doubleNode<T>* next;
  doubleNode<T>* prev;

  for(int i = 0; i < length; i++)
  {
    next = cur->next;
    prev = cur->prev; 

    if(cur->item == target)
    {
      index++;
      prev->next = cur->next;
      next->prev = cur->prev;
      delete cur;
      length--;
    } 
    cur = next;    
  }
  return index;
}

template <typename T>
void ListD<T>::Sort()
{
  doubleNode<T>* temp = head;

  // Traverse the List
  while (temp) 
  {
    doubleNode<T>* cur = temp;
    doubleNode<T>* r = temp->next;

    // Traverse the unsorted sublist
    while (r) 
    {
      if (cur->item > r->item)
        cur = r

      r = r->next;
    }

    // Swap Data
    int tempInt = temp->item;
    temp->item = cur->item;
    cur->item = tempInt;
    temp = temp->next;
  }
}
