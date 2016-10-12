/*
 * PROBLEM:
 * Given a circular linked list, implement an algorithm that returns node at the
 * beginning of the loop.
 *
 * IMPLEMENTATION:
 * Iterate through the list, keeping track of which nodes have already been seen. If a
 * node points to a node that has already been seen, return the node that has already
 * been seen. If no loop is detected, return NULL.
 *
 * TIME COMPLEXITY:
 * O(n), because we iterate through the whole list once.
 *
 * SPACE COMPLEXITY:
 * O(n), because we store a hashmap of seen nodes.
 *
 * WHAT COULD YOU IMPROVE:
 * Have two pointers iterating through the list, one twice as fast as the other. When
 * they "collide," we have found the loop. Then move the slow pointer back to the list
 * head and move both pointers one step at a time until they collide. Then return either.
 */
#include <iostream>
#include <map>

struct Node
{
	int data;
	Node* next;
};

Node* detect_loop(Node* head)
{
	if ((head == NULL) || (head->next == NULL))
		return NULL;

	std::map<Node*, bool> m;
	m[head] = true;

	while (head->next != NULL)
	{
		if (m[head->next])
			return head->next;
		head = head->next;
	}
	return NULL;
}

int main(int argc, char** argv)
{
	Node* head = new Node;
	head->data = 1;
	Node* h2 = new Node;
	h2->data = 2;
	Node* h3 = new Node;
	h3->data = 3;
	
	head->next = h2;
	h2->next = h3;
	h3->next = head;

	std::cout << head << std::endl;
	std::cout << detect_loop(head) << std::endl;
}
