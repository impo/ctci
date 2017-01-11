/*
 * PROBLEM:
 * A monochrome screen is stored as a single array of bytes, allowing eight
 * consecutive pixels to be stored in one byte. The screen has width w, where
 * w is divisible by 8. The height of the screen, of course, can be derived from
 * the length of the array and the width. Implement a function that draws a
 * horizontal line from (x1, y) to (x2, y).
 *
 * IMPLEMENTATION:
 * Use bitmasks to fill the first and last bytes covered by the horizontal line.
 * Completely fill the bytes in between, if there are any. Check vigorously
 * for corner cases.
 *
 * SPACE COMPLEXITY:
 * O(N), where N is the number of bytes in the screen.
 *
 * TIME COMPLEXITY:
 * O(K), where K is the number of bytes to be filled.
 *
 * NOTES:
 * Solution adapted from the book.
 */
#include <vector>

void draw_line(std::vector<unsigned char>& screen, const int& width, const int& x1,
                const int& x2, const int& y)
{
    int start_offset = x1 % 8;
    int first_full_byte = x1 / 8;
    if (start_offset != 0)
        ++first_full_byte;

    int end_offset = x2 % 8;
    int last_full_byte = x2 / 8;
    if (end_offset != 7)
        --last_full_byte;

    // Set full bytes
    for (int b = first_full_byte; b <= last_full_byte; b++)
        screen[(width / 8) * y + b] = 0xFF;

    // Create masks for start and end of line
    unsigned char start_mask = 0xFF >> start_offset;
    unsigned char end_mask = ~(0xFF >> (end_offset + 1));

    // Set start and end of line
    if ((x1 / 8) == (x2 / 8)) // x1 and x2 are in the same byte
    {
        unsigned char mask = start_mask & end_mask;
        screen[(width / 8) * y + (x1 / 8)] |= mask;
    }
    else
    {
        if (start_offset != 0)
        {
            int byte_number = (width / 8) * y + first_full_byte - 1;
            screen[byte_number] |= start_mask;
        }
        if (end_offset != 7)
        {
            int byte_number = (width / 8) * y + last_full_byte + 1;
            screen[byte_number] |= end_mask;
        }
    }
}

int main(int argc, char** argv)
{
    return 0;
}
