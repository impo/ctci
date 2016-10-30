/*
 * FALSE START:
 * Does not work because it only checks if each node is "balanced,"
 * not if the entire binary tree is a search tree.
 *
 * It would incorrectly return true  on the following tree:
 * 		20
 * 	       /  \
 * 	      10  30
 * 	       \
 * 	       25
 */
struct tree {
	tree* left = nullptr;
	tree* right = nullptr;
	int data = -1;
};

bool is_bst(const tree* root)
{
	if (root == nullptr)
		return true;

	bool first = (root->left == nullptr) || (root->left->data < root->data);
	bool second = (root->right == nullptr) || (root->right->data < root->data);

	return first && second && is_bst(root->left) && is_bst(root->right);
}

int main(int argc, char** argv)
{
	return 0;
}
