/*
 * PROBLEM:
 * Given two (singly) linked lists, determine if the two lists intersect. Return the
 * intersecting node. Note that the intersection is defined based on reference, not
 * value. That is, if the kth node of the first linked list is the exact same node
 * (by reference) as the jth node of the second linked list, then they are
 * intersecting.
 *
 * TIME COMPLEXITY:
 * O(A + B), because we iterate through both lists twice in the worst case,
 * performing constant work over each iteration.
 *
 * SPACE COMPLEXITY:
 * O(1), as we store a fixed number of bookkeeping variables.
 *
 * WHAT COULD YOU IMPROVE?
 * Check the tail nodes of each linked list. If they differ, there is no intersection
 * and we should return immediately with NULL.
 */
#include <algorithm>
#include <iostream>

struct Node
{
	Node* next;
	int data;
};

// Find length of linked list
size_t find_length(Node* l)
{
	size_t len = 1;
	while (l->next != NULL)
	{
		l = l->next;
		++len;
	}
	return len;
}

Node* intersection(Node* a, Node* b)
{
	size_t len_a = find_length(a), len_b = find_length(b);

	// Now we use start_a and start_b
	Node* longer = (len_a > len_b) ? a : b;
	Node* shorter = (len_a > len_b) ? b : a;

	size_t longer_len = std::max(len_a, len_b);
	size_t shorter_len = std::min(len_a, len_b);

	size_t dist = longer_len - shorter_len;

	while (dist > 0)
	{
		longer = longer->next;
		--dist;
	}
	while (longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}

int main(int argc, char** argv)
{
	Node* a = new Node;
	Node* b = new Node;
	Node* b2 = new Node;

	a->data = 1;
	b->data = 7;
	b2->data = 8;

	b->next = b2;
	b2->next = a;

	std::cout << a << std::endl;
	std::cout << intersection(a, b) << std::endl;
}
