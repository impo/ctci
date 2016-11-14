/*
 * PROBLEM:
 * T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create
 * an algorithm to determine if T2 is a subtree of T1.
 *
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree
 * of n is identical to T2. That is, if you cut off the tree at node n, the two
 * trees would be identical.
 *
 * IMPLEMENTATION:
 * If the two trees' data matches, match the subtrees of the two trees. Otherwise,
 * keep searching for the root of T2.
 *
 * TIME COMPLEXITY:
 * O(n + km)
 *
 * SPACE COMPLEXITY:
 * O(n + m) on the call stack
 *
 * WHAT COULD BE IMPROVED?
 * This algorithm matches subtrees "embedded" in T1; in other words, it doesn't
 * require T1 to end after matching the nodes from T2. The leaves of T2 must
 * match nodes in T1 data-wise, but those nodes in T1 may still have children.
 *
 * I could modify the algorithm to remove this property, aligning with the
 * problem's definition of "subtree."
 *
 * In order to do this, I must assert that either both nodes being matched
 * are null or neither are null.
 */
#include <iostream>

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int data = -1;
};

bool match(const Node* t1, const Node* t2)
{
	// Done matching t2
	if (t2 == nullptr)
		return true;

	// Same as t2 != nullptr && t1 == nullptr.
	// We haven't finished matching t2, but t1 is already empty.
	if (t1 == nullptr)
		return false;

	// Now we know t1 != nullptr && t2 != nullptr,
	// so we can compare their data.
	
	// Data is the same, so match the subtrees of t1 with those of t2.
	if (t1->data == t2->data)
		return match(t1->left, t2->left) && match(t1->right, t2->right);
	else // Data is different, so keep searching for the root.
		return match(t1->left, t2) || match(t1->right, t2);
}

Node* neu_node(const int& i)
{
	Node* n = new Node;
	n->data = i;
	return n;
}

void link(Node* n1, Node* n2, Node* n3)
{
	n1->left = n2;
	n1->right = n3;
}

int main(int argc, char** argv)
{
	auto t1 = neu_node(1);
	auto t2 = neu_node(2);
	auto t3 = neu_node(3);
	auto t4 = neu_node(4);
	auto t5 = neu_node(5);
	auto t6 = neu_node(6);
	auto t7 = neu_node(7);
	auto t8 = neu_node(8);
	auto t9 = neu_node(9);
	auto t10 = neu_node(10);

	link(t2, t3, t4);
	link(t1, t5, t6);
	link(t5, t7, t8);
	link(t6, t9, t10);
	link(t10, t2, nullptr);

	if (match(t1, t2))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	return 0;
}
