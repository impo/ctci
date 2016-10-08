/*
 * PROBLEM:
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
 * column are set to 0.
 *
 * IMPLEMENTATION:
 * Declare two sets of size_t's to hold the rows and columns of elements equal to zero,
 * respectively.
 *
 * Iterate through the entire matrix, inserting the coordinates of each
 * element equal to zero as iteration continues.
 *
 * Once the sets are filled with the necessary coordinates, zero out the rows and columns
 * according to the contents of the sets.
 *
 * TIME COMPLEXITY:
 * O(M * log(M) + N * log(N) + M * N). If every element of the matrix is zero, we insert
 * M elements into the set of rows and N elements into the set of columns. Then we zero
 * out every row and every column, taking M * N time.
 *
 * SPACE COMPLEXITY:
 * O(M + N), if we need to store the index of every row and the index of every column,
 * respectively.
 *
 * HOW COULD YOU IMPROVE THIS?
 * By using the first row and the first column to store whether or not a row or column
 * will be zeroed, we can reduce space complexity to zero and time complexity to O(M*N).
 */
#include <iostream>
#include <set>
#include <vector>

void find_zeros(std::set<size_t>& rows, std::set<size_t>& cols,
		const std::vector<std::vector<int>>& m)
{
	size_t R = m.size();
	size_t C = m[0].size();

	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			if (m[i][j] == 0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
}

void zero_matrix(std::vector<std::vector<int>>& m)
{
	std::set<size_t> rows, cols;
	find_zeros(rows, cols, m);
	size_t R = m.size();
	size_t C = m[0].size();
	
	for (const size_t& r : rows)
	{
		m[r].assign(C, 0);
	}

	for (const size_t& c : cols)
	{
		for (size_t i = 0; i < R; i++)
		{
			m[i][c] = 0;
		}
	}
}

void print_matrix(const std::vector<std::vector<int>>& m)
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
	std::vector<std::vector<int>> m = { { 1, 2, 3 }, { 4, 5, 0 }, { 0, 8, 9 } };
	print_matrix(m);
	zero_matrix(m);
	print_matrix(m);
}
