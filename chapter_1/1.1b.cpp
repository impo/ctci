/*
 * PROBLEM:
 * Implement an algorithm to determine if a string has all unique characters,
 * without using any data structures.
 *
 * IMPLEMENTATION:
 * Make a 128-element char array to store character counts, indexed by
 * character. If we're about to increment a character counter that's already
 * at 1, we know the string is not comprised of unique characters.
 *
 * TIME COMPLEXITY: O(n)
 * We simply iterate through the string, performing constant work over each
 * character.
 *
 * SPACE COMPLEXITY: O(1)
 * We use up 128 bytes for the char array.
 *
 * HOW COULD YOU IMPROVE THIS?
 * Storing our state in a bool array instead of a char array, since all we
 * need to know is whether or not we have seen the character before or not.
 *
 * Perhaps unicode handling could be considered an improvement, though it would
 * vastly increase the complexity of the algorithm and seems outside the scope
 * of the question.
 */

#include <string>
#include <iostream>
#include <cassert>

bool is_unique(std::string s)
{
	char count[128] = {0};
	for (char& c : s)
	{
		assert(c > -1 && c < 128);
		if (count[c]++ == 1)
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	std::cout << is_unique("haha") << std::endl;
	std::cout << is_unique("sadboy") << std::endl;
	return 0;
}
