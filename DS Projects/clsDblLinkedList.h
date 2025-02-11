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
		new_node->value = value;
		new_node->next = NULL;

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
			current->next = new_node;
			new_node->prev = current;
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

	int Size()
	{
		return _size;
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
		clsNode<T>* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->next = current->prev;
			current->prev = temp;
			current = current->prev;
		}
		if (temp != nullptr)
		{
			head = temp->prev; 
		}
	}

	clsNode<T>* GetNode(int Index)
	{
		int Counter = 0;

		if (Index > _size - 1 || Index < 0)
			return NULL;

		clsNode<T>* Current = head;
		while (Current != NULL && (Current->next != NULL)) {

			if (Counter == Index)
				break;

			Current = Current->next;
			Counter++;

		}

		return Current;
	}
	
	T GetItem(int Index)
	{
		return GetNode(Index) == NULL ? NULL : GetNode(Index)->value;
	}

	bool UpdateItem(int Index, T value)
	{
		clsNode<T>* Node = GetNode(Index);
		if (Node == NULL)
		{
			return false;
		}
		else
		{
			Node->value = value;
			return true;
		}
	}
	
	bool InsertAfter(int Index, T value)
	{
		clsNode<T>* new_node = new clsNode<T>();
		
		clsNode<T>* current = GetNode(Index);
		if (current == NULL)
		{
			return false;
		}
		else
		{
			InsertAfter(current, value);
			return true;
		}
	}
	void Extrans(clsNode<T>* node)
	{
		clsNode<T>* current = node;
		clsNode<T>* prev = current->prev;
		clsNode<T>* end = (clsNode<T>*)((uintptr_t)(current->next) ^ ( (uintptr_t)current ^ (uintptr_t)current)  );
		cout << end->value;
	}
};	

