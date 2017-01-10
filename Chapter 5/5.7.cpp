/*
 * PROBLEM:
 * Write a program to swap odd and even bits in an integer with as few
 * instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3
 * are swapped, and so on).
 *
 * IMPLEMENTATION:
 * Store the integer shifted left by one and the same integer shifted right by
 * one. Set another integer to 0. This integer will be used to store the answer.
 *
 * Loop through all the bits in the integer, over a zero-based index. On most
 * systems, this loop will range from 0 to 31. Ensure at every stage of the loop
 * that at least one of the left-shifted and right-shifted integers is nonzero.
 *
 * Construct the result by consuming the bits from the left-shifted and right-
 * shifted integers.
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * TIME COMPLEXITY:
 * O(1)
 *
 * HOW COULD YOU IMPROVE THIS?
 * Simply use a bitmask to extract the even and odd bits, then shift the results
 * accordingly and OR them together. However, this solution is not platform-
 * independent.
 */
#include <iostream>

int swap_bits(int n)
{
    int rsh = n >> 1;
    int lsh = n << 1;
    int result = 0;

    int sz = sizeof(int) * 8;

    for (int i = 0; i < sz && (rsh > 0 || lsh > 0); i++)
    {
        if (i % 2 == 0) // i is even
            result |= ((rsh & 1) << i);
        else
            result |= ((lsh & 1) << i);

        rsh >>= 1;
        lsh >>= 1;
    }

    return result;
}

int main(int argc, char** argv)
{
    std::cout << swap_bits(5) << std::endl; // should be 10
    std::cout << swap_bits(14) << std::endl; // should be 13
    return 0;
}
