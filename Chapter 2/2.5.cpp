/*
 * PROBLEM:
 * You have two numbers represented by a linked list, where each node contains a single
 * digit. The digits are stored in reverse order, such that the 1's digit is at the head
 * of the list. Write a function that adds the two numbers and returns the sum as a
 * linked list.
 *
 * IMPLEMENTATION:
 * To convert a list to an integer, set n = 0. Iterate through the list, multiplying each
 * element by 10^i, where i is that element's 0-based index and adding the result to n.
 * Return n.
 * 
 * To convert an integer to a list, note that for an integer n, n % 10 := the last digit
 * of that integer. Keep appending the last digit of the integer to a linked list,
 * dividing the integer by 10 every time you append a digit. When the integer equals
 * zero, return your list.
 *
 * We convert both lists to integers, sum the integers, and convert the result back to a
 * list. We then return that list.
 *
 * TIME COMPLEXITY:
 * O(n + m), where n and m are the number of digits in list one and two, respectively.
 * Converting a list to an integer takes O(d) time for d digits and converting that
 * back to a list takes O(d) time as well.
 *
 * SPACE COMPLEXITY:
 * O(1). We store a fixed number of integers.
 *
 * WHAT COULD YOU IMPROVE?
 * I could store the numbers represented by the lists as arbitrary-length integers,
 * to avoid overflow errors. However, this would take away the O(1) space complexity.
 */
#include <cmath>
#include <forward_list>
#include <iostream>

int to_num(const std::forward_list<int>& l)
{
	int sum = 0;
	int i = 0;
	for (auto it = l.cbegin(); it != l.cend(); it++, i++)
	{
		sum += (*it) * pow(10, i);
	}
	return sum;
}

std::forward_list<int> from_num(int n)
{
	std::forward_list<int> l;
	auto it = l.cbefore_begin();
	while (n > 0)
	{
		int next = n % 10;
		it = l.insert_after(it, next);
		n /= 10;
	}
	return l;
}

std::forward_list<int> add_lists(const std::forward_list<int>& a,
				const std::forward_list<int>& b)
{
	int num_a = to_num(a);
	int num_b = to_num(b);
	return from_num(num_a + num_b);
}

int main(int argc, char** argv)
{
	std::forward_list<int> result =
		add_lists( { 7, 1, 6 }, { 5, 9, 2 } );
	for (const int& i : result)
		std::cout << i << " ";
	std::cout << std::endl;
}
