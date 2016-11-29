/*
 * PROBLEM:
 * Given a real number between 0 and 1 that is passed in as a double, print the
 * binary representation. If the number cannot be represented accurately in
 * binary with at most 32 characters, print "ERROR."
 *
 * IMPLEMENTATION:
 * Each bit past the decimal point represents a negative power of two. While the
 * number is greater than zero, check if the number "has" a negative power of
 * two, starting at 2^-1 = 0.5.
 *
 * If the number does have that power of two, append "1" to the string
 * representation of the double. Otherwise, append a zero and proceed to the
 * next smallest power of two.
 *
 * TIME COMPLEXITY:
 * O(1)
 *
 * SPACE COMPLEXITY:
 * O(1)
 *
 * NOTES:
 * This solution was translated from the back of the book.
 */
#include <string>
#include <iostream>

std::string dbl_to_bin(double n)
{
    if (n >= 1 || n <= 0)
        return "ERROR";

    std::string result;
    double frac = 0.5;
    result.append(".");

    while (n > 0)
    {
        // 32 char max
        if (result.length() >= 32)
            return "ERROR";
        if (n >= frac)
        {
            result.append("1");
            n -= frac;
        }
        else
        {
            result.append("0");
        }
        frac /= 2;
    }
    return result;
}

int main(int argc, char** argv)
{
    double test = 0.125; // Should return .001
    std::cout << dbl_to_bin(test) << std::endl;
}
