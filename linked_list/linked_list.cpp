#include "linked_list.h"

// default constructor
template <typename T>
linked_list<T>::linked_list()
{
	this->head = this->last = count = 0;
}

// destructor calls pop until linked list is empty
template <typename T>
linked_list<T>::~linked_list()
{
	while (this->head != 0)
	{
		this->pop();
	}
}
// constructor with 1 element
template <typename T>
linked_list<T>::linked_list(T data)
{
	list_node<T> *temp = new list_node<T>;
	temp->data         = data;
	head = last        = temp;
	this->count        = 1;
}

// insert argument at last position of linked list
template <typename T>
void linked_list<T>::insert(T data)
{
	list_node<T> *temp = new list_node<T>;
	temp->data         = data;
	this->last->next   = this->last = temp;
	this->count++;
}

// insert argument 'data' after the node at index 'pos'
// zero based indexing
template <typename T>
void linked_list<T>::insert_after(T data, unsigned pos)
{
	if (pos > this->count || pos < 0)
		return;
	list_node<T> *temp = new list_node<T>;
	temp->data         = data;
	unsigned index     = 0;
	list_node<T> *cur  = head;
	while(cur != 0)
	{
		if (pos == index)
		{	
			temp->next = cur->next;
			cur->next  = temp;
			this->count++;
			return;
		}
		cur            = cur->next;
		index++;
	}
}

// returns and removes first element in the linked list
template <typename T>
T linked_list<T>::pop()
{
	this->count--;
	list_node<T> *temp = head;
	T ret              = this->head->data;
	this->head         = this->head->next;
	delete temp;
	return ret;
}

// returns and removes the element in the linked list after index 'pos'
// zero based indexing
template <typename T>
T linked_list<T>::pop_after(unsigned pos)
{
	if (pos >= this->count || pos < 0)
		return 0;
	list_node<T> *temp;
	T data;
	unsigned index     = 0;
	list_node<T> *cur  = head;
	while(cur != 0)
	{
		if (pos == index)
		{	
			temp       = cur->next;
			cur->next  = cur->next->next;
			data       = temp->data;
			delete temp;
			this->count--;
			return data;
		}
		cur            = cur->next;
		index++;
	}
	return 0;
}

// returns true if 'data' exists within the linked list, false otherwise
template <typename T>
bool linked_list<T>::exists(T data)
{
	if (head == 0)
		return false;
	list_node<T> *cur = this->head;
	while (cur != 0)
	{
		if (cur->data == data)
			return true;
		cur=cur->next;
	}
	return false;
}

// returns size of linked list
template <typename T>
unsigned long linked_list<T>::size()
{
	return this->count;
}

// returns first element of linked list
template <typename T>
T linked_list<T>::front()
{
	return this->head->data;
}

//returns last element of linked list
template <typename T>
T linked_list<T>::back()
{
	return this->last->data;
}

//returns true of linked list is empty, false otherwise
template <typename T>
bool linked_list<T>::empty()
{
	return count == 0? true:false;
}