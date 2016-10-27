/*
 * PROBLEM:
 * Given a binary tree, design an algorithm which creates a linked list of all
 * the nodes at each depth (e.g., if you have a tree with depth D, you'll have
 * D linked lists).
 *
 * IMPLEMENTATION:
 * Create an empty vector to hold the linked lists. Create a linked list holding
 * just the root node and call it "current depth."
 *
 * While there exists a current depth, add all of the children nodes of the nodes
 * in the current depth to a list called "next depth."
 *
 * Then push "current depth" onto the vector and set the current depth to the
 * next depth.
 *
 * TIME COMPLEXITY:
 * O(n), as we traverse over each node, performing constant work with each
 * traversal.
 *
 * SPACE COMPLEXITY:
 * O(n), as we return all n nodes.
 */
#include <list>
#include <vector>

struct tree {
	int data = -1;
	tree* left = nullptr;
	tree* right = nullptr;
};

std::vector<std::list<tree*>> depths(tree* root)
{
	std::vector<std::list<tree*>> result;
	std::list<tree*> current_depth;

	if (root != nullptr)
		current_depth.push_back(root);

	while (!current_depth.empty())
	{
		std::list<tree*> next_depth;
		for (tree* node : current_depth)
		{
			if (node->left != nullptr)
				next_depth.push_back(node->left);
			if (node->right != nullptr)
				next_depth.push_back(node->right);
		}
		result.push_back(current_depth);
		current_depth = next_depth;
	}
	return result;
}

int main(int argc, char** argv)
{
	return 0;
}
