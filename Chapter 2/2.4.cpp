/*
 * PROBLEM:
 * Write code to partition a linked list around a value x, such that all nodes less than
 * x come before all nodes greater than or equal to x. If x is contained within the list,
 * the values of x only need to be after the elements less than x. The partition element
 * x can appear anywhere in the "right partition"; it does not need to appear between
 * the left and right partitions.
 *
 * TIME COMPLEXITY:
 * O(n), as we iterate through the list once. In the worst case we will remove all but
 * the first element and x, which makes (n-2) removals and (n-2) insertions. These
 * insertions and removals take constant time on a linked list.
 *
 * SPACE COMPLEXITY:
 * O(1), as we only store a few temporary variables.
 */
#include <forward_list>
#include <iostream>

void partition(std::forward_list<int>& l, int x)
{
	auto first = l.begin();
	auto runner = ++(l.begin());

	while (runner != l.end())
	{
		if (*runner < x)
		{
			int tmp = *runner;
			runner = first;
			l.erase_after(first);
			l.push_front(tmp);
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
	std::forward_list<int> l = { 3, 5, 8, 5, 10, 2, 1 };
	partition(l, 5);

	for (const int& i : l)
		std::cout << i << " ";
	std::cout << std::endl;
}
