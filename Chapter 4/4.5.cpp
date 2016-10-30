/*
 * PROBLEM:
 * Implement a function to check if a binary tree is a binary search tree.
 *
 * IMPLEMENTATION:
 * Keep track of a minimum and a maximum value that a node can have within
 * the context of a BST. Recurse through the tree, updating the max when
 * branching left and the min when branching right and checking each
 * node according to the max and min.
 *
 * TIME COMPLEXITY:
 * O(n)
 *
 * SPACE COMPLEXITY:
 * O(log(n))
 *
 * NOTES:
 * Looked at the solution guide to check against my original solution.
 * My (incorrect) original solution can be found in the 4.5a.cpp file.
 */
struct tree {
	tree* left = nullptr;
	tree* right = nullptr;
	int* data = nullptr;
};

bool check_bst(const tree* root, int* min, int* max)
{
	if (root == nullptr)
		return true;

	if ((min != nullptr && *(root->data) <= *min) ||
		(max != nullptr && *(root->data) > *max))
		return false;

	if (!check_bst(root->left, min, root->data) ||
		!check_bst(root->right, root->data, max))
		return false;

	return true;
}

int main(int argc, char** argv)
{
	return 0;
}
