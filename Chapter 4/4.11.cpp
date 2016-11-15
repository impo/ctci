/*
 * PROBLEM:
 * You are implementing a binary search tree class from scratch, which, in
 * addition to insert, find, and delete, has a method getRandomNode() which
 * returns a random node from the tree. All nodes should be equally likely
 * to be chosen. Design and implement an algorithm for getRandomNode, and
 * explain how you would implement the rest of the methods.
 *
 * IMPLEMENTATION:
 * Perform in-order traversal, counting the number of nodes. Then generate
 * a random integer from 1 to N, where N is the number of nodes. Next,
 * perform another in-order traversal, selecting the rth node, where r is the
 * random integer you generated earlier.
 *
 * TIME COMPLEXITY:
 * O(n)
 *
 * SPACE COMPLEXITY:
 * O(d), where d is the depth of the tree.
 *
 * WHAT COULD YOU IMPROVE?
 * Since I'm designing this class from scratch, I could keep track of the "size"
 * of each node, and I could use the size of the nodes to calculate an even
 * probabilistic distribution across all nodes. In this way, I could descend
 * and pick a node in one pass, in O(d) time.
 */
#include <random>

struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	int data = -1;
};

void inorder_count(const Node* n, int& c)
{
	if (n == nullptr)
		return;
	inorder_count(n->left, c);
	++c;
	inorder_count(n->right, c);
}

int inorder_count(const Node* n)
{
	int c = 0;
	inorder_count(n, c);
	return c;
}

void inorder_return(Node* n, int& c, const int& desired, Node*& result)
{
	if (n == nullptr || result != nullptr)
		return;
	inorder_return(n->left, c, desired, result);
	++c;
	if (c == desired)
		result = n;
	inorder_return(n->right, c, desired, result);
}

int randint(int lo, int hi)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(lo, hi);
	return uni(rng);
}

Node* get_random_node(Node* n)
{
	int count = inorder_count(n);
	int desired = randint(1, count);
	int c = 0;
	Node* result = nullptr;

	inorder_return(n, c, desired, result);

	return result;
}

int main(int argc, char** argv)
{
	return 0;
}
