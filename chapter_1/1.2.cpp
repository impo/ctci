/*
 * PROBLEM:
 * Given two strings, write a method to decide if one is a permutation of the
 * other.
 *
 * IMPLEMENTATION:
 * Sort both strings and compare the two. If they're equal, they're
 * permutations of each other.
 *
 * TIME COMPLEXITY:
 * O(a * log(a) + b * log(b)) where a is the length of the first
 * string and b is the length of the second string.
 *
 * std::sort should have a worst-case time complexity of O(n * log(n)), and we
 * run it on the two strings, so we sum the runtimes.
 *
 * SPACE COMPLEXITY:
 * Many implementations of std::sort rely on a hybrid of merge sort and
 * quicksort, so roughly O(log(n)) or O(n).
 *
 * WHAT COULD YOU IMPROVE?
 * Before, sorting, check if the two strings are equal. This improves our
 * average-case time complexity.
 *
 * Check if the two strings are of equal length. If not, return false.
 * 
 * We could also store an array of character counts for both strings, which
 * reduces our space complexity to O(1). This should also reduce our time
 * complexity to O(A + B).
 */
#include <string>
#include <algorithm>
#include <iostream>

bool is_permutation(std::string s1, std::string s2)
{
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return s1 == s2;
}

int main(int argc, char** argv)
{
	std::cout << is_permutation("hello", "lleoh") << std::endl;
	std::cout << is_permutation("one", "two") << std::endl;
	std::cout << is_permutation("a", "a") << std::endl;
	std::cout << is_permutation("!@", "@!") << std::endl;
	return 0;
}
