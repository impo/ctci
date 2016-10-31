/*
 * PROBLEM:
 * Write an algorithm to find the in-order successor of a given node in a
 * binary search tree. You may assume that each node has a link to its parent.
 *
 * IMPLEMENTATION:
 * If there is a right subtree, take the leftmost node of the right subtree.
 * Otherwise, keep traversing up the parent nodes until you are "on the left,"
 * then return that node.
 *
 * TIME COMPLEXITY:
 * O(log(n)). In the worst case, you have to traverse parents up to the root
 * of the tree, rising log2(n) levels.
 *
 * SPACE COMPLEXITY:
 * O(1), to store bookkeeping variables.
 *
 * NOTES:
 * This solution is from the book, but I have included my false start in the
 * file 4.6a.cpp.
 */
struct tree {
	tree* left = nullptr;
	tree* right = nullptr;
	tree* parent = nullptr;
	int data = -1;
};

tree* leftmost_child(const tree* n)
{
	if (n == nullptr)
		return nullptr;
	while (n->left != nullptr)
		n = n->left;
	return n;
}

tree* in_order_succ(const tree* n)
{
	if (n == nullptr)
		return n;

	if (n->right != nullptr)
	{
		return leftmost_child(n->right);
	}
	else
	{
		const tree* q = n;
		const tree* x = q->parent;

		while (x != nullptr && x->left != q)
		{
			q = x;
			x = x->parent;
		}
		return x;
	}
}

int main(int argc, char** argv)
{
	return 0;
}
