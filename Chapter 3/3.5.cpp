/*
 * PROBLEM:
 * Write a program to sort a stack such that the smallest items are on the top.
 * You can use an additional temporary stack, but you may not copy the elements
 * into any other data structure (such as an array). The stack supports the
 * following operations: push, pop, peek, and isEmpty.
 *
 * IMPLEMENTATION:
 * Insert the elements in sorted order (smallest on bottom, largest on top)
 * into the temporary stack, then move all of the elements back from the
 * temporary stack into the original stack.
 *
 * TIME COMPLEXITY:
 * O(n^2)
 *
 * SPACE COMPLEXITY:
 * O(n)
 *
 * WHAT COULD YOU IMPROVE?
 * If I could create an unlimited number of stacks, I could implement a form
 * of quicksort. Under my constraints, I have implemented the fastest and
 * most space-efficient algorithm possible.
 */
#include <stack>

void sort_stack(std::stack<int>& s)
{
	std::stack<int> tmp;
	while (!s.empty())
	{
		int store = s.top();
		s.pop();
		while ((!tmp.empty()) && (store < tmp.top()))
		{
			s.push(tmp.top());
			tmp.pop();
		}
		tmp.push(store);
	}
	while (!tmp.empty())
	{
		s.push(tmp.top());
		tmp.pop();
	}
}

int main(int argc, char** argv)
{
	return 0;
}
