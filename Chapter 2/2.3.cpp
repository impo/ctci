/*
 * PROBLEM:
 * Implement an algorithm to delete a node in the middle (i.e., any node but the first
 * and last node, not necessarily the exact middle) of a singly linked list, given only
 * access to that node.
 *
 * IMPLEMENTATION:
 * Copy the data from the next node into the node of choice, then delete that node.
 *
 * TIME COMPLEXITY:
 * O(1), as we perform 3 assignments and one deletion.
 *
 * SPACE COMPLEXITY:
 * O(1), as we do not use any space for this algorithm.
 */
#include <iostream>

struct Node
{
	Node* link;
	int data;
};

void delete_node(Node* n)
{
	Node* to_delete = n->link;

	n->data = to_delete->data;
	n->link = to_delete->link;

	delete to_delete;
}

void print_list(Node* head)
{
	while (head->link != NULL)
	{
		std::cout << head->data << std::endl;
		head = head->link;
	}
	std::cout << head->data << std::endl;
}

int main(int argc, char** argv)
{
	Node* n1 = new Node;
	n1->data = 1;
	Node* n2 = new Node;
	n2->data = 2;
	Node* n3 = new Node;
	n3->data = 3;

	n1->link = n2;
	n2->link = n3;
	n3->link = NULL;

	print_list(n1);

	delete_node(n2);

	print_list(n1);
}
