#pragma once
#include <iostream>
#include "clsNode.h";
using namespace std;
template <class T>

class clsDblLinkedList : protected clsNode<T>
{
private:
	clsNode<T>* head = NULL;
	int _size;
public:

	void InsertAtBeginning(T value)
	{
		clsNode<T>* new_node = new clsNode<T>();
		new_node->value = value;
		new_node->next = head;
		new_node->prev = NULL;
		_size++;
		head = new_node;
	}
	clsNode<T> *Find(T value)
	{
		clsNode<T>* current = head;

		while (current != NULL) {
			
			if (current->value == value)
				return current;

			current = current->next;
		}
		delete current;
		return NULL;
	}
	void InsertAfter(clsNode<T>* current, T value)
	{
		clsNode<T>* new_node = new clsNode<T>();
		new_node->value = value;
		new_node->next = current->next;
		new_node->prev = current;
		if (current->next != NULL)
			current->next->prev = new_node;

		current->next = new_node;
		_size++;
	}

	void InsertAtEnd(T value)
	{
		clsNode<T>* new_node = new clsNode<T>();
		if (head == NULL)
		{
			new_node->prev = NULL;
			head = new_node;
		}
		else
		{
			clsNode<T>* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			new_node->value = value;
			new_node->next = NULL;
			new_node->prev = current;
			current->next = new_node;
		}
		_size++;

	}

	void DeleteNode(clsNode<T>* &node)
	{
		if (head == node)
			head = node->next;
		if (head == NULL || node == NULL)
			return;
		if (node->next != NULL)
			node->next->prev = node->prev;
		if (node->prev != NULL)
			node->prev->next = node->next;
		_size--;
		delete node;
	}
	void DeleteFirstNode()
	{
		clsNode<T>* temp = head;
		if (head == NULL)
			return;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		delete temp;
		_size--;
	}
	void DeleteLastNode()
	{
		clsNode<T>* temp = head;
		if (head == NULL)
			return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_size--;
			return;
		}

		clsNode<T>* current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		clsNode<T>* temp = current->next;
		current->next = NULL;
		delete temp;
		_size--;

	}
	void PrintNodesValues()
	{
		clsNode<T>* current = head;

		while (current != NULL) {
			cout << current->value << endl;
			current = current->next;
		}
		delete current;
		// do not move head
	}
	void Size()
	{
		cout << _size;
	}

	bool IsEmpty()
	{
		return (_size == 0 ? true : false);
	}

	void Clear()
	{
		while (_size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		clsNode<T>* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		clsNode<T>* last = current;
		while (last != NULL) {
			cout << last->value << endl;
			last = last->prev;
		}
		delete last;
		delete current;

	}
};	

