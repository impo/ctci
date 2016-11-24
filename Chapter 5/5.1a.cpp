/*
 * NOTE:
 * "Translation" of book's solution for 5.1.
 */
#include <iostream>

unsigned update_bits(const unsigned& n, const unsigned& m, const unsigned& i,
		const unsigned& j)
{
	unsigned ones = ~0;
	unsigned left = ones << (j + 1);
	unsigned right = ((1 << i) - 1);
	unsigned mask = left | right;

	/* Clear bits i through j then put m in there */
	unsigned n_cleared = n & mask;
	unsigned m_shifted = m << i;
	return n_cleared | m_shifted;
}

int main(int argc, char** argv)
{
	return 0;
}
