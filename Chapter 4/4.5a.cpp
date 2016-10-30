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
