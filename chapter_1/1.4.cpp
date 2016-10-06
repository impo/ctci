/*
 * PROBLEM:
 * Given a string, write a function to check if it is a permutation of a
 * palindrome. A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters. The palindrome does not need to be
 * limited to just dictionary words.
 *
 * IMPLEMENTATION:
 * Make a 128-element size_t array to store character counts. Iterate through the string,
 * counting all alphabetic characters as lowercase letters. Iterate through the character
 * counts. If you have more than one odd count, then return false. Otherwise, return
 * true.
 *
 * TIME COMPLEXITY:
 * O(n), as we iterate through the whole string and then iterate through 26 characters.
 *
 * SPACE COMPLEXITY:
 * O(1), as we only need space for a 128-element array and for an integer to hold our
 * odd count.
 *
 * HOW COULD YOU IMPROVE TI?
 * Store whether or not a count is even or odd inside the bits of an integer. Thirty-two
 * bits provides us more than enough room (26 alphabetic characters). To see if exactly
 * one of the bits is flipped to 1 (exactly 1 odd count), just compute
 * 					bitvec & (bitvec - 1).
 * If this returns a value of zero, then exactly one bit is set to one (return true).
 * Otherwise, you have more than one alphabetic character occurring an odd number of
 * times in your string, and thus your string is not a permutation of a palindrome.
 */
#include <iostream>
#include <string>
#include <cctype>

bool is_perm_of_palindrome(const std::string& s)
{
	size_t count[128] = {0};
	int odd_counts = 0;

	for (const char& c : s)
		if (isalpha(c))
			++count[tolower(c)];
	
	for (char c = 'a'; c <= 'z'; c++)
		if (count[c] % 2) // count is odd
			++odd_counts;

	return odd_counts <= 1;
}

int main(int argc, char** argv)
{
	std::cout << is_perm_of_palindrome("Tact Coa") << std::endl;
	std::cout << is_perm_of_palindrome("aaa") << std::endl;
	std::cout << is_perm_of_palindrome("bad") << std::endl;
	std::cout << is_perm_of_palindrome("tactcoapapa") << std::endl;
	std::cout << is_perm_of_palindrome("") << std::endl;
}
