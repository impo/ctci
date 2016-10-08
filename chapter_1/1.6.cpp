/*
 * PROBLEM: Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would because a2b1c5ae. If
 * the "compressed" string would not become smaller than the original string, your method
 * should return the original string. You can assume the string has only uppercase and
 * lowercase letters.
 *
 * IMPLEMENTATION:
 * If the string is empty, immediately return the string. Next, iterate through the
 * string, keeping count of how many instances of a character arise in a row as you
 * iterate.
 *
 * Create a new string to hold the compressed version of the original string.
 * Every time you encounter a new character, append the old character, along with its
 * count, to the new string.
 *
 * After iteration, do not forget to append the last character
 * along with its count.
 *
 * After appending the last character and its count, compare the size of the compressed
 * string to that of the original string. If the new string is longer than or as long as
 * the original string, return the original string. Otherwise, return the new string.
 *
 * TIME COMPLEXITY:
 * O(n), as we iterate through the entire old string, performing constant work with each
 * iteration.
 *
 * SPACE COMPLEXITY:
 * O(n). In the worst case, every character in the old string will be different from its
 * predecessor. Then our compressed string will append a count of 1 after each character,
 * storing 2n characters in the new string and n characters in the old string for roughly
 * 3n storage. We drop the constant to get O(n).
 *
 * WHAT COULD YOU IMPROVE?
 * We could check for the length of the compressed string up front, instead of building
 * the string and comparing lengths at the end of the compress method.
 */
#include <string>
#include <iostream>

void append_compression(std::string& s, char c, size_t counter)
{
	s.push_back(c);
	s.append(std::to_string(counter));
}

std::string compress(const std::string& s)
{
	if (s.size() == 0)
		return s;

	size_t counter = 0;
	char current = s[0];
	std::string result = std::string();

	for (char c : s)
	{
		if (c == current)
		{
			++counter;
		}
		else
		{
			append_compression(result, current, counter);
			current = c;
			counter = 1;
		}
	}
	append_compression(result, current, counter);

	if (result.size() >= s.size())
		return s;

	return result;
}

int main(int argc, char** argv)
{
	std::cout << compress("test") << std::endl;
	std::cout << compress("aabcccccaaa") << std::endl;
	std::cout << compress("a") << std::endl;
	std::cout << compress("") << std::endl;
}
