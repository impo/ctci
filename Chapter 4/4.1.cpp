#include <vector>
#include <iostream>

struct Node {
	bool visited = false;
	std::vector<Node*> adjacent;
};

struct Graph {
	std::vector<Node> nodes;
};

bool is_path(Graph& g, Node* s, Node* t)
{
	s->visited = true;

	if (s == t)
		return true;

	for (Node* n : s->adjacent)
	{
		if (!(n->visited) && is_path(g, n, t))
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	Node a, b, c;
	
	a.adjacent.push_back(&b);
	b.adjacent.push_back(&c);

	Graph g = { { a, b, c } };

	if (is_path(g, &a, &c))
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
}
