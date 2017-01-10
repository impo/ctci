/*
 * PROBLEM:
 * Given a positive integer, print the next smallest and the next largest
 * number that have the same number of 1 bits in their binary representation.
 *
 * IMPLEMENTATION:
 * Count the number of trailing zeroes and the number of following
 * ones, then ensure that it is possible to find the next largest
 * number. Set bit at position p to 1, where p is equal to the sum
 * of the count of trailing zeros and the count of following ones.
 *
 * Clear all the bits to the right of p, then insert 1s at positions
 * 0 through c1 - 1.
 *
 * Similar logic follows for finding the previous number.
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * TIME COMPLEXITY:
 * O(1)
 *
 * NOTES:
 * This solution was adapted from CtCI.
 */
#include <iostream>

int get_next(int n)
{
	int c = n;
	int c0 = 0, c1 = 0;
	
	while (((c & 1) == 0) && (c != 0)) // count trailing zeros
	{
		c0++;
		c >>= 1;
	}

	while ((c & 1) == 1) {
		c1++;
		c >>= 1;
	}

	if (c0 + c1 == 31 || c0 + c1 == 0)
		return -1;

	int p = c0 + c1;

	n |= (1 << p);
	n &= ~((1 << p) - 1);
	n |= (1 << (c1 - 1)) - 1;
}

int get_prev(int n)
{
	int tmp = n;
	int c0 = 0, c1 = 0;

	while (tmp & 1 == 1)
	{
		c1++;
		tmp >>= 1;
	}

	if (tmp == 0) return -1;

	while ((tmp & 1) == 0 && (tmp != 0))
	{
		c0++;
		tmp >>= 1;
	}

	int p = c0 + c1;
	n &= ((~0) << (p + 1));

	int mask = (1 << (c1 + 1)) - 1; // Sequence of (c1 + 1) ones
	n |= mask << (c0 - 1);

	return n;
}

int main(int argc, char** argv)
{
	return 0;
}
