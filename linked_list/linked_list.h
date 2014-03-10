#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 *  Singly templated linked list
 */

template <typename T>
class list_node
{
	public:
		T data;
		list_node *next;
};

template <typename T>
class linked_list
{
	private:
		list_node<T>  *head;
		list_node<T>  *last;
		unsigned long count;
	public:
		linked_list();
		~linked_list();
		linked_list(T data);

		void insert(T data);
		void insert_after(T data, unsigned pos);
		T pop();
		T pop_after(unsigned pos);
		bool exists(T data);
		unsigned long size();
		T front();
		T back();
		bool empty();
};
#endif