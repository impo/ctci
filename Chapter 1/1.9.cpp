/*
 * PROBLEM:
 * Assume you have a method isSubstring which checks if one word is a substring of
 * another. Given two strings, s1 and s2, write code to check if s2 is a rotation
 * of s1 using only one call to isSubstring.
 *
 * IMPLEMENTATION:
 * Return false if the strings differ in length. Concatenate s2 to itself, and check if
 * s1 is a substring of the result. If so, return true. Otherwise, return false.
 *
 * TIME COMPLEXITY:
 * O(n), to concatenate s2 to itself.
 *
 * SPACE COMPLEXITY:
 * O(n), to store the "doubled" string.
 *
 * HOW CAN YOU IMPROVE THIS?
 * Perhaps there's some way to compute the answer in O(1) time, but not without
 * complicating the solution.
 */
#include <string>
#include <iostream>

bool is_rotation(const std::string& s1, const std::string& s2)
{
	if (s1.size() != s2.size())
		return false;

	std::string result(s2);
	result += s2;
	return (result.find(s1) != std::string::npos);
}

int main(int argc, char** argv)
{
	std::cout << is_rotation("waterbottle", "erbottlewat") << std::endl;
	std::cout << is_rotation("abc", "def") << std::endl;
	std::cout << is_rotation("c++", "+c+") << std::endl;
}
