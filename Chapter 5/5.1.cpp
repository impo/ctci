/*
 * PROBLEM:
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * Write a method to insert M into N such that M starts at bit j and ends at
 * bit i. You can assume that the bits j through i have enough space to fit
 * all of M.
 *
 * IMPLEMENTATION:
 * 1. Clear bits i thru j in N.
 * 2. Shift M left by i bits.
 * 3. Set N equal to N OR M.
 *
 * TIME COMPLEXITY:
 * O(1), since the algorithm is limited to 32-bit numbers.
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * WHAT COULD YOU IMPROVE?
 * I could be more clever with bit masks. The book constructs two halves of
 * a mask, and ANDs N with the mask to zero out all the appropriate bits at
 * once.
 */
#include <iostream>

unsigned clear_bit(unsigned n, unsigned i)
{
	return n & (~(1 << i));
}

unsigned int answer(unsigned i, unsigned j, unsigned n, unsigned m)
{
	for (unsigned idx = i; idx <= j; ++idx)
		n = clear_bit(n, idx);
	return n | (m << i);
}

int main(int argc, char** argv)
{
	std::cout << answer(2, 6, 1024, 19) << std::endl;
	return 0;
}
