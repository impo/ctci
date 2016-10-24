/*
 * PROBLEM:
 * Given a directed graph, design an algorithm to find out whether there is a route
 * between two nodes.
 *
 * IMPLEMENTATION:
 * Perform depth-first search on the graph. Start from the source node and continue
 * the search until you visit the target node. If you never find the target node,
 * return false.
 *
 * TIME COMPLEXITY:
 * O(V+E), as we use an adjacency list to represent edges between nodes. We visit
 * each node and each edge once, with O(1) time for every visit. This we have
 * O(V) + O(E) time complexity, or O(V + E).
 *
 * SPACE COMPLEXITY:
 * O(V^2). Suppose every vertex has edges to every other vertex. Then each vertex
 * stores V edges, making O(V*V) = O(V^2) storage.
 *
 * WHAT COULD YOU IMPROVE?
 * Depending on the average use case of this algorithm, BFS may be faster.
 */
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
