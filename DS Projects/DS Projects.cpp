#include <iostream>
#include "clsDblLinkedList.h";
using namespace std;

int main()
{
	clsDblLinkedList<int> List;
	List.InsertAtBeginning(9);

	clsNode<int> *N1 = List.Find(9);
	List.InsertAfter(N1, 2);
	List.InsertAtEnd(22);
	List.DeleteNode(N1);
	List.PrintNodesValues();
	List.Reverse();
}

