/*
 * FALSE START:
 * This should work, though it relies on each node's data when that is not necessary.
 */
struct tree {
	tree* left = nullptr;
	tree* right = nullptr;
	tree* parent = nullptr;
	int data = -1;
};

tree* succ(const tree* node)
{
	tree* parent = node->parent;
	tree* rsub = node->right;
	if (rsub != nullptr)
	{
		while (rsub->left != nullptr)
			rsub = rsub->left;
		return rsub;
	}
	else if (par != nullptr)
	{
		while (par != nullptr && par->data < node->data)
			par = par->parent;
		return par;
	}
	else
	{
		return nullptr;
	}
}

int main(int argc, char** argv)
{
	return 0;
}
