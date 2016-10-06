/*
 * PROBLEM:
 * Write a method to replace all spaces in a string with %20. You may assume that the
 * string has sufficient space at the end to hold the additional characters, and that
 * you are given the "true" length of the string.
 *
 * IMPLEMENTATION:
 * Traverse the "true string," counting up the total number of spaces and noting the
 * index of the first space. If there are no spaces, return the original string.
 *
 * Next, traverse the "true string" backwards, moving every non-space character back by
 * 2 * (the number of spaces).
 *
 * Lastly, traverse through the entire string, which now has three spaces for every space
 * in the "true string." Replace each triplet of spaces with %20 and return the string.
 *
 * TIME COMPLEXITY:
 * O(n), because we traverse the array roughly twice, performing constant time operations
 * with each traversal. 
 *
 * SPACE COMPLEXITY:
 * O(1), because we only store two values: the index of the first space in the string and
 * the total number of spaces.
 *
 * WHAT COULD YOU IMPROVE?
 * Start by counting the number of total spaces. Do not keep track of the index of the
 * first space. Iterate backwards through the "true string", copying each character
 * over to the end of the "full string." On each space, copy '%20'.
 */

#include <string>
#include <iostream>

std::string urlify(std::string& s, int true_len)
{
	int first_space_idx = -1;
	int num_spaces = 0;

	for (int i = 0; i < true_len; i++)
	{
		if (s[i] == ' ')
		{
			if (num_spaces == 0)
				first_space_idx = i;
			++num_spaces;
		}
	}

	if (num_spaces == 0)
		return s;

	for (int i = (true_len - 1); i > first_space_idx; i--)
	{
		if (s[i] == ' ')
		{
			--num_spaces;
			continue;
		}
		s[i + 2 * num_spaces] = s[i];
		s[i] = ' ';
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '%';
			s[i + 1] = '2';
			s[i + 2] = '0';
		}
	}
	
	return s;
}

int main(int argc, char** argv)
{
	std::string s1(" hi  ");
	std::string s2("Mr John Smith    ");
	std::string s3("foo");
	std::string s4("      ");

	std::cout << urlify(s1, 3) << std::endl;
	std::cout << urlify(s2, 13) << std::endl;
	std::cout << urlify(s3, 3) << std::endl;
	std::cout << urlify(s4, 2) << std::endl;
	return 0;
}
