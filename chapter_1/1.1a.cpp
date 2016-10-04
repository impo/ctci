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
