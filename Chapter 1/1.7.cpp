/*
 * PROBLEM:
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees. Can you do this in place?
 *
 * IMPLEMENTATION:
 * First, indicate an error if the matrix is not NxN with N > 0. Next, rotate each outer
 * layer of the matrix, working inwards.
 *
 * Shift the top row of the layer to the right,
 * the right column of the layer to the bottom, the bottom row of the layer to the left,
 * and the left column of the layer to the top.
 *
 * Use a temporary variable to store the value in the top layer over each iteration, so
 * that it is possible to rotate the matrix in place.
 *
 * TIME COMPLEXITY:
 * O(N^2), as we are forced to iterate through each element of the matrix, performing
 * constant work with each iteration.
 *
 * SPACE COMPLEXITY:
 * O(1), as we do not store anything other than a few indices, along with the temp value
 * for the top part of the layer.
 *
 * WHAT COULD YOU IMPROVE?
 * I had to look at the solution in the book to solve this problem, so this solution
 * is already optimal. Hopefully next time my problem decomposition skills will improve.
 */
#include <iostream>
#include <vector>

bool rotate_matrix(std::vector<std::vector<int> >& m)
{
	if (m.size() == 0 || (m.size() != m[0].size()))
		return false;

	size_t len = m.size();
	for (size_t layer = 0; layer < len / 2; layer++)
	{
		size_t first = layer;
		size_t last = len - 1 - layer;
		for (size_t i = first; i < last; i++)
		{
			size_t offset = i - first;
			int top = m[first][i];

			// move left to top
			m[first][i] = m[last - offset][first];

			// move bottom to left
			m[last - offset][first] = m[last][last - offset];

			// move right to bottom
			m[last][last - offset] = m[i][last];

			// move top to right
			m[i][last] = top;
		}
	}
	return true;
}

void print_matrix(const std::vector<std::vector<int> >& m)
{
	for (const std::vector<int>& row : m)
	{
		for (const int& cell : row)
		{
			std::cout << cell << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
	std::vector<std::vector<int> > m = { { 1, 2}, {3, 4} };
	print_matrix(m);
	if (rotate_matrix(m))
	{
		print_matrix(m);
	}
}
