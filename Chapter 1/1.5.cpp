/*
 * PROBLEM:
 * There are three types of edits that can be performed on strings: insert a character,
 * remove a character, or replace a character. Given two strings, write a function to
 * check if they are one edit (or zero edits) away.
 *
 * IMPLEMENTATION:
 * First, set up two methods to determine the longest and shortest string of two strings,
 * respectively.
 *
 * If the longest and shortest string are of the same length, compare the
 * two strings character-by-character. If there is more than one character-wise
 * difference between the strings, return false, as there has been more than one
 * replacement edit.
 *
 * If the lengths of the longest and shortest string differ by more than one, there has
 * been more than one insertion/deletion edit, and thus we return false.
 *
 * If the lengths of the longest and shortest string differ by exactly one, we compare
 * the two strings character-wise, skipping a character of the largest string the first
 * time we find a mismatch. If we find more than one mismatch, we have more than one edit
 * and thus we will return false.
 *
 * TIME COMPLEXITY:
 * Let the length of the first string be L_1 and that of the second string be L_2. We
 * have O(min(L_1, L_2)), because we iterate over the smaller of the two strings,
 * performing constant work over each element.
 *
 * SPACE COMPLEXITY:
 * O(1), as we need constant space to store the number of edits and to store the indices
 * for iteration.
 *
 * WHAT COULD YOU IMPROVE?
 * The longest_string and shortest string methods could be replaced by the expressions:
 * 	const std::string& longest = (s1.size() > s2.size()) ? s1 : s2;
 * 	const std::string& shortest = (s1.size() > s2.size()) ? s2 : s1;
 *
 * Other than that, I think the solution is fairly clean.
 */
#include <algorithm>
#include <iostream>
#include <string>

const std::string& longest_string(const std::string& s1, const std::string& s2)
{
	if (s1.size() > s2.size())
		return s1;
	else if (s1.size() == s2.size())
		return s1;
	else
		return s2;
}

const std::string& shortest_string(const std::string& s1, const std::string& s2)
{
	if (s1.size() < s2.size())
		return s1;
	else if (s1.size() == s2.size())
		return s2;
	else
		return s2;
}

bool one_edit_away(const std::string& s1, const std::string& s2)
{
	const std::string& longest = longest_string(s1, s2);
	const std::string& shortest = shortest_string(s1, s2);
	size_t edits = 0;

	if (longest.size() == shortest.size())
	{
		for (int i = 0; i < longest.size(); i++)
			if (s1[i] != s2[i])
				++edits;
	}
	else if ((longest.size() - shortest.size()) > 1)
	{
		edits = longest.size() - shortest.size();
	}
	else // strings are only one character apart in length
	{
		for (int i = 0, j = 0; i < shortest.size() && j < longest.size(); i++, j++)
		{
			if (shortest[i] != longest[j]) // we assume this is the character
							// missing from shortest
			{
				++j;
				++edits;

			}
		}
	}

	return (edits <= 1);
}

int main(int argc, char** argv)
{
	std::cout << one_edit_away("pale", "ple") << std::endl
		<< one_edit_away("pales", "pale") << std::endl
		<< one_edit_away("pale", "bale") << std::endl
		<< one_edit_away("pale", "bake") << std::endl
		<< one_edit_away("", "a") << std::endl;
}
