/*
 * PROBLEM:
 * Write code to remove duplicates from an unsorted linked list.
 *
 * IMPLEMENTATION:
 * Start iterating through the linked list, with a runner one step ahead of the normal
 * iteration. Keep a map from int to bool, recording whether or not an integer has been
 * seen. Whenever the runner iterates over an int that has already been seen, push the
 * runner back a step, then delete whatever is after the first iterator, and then push
 * the runner forward again.
 *
 * TIME COMPLEXITY:
 * O(n), because we iterate through the singly linked list only once, performing constant
 * work over each element.
 *
 * SPACE COMPLEXITY:
 * O(n), because in the worst case we store each element in the hashmap.
 *
 * HOW COULD YOU IMPROVE THIS?
 * I could avoid using a hashmap by searching the list for every element in order to
 * prune duplicates. However, this would increase the time complexity to O(n^2).
 */
#include <map>
#include <forward_list>
#include <iostream>

void dedup(std::forward_list<int>& l)
{
	std::map<int, bool> seen;
	auto runner = ++(l.begin());
	auto first = l.begin();
	while (runner != l.end())
	{
		seen[*first] = true;
		if (seen[*runner])
		{
			runner = first;
			l.erase_after(first);
		}
		else
		{
			++first;
		}
		++runner;
	}
}

int main(int argc, char** argv)
{
	std::forward_list<int> test = { 1, 1, 2, 3, 4, 4 };
	dedup(test);
	for (const int& i : test)
		std::cout << i << " ";
	std::cout << std::endl;
}
