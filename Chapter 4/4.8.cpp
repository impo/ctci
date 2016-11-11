/*
 * PROBLEM:
 * Design an algorithm and write code to find the first common ancestor of two
 * nodes in a binary tree. Avoid storing additional nodes in a data structure.
 *
 * IMPLEMENTATION:
 * If the two nodes are not of equal depth, follow the parent of the deeper
 * node until both are at equal depth. Then simultaneously follow the parents
 * of both nodes until the nodes are equal.
 *
 * TIME COMPLEXITY:
 * O(d), where d is the depth of the deeper node.
 *
 * SPACE COMPLEXITY:
 * Trivially O(1).
 *
 * WHAT COULD YOU IMPROVE?
 * I could implement a solution that does not rely on parent links by
 * descending through the tree. If both nodes lie on the "same side"
 * of the current node, then branch to that side. If each node lies on a
 * different side of the current node, I have found the common ancestor.
 */
#include <cstdlib>

struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

std::size_t find_depth(Node* n)
{
	std::size_t depth = 0;
	while (n = n->parent)
		++depth;
	return depth;
}

Node* common_ancestor(Node* n1, Node* n2)
{
	std::size_t h1 = find_depth(n1);
	std::size_t h2 = find_depth(n2);

	while (h1 > h2)
	{
		n1 = n1->parent;
		--h1;
	}
	while (h2 > h1)
	{
		n2 = n2->parent;
		--h2;
	}

	while (n1 != n2)
	{
		n1 = n1->parent;
		n2 = n2->parent;
	}
	
	return n1;
}

int main(int argc, char** argv)
{
	return 0;
}
