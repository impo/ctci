/*
 * PROBLEM:
 * Implement a function to check if a linked list is a palindrome.
 *
 * IMPLEMENTATION:
 * Reverse the linked list and compare it to the original.
 *
 * TIME COMPLEXITY:
 * O(n). We iterate over a list of length n three times, performing constant work with
 * each iteration.
 *
 * SPACE COMPLEXITY:
 * O(n). We store a reversed copy of the original list.
 *
 * WHAT COULD YOU IMPROVE?
 * I only have to compare the first half of the original list to the reversed list, so
 * I could be saving work this way.
 *
 * I could have iterated through the list, pushing each element of the first half onto
 * a stack and then popping and comparing elements with the second half of the list.
 */
#include <forward_list>
#include <iostream>

bool is_palindrome(const std::forward_list<char>& l)
{
	std::forward_list<char> reversed;
	for (const char& c : l)
		reversed.push_front(c);
	for (auto first = l.cbegin(), second = reversed.cbegin();
		first != l.cend() && second != reversed.cend();
		first++, second++)
	{
		if (*first != *second)
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	std::cout << is_palindrome( { 'a', 'b', 'a' } ) << std::endl;
	std::cout << is_palindrome( { 'b', 'o', 'o' } ) << std::endl;
	std::cout << is_palindrome( { 'h', 'a', 'n', 'n', 'a', 'h' } ) << std::endl;
	std::cout << is_palindrome( { 'h', 'a', 'n', 'n' } ) << std::endl;
}
