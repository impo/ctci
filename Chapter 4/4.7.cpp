/*
 * PROBLEM:
 * You are given a list of projects and a list of dependencies. All of a
 * project's dependencies must be built before the project is. Find a build
 * order that will allow the projects to be built. If there is no valid
 * build order, return an error.
 *
 * Implementation:
 * Represent the projects and dependencies as a directed graph, then run
 * Kahn's algorithm on the graph to topologically sort it.
 *
 * TIME COMPLEXITY:
 * O(P + D), where P is the number of projects and D is the number of
 * edges between projects.
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * WHAT COULD YOU IMPROVE?
 * Perhaps I could use regex to parse the dependency pairs, so the pairs
 * can be represented in the form: (a, b), (b, c), etc.
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

struct Node
{
	std::string name;
	std::vector<Node*> outgoing;
	std::vector<Node*> incoming;
};

struct Graph
{
	std::vector<Node*> vertices;
	std::size_t edge_count = 0;
};

std::map<std::string, Node*> construct_nodes()
{
	std::map<std::string, Node*> m;
	std::cout << "projects: " << std::endl;

	std::string s;
	std::getline(std::cin, s);

	std::stringstream ss(s);
	std::string project;
	while (std::getline(ss, project, ' '))
	{
		Node* n = new Node;
		n->name = project;
		m[project] = n;
	}
	return m;
}

std::size_t construct_neighbors(std::map<std::string, Node*>& m)
{
	std::size_t edge_count = 0;
	std::cout << "dependencies:" << std::endl;
	std::string f, s;
	std::getline(std::cin, s);

	std::stringstream ss(s);
	while (ss >> f >> s)
	{
		m[f]->outgoing.push_back(m[s]);
		m[s]->incoming.push_back(m[f]);
		++edge_count;
	}
	return edge_count;
}

Graph construct_graph()
{
	Graph g;

	std::map<std::string, Node*> m = construct_nodes();
	g.edge_count = construct_neighbors(m);

	for (auto const &p : m)
		g.vertices.push_back(p.second);
	return g;
}

bool create_build(Graph& g, std::vector<Node*>& b)
{
	std::vector<Node*> no_incoming;
	for (Node* n : g.vertices)
	{
		if (n->incoming.empty())
			no_incoming.push_back(n);
	}
	while (!no_incoming.empty())
	{
		b.push_back(no_incoming.back());
		no_incoming.pop_back();
		for (Node* m : (b.back()->outgoing))
		{
			m->incoming.erase(std::remove(m->incoming.begin(), m->incoming.end(), b.back()), m->incoming.end());
			--g.edge_count;
			if (m->incoming.empty())
				no_incoming.push_back(m);
		}
	}
	return (g.edge_count == 0);
}

void print_build(const std::vector<Node*>& b)
{
	for (auto const &n : b)
		std::cout << n->name << " ";
	std::cout << std::endl;
}

int main()
{
	Graph g = construct_graph();
	std::vector<Node*> build;
	if (create_build(g, build))
		print_build(build);
	else
		std::cout << "FAIL" << std::endl;
	return 0;
}
