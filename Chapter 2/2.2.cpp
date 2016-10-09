/*
 * PROBLEM:
 * Implement an algorithm to find the kth to last element of a singly linked list.
 *
 * IMPLEMENTATION:
 * Iterate through the list once to get a count of the elements in the list, then
 * return the value at the (count - k)th index in the list, assuming 0-based indices.
 *
 * TIME COMPLEXITY:
 * O(n), as we iterate through the list twice at max.
 *
 * SPACE COMPLEXITY:
 * O(1), as we do not store any variables other than indices and iterators.
 *
 * HOW CAN YOU IMPROVE THIS?
 * Error handling would help this solution. Also the bound on the second for-loop could
 * be (counter - k), instead of subtracting k from counter prior to the for-loop.
 */
#include <forward_list>
#include <cassert>
#include <iostream>

int kth_to_last(const std::forward_list<int>& l, size_t k)
{
	size_t counter = 0;
	for (auto it = l.cbegin(); it != l.cend(); it++)
		++counter;
	assert(counter > 0);

	counter -= k;
	auto answer = l.cbegin();
	for (int i = 0; i < counter; i++)
		++answer;
	return *answer;
}

int main(int argc, char** argv)
{
	std::forward_list<int> l = { 1, 2, 3, 4 };
	std::cout << kth_to_last(l, 4) << std::endl;
	return 0;
}
