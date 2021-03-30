#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

   
ListD::ListD()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

ListD::ListD(ListD* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;

 //returns pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

ListD::~ListD()
{
    while (head != NULL) 
    {
        doubleNode* cur = head->next;
        delete head;
        head = cur;

    }
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

void ListD::PrintBackward()
{
    doubleNode*  cur = tail->prev;

    int i = 0;
    while (i < length)
    {
        cout << cur->item << endl;
        cur = cur->prev;
        i++;
    }
}

void ListD::Delete(int pos)
{
    doubleNode* cur = head;

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

void ListD::deleteFirst()
{
	doubleNode* cur = head;
	head = head->next;
	head->prev = NULL;
	delete(cur);
	length--;
}

void ListD::deleteLast()
{
    doubleNode* cur = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete(cur);
    length--;
} 


int ListD::DeleteAll(itemType target)
{
    int index = 0;
    doubleNode* cur = head;
    doubleNode* next;
    doubleNode* prev;

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

void ListD::Sort()
{
    doubleNode* temp = head;
  
    // Traverse the List
    while (temp) {
        doubleNode* cur = temp;
        doubleNode* r = temp->next;
  
        // Traverse the unsorted sublist
        while (r) {
            if (cur->item > r->item)
                cur = r;
  
            r = r->next;
        }
  
        // Swap Data
        int tempInt = temp->item;
        temp->item = cur->item;
        cur->item = tempInt;
        temp = temp->next;
    }
}
