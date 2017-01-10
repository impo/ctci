/*
 * PROBLEM:
 * Write a function to determine the number of bits you would need to flip
 * to conver integer A to integer B.
 *
 * IMPLEMENTATION:
 * A XOR B returns a binary number with a 1 for every differing bit. Simply
 * count the number of 1 bits in A XOR B and return the count.
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * TIME COMPLEXITY:
 * O(1)
 */
#include <iostream>

int count_ones(int n)
{
	int count = 0;
	while (n != 0)
	{
		if ((n & 1) == 1)
		{
			++count;
		}
		n >>= 1;
	}

	return count;
}

int count_conversion_bits(const int &a, const int &b)
{
	return count_ones(a ^ b);
}

int main(int argc, char** argv)
{
	std::cout << count_conversion_bits(29, 15) << std::endl;
	return 0;
}
