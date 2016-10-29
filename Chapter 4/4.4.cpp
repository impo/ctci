/*
 * PROBLEM:
 * Implement a function to check if a binary tree is balanced. For the purposes
 * of this question, a balanced tree is defined to be a tree such that the
 * heights of the two subtrees of any node never differ by more than one.
 *
 * IMPLEMENTATION:
 * Recursively compare the height of subtrees, returning an error code if the
 * tree is not balanced.
 *
 * TIME COMPLEXITY:
 * O(n)
 *
 * SPACE COMPLEXITY:
 * O(h), where h is the height of the tree, because that is how many times
 * check_height recurses.
 *
 * WHAT COULD YOU IMPROVE?
 * I could make this algorithm iterative instead of recursive, by using a stack.
 */
#include <algorithm>
#include <cmath>
#include <limits>

struct tree
{
	int data = 1;
	tree* left = nullptr;
	tree* right = nullptr;
};

int check_height(const tree* root)
{
	if (root == nullptr)
		return -1;

	int left_height = check_height(root->left);
	if (left_height == std::numeric_limits<int>::min())
		return std::numeric_limits<int>::min();
	
	int right_height = check_height(root->right);
	if (right_height == std::numeric_limits<int>::min())
		return std::numeric_limits<int>::min();

	int height_diff = left_height - right_height;
	if (std::abs(height_diff) > 1)
		return std::numeric_limits<int>::min();
	else
		return std::max(left_height, right_height) + 1;
}

bool is_balanced(const tree* root)
{
	return check_height(root) != std::numeric_limits<int>::min();
}

int main(int argc, char** argv)
{
	return 0;
}
