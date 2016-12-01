/*
 * PROBLEM:
 * You have an integer and you can flip exactly one bit from a 0 to a 1. Write
 * code to find the length of the longest sequence of 1s you could create.
 *
 * IMPLEMENTATION:
 * Store the number of ones before the gap and through the gap, separately.
 * When you encounter a zero, start incrementing the counter for the number of
 * ones through the gap until you either encounter a zero or until you finish
 * iterating through the number.
 *
 * Whether you finish iterating or find a zero, check if the count of ones
 * is greater than the maximum count thus far. If it is greater, set the maximum
 * count to the count of ones.
 *
 * If you have found a zero, set the variable holding the count of ones before
 * the gap to the count of ones found through the gap, minus one. Then set the
 * count of ones through the gap to one and continue counting as usual.
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * TIME COMPLEXITY:
 * O(1)
 *
 * WHAT COULD YOU IMPROVE?
 * I could clean up my implementation to match the book's.
 */
#include <iostream>

int longest_flip(unsigned int n)
{
    bool in_gap = false;
    int result = 0, pregap = 0, thrugap = 0;

    if (n == 0)
        return 1;

    while (n > 0)
    {
        if (n & 1 == 1) // LSB is a 1
        {
            if (in_gap)
                ++thrugap;
            else
                ++pregap;
        }
        else // LSB is a 0
        {
            if (in_gap)
            {
                if ((pregap + thrugap) > result)
                    result = pregap + thrugap;
                pregap = thrugap - 1;
            }
            else
            {
                in_gap = true;
            }
            thrugap = 1;
        }
        n >>= 1;
    }

    if ((pregap + thrugap) > result)
        result = pregap + thrugap;

    return result;
}

int main(int argc, char** argv)
{
    std::cout << longest_flip(1775) << std::endl;
    return 0;
}
