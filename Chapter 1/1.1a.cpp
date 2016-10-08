/*
 * PROBLEM:
 * Implement an algorithm to determine if a string has all unique characters.
 * You may use additional data structures.
 *
 * IMPLEMENTATION:
 * Iterate through the string, placing every character in a set. Then check to
 * see if the size of the set is the same as the size of the string.
 *
 * TIME COMPLEXITY: O(n * log(n))
 * std::set is usually implemented as an RB-tree, so insertion should take
 * O(log(n)) time on a typical implementation. Since we iterate over every
 * element of the string, we get O(n * log(n)) time complexity for this
 * solution.
 *
 * SPACE COMPLEXITY: O(1)
 * We take up O(1) space since we use chars. A char can have 256
 * different values, so our set has no more that 256 elements.
 *
 * HOW COULD YOU IMPROVE THIS?
 * Using a hash table to store character counts would work, though it would
 * still have worst-case O(n^2) complexity.
 *
 * Storing character counts in a 128-element array indexed by character seems
 * to be the best solution. It would bring our time complexity down to O(n).
 * See 1.1b.cpp for that implementation.
 */

#include <set>
#include <string>
#include <iostream>

std::set<char> unique_chars(std::string s)
{
	std::set<char> chars;
	for (char& c: s)
	{
		chars.insert(c);
	}
	return chars;
}

bool is_unique(std::string s)
{
	std::set<char> unique_characters = unique_chars(s);
	return unique_characters.size() == s.size();
}

int main(int argc, char** argv)
{
	std::cout << is_unique("haha") << std::endl;
	std::cout << is_unique("defg") << std::endl;
	return 0;
}
