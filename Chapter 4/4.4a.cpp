/*
 * False start on problem 4.4
 */
#include <iostream>

struct tree
{
	int data = 1;
	tree* left = nullptr;
	tree* right = nullptr;
};

bool is_balanced(const tree* root)
{
	if (root->left == nullptr && root->right == nullptr)
		return true;
	else if (root->left != nullptr && root->right != nullptr)
		return is_balanced(root->left) && is_balanced(root->right);
	else
	{
		if (root->left != nullptr)
		{
			if (root->left->left == nullptr &&
				root->left->right == nullptr)
				return true;
			else
				return false;
		}
		else
		{
			if (root->right->left == nullptr &&
				root->right->right == nullptr)
				return true;
			else
				return false;
		}
	}
}

int main(int argc, char** argv)
{
	tree* a = new tree;
	tree* b = new tree;
	tree* c = new tree;
	tree* d = new tree;
	tree* e = new tree;
	tree* f = new tree;
	tree* g = new tree;
	tree* h = new tree;
	tree* i = new tree;
	tree* j = new tree;
	tree* k = new tree;
	tree* l = new tree;
	tree* m = new tree;
	tree* n = new tree;
	tree* o = new tree;
	tree* p = new tree;
	tree* q = new tree;
	tree* r = new tree;
	tree* s = new tree;

	h->left = l;
	h->right = m;
	i->left = n;
	i->right = o;
	j->left = p;
	j->right = q;
	k->left = r;
	k->right = s;

	f->left = h;
	f->right = i;
	g->left = j;
	g->right = k;

	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	a->left = b;
	a->right = c;

	if (is_balanced(a))
		std::cout << "BALANCED" << std::endl;
	else
		std::cout << "UNBALANCED" << std::endl;
}
