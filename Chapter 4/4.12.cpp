/*
 * PROBLEM:
 * You are given a binary tree in which each node contains an integer value
 * (which might be positive or negative). Design an algorithm to count the
 * number of paths that sum to a given value. The path does not need to start
 * or end at the root or a leaf, but it must go downwards.
 *
 * IMPLEMENTATION:
 * Recursively track the sum on a path from the root of a subtree to the
 * leaves, incrementing a count every time the tracked sum reaches the target
 * sum.
 *
 * Run this recursive algorithm on every node in the tree, and sum up the results.
 *
 * TIME COMPLEXITY:
 * O(n^2).
 *
 * SPACE COMPLEXITY:
 * O(d), where d is the max depth of the tree.
 *
 * WHAT COULD YOU IMPROVE?
 * With clever use of arithmetic and a hash table, I could get this algorithm
 * down to O(n) time and O(n) space.
 */
#include <iostream>

struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	int data = -1;
};

void count_paths(const Node* n, int& c, int sum, const int& desired)
{
	if (n == nullptr)
		return;
	if ((sum += n->data) == desired)
		++c;
	count_paths(n->left, c, sum, desired);
	count_paths(n->right, c, sum, desired);
}

int count_paths(const Node* n, const int& desired)
{
	int c = 0, sum = 0;
	count_paths(n, c, sum, desired);
	return c;
}

int count_total_paths(const Node* n, const int& desired)
{
	if (n == nullptr)
		return 0;
	int root_paths = count_paths(n, desired);
	int left_paths = count_total_paths(n->left, desired);
	int right_paths = count_total_paths(n->right, desired);

	return root_paths + left_paths + right_paths;
}

int main(int argc, char** argv)
{
	Node* root = new Node;
	Node* r1 = new Node;
	Node* r2 = new Node;
	Node* r3 = new Node;
	Node* r4 = new Node;
	Node* r5 = new Node;
	Node* r6 = new Node;
	Node* r7 = new Node;
	Node* r8 = new Node;
	root->data = 10;
	r1->data = 5;
	r2->data = -3;
	r3->data = 3;
	r4->data = 2;
	r5->data = 11;
	r6->data = 3;
	r7->data = -2;
	r8->data = 1;
	root->left = r1;
	root->right = r2;
	r1->left = r3;
	r1->right = r4;
	r2->right = r5;
	r3->left = r6;
	r3->right = r7;
	r4->right = r8;

	std::cout << count_total_paths(root, 8) << std::endl;

	return 0;
}
