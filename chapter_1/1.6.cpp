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
