/*
 * PROBLEM:
 * Given a sorted (increasing order) array with unique integer elements, write an
 * algorithm to create a binary search tree with minimal height.
 *
 * IMPLEMENTATION:
 * Create the root of your tree in the middle of the array. The left subtree and
 * the right subtree are constructed recursively from the left half of the array
 * and the right half of the array, respectively.
 *
 * TIME COMPLEXITY:
 * O(n), as we "add a root" for every element in the array.
 *
 * SPACE COMPLEXITY:
 * O(n) on the call stack.
 *
 * WHAT COULD YOU IMPROVE?
 * I could implement an iterative solution, or I could try to improve the space
 * complexity of this solution.
 *
 * NOTES:
 * Shamefully, I had to look at the solution for this one. I had the right idea
 * of taking the center of the array for the root of the tree and recursively
 * splitting the halves the of the arrays up into subtrees, but I tried to
 * implement it without using variables for the start and the end of the
 * subarrays and quickly got frustrated. I tried to work it out with
 * my method for a few hours before giving up.
 */
#include <vector>

struct Tree {
	int data;
	Tree* left;
	Tree* right;
};

Tree* create_minimal_BST(std::vector<int> a, int start, int end)
{
	if (end < start)
		return nullptr;

	int mid = (start + end) / 2;

	Tree* n = new Tree;
	n->data = a[mid];
	n->left = create_minimal_BST(a, start, mid - 1);
	n->right = create_minimal_BST(a, mid + 1, end);
	return n;
}

Tree* create_minimal_BST(std::vector<int> a)
{
	if (a.size() == 0)
		return nullptr;
	else
		return create_minimal_BST(a, 0, a.size() - 1);
}

int main(int argc, char** argv)
{
	return 0;
}
