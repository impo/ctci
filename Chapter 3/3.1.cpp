/*
 * PROBLEM:
 * Describe how you could use a single array to implement three stacks.
 *
 * IMPLEMENTATION:
 * Divide a fixed-length array into thirds, filling up each third with
 * a different stack.
 *
 * TIME/SPACE COMPLEXITY:
 * Not relevant as this is a conceptual question, though this implementation
 * has O(1) push, pop, and peek.
 *
 * WHAT COULD YOU IMPROVE?
 * I could make the stacks dynamically sized and fill them according to a circular buffer,
 * but it would alter the complexity of the solution dramatically.
 */
#include <iostream>
#include <cassert>

class MultiStack {
	public:
		MultiStack(size_t capacity) {
			stack_capacity = capacity;
			values = new int[num_stacks * capacity];
			sizes = new size_t[num_stacks];
		};

		~MultiStack() {
			delete values;
			delete sizes;
		};

		bool is_full(size_t stack_index) {
			return sizes[stack_index] == stack_capacity;
		};

		bool is_empty(size_t stack_index) {
			return sizes[stack_index] == 0;
		};

		size_t index_of_top(size_t stack_index) {
			size_t offset = stack_index * stack_capacity;
			size_t size = sizes[stack_index];
			return offset + size - 1;
		};

		int peek(size_t stack_index) {
			assert(!is_empty(stack_index));
			return values[index_of_top(stack_index)];
		};

		void push(size_t stack_index, int value) {
			assert(!is_full(stack_index));
			sizes[stack_index]++;
			values[index_of_top(stack_index)] = value;
		};

		int pop(size_t stack_index) {
			assert(!is_empty(stack_index));

			size_t top_index = index_of_top(stack_index);
			int value = values[top_index];
			values[top_index] = 0;

			sizes[stack_index]--;

			return value;
		};

	private:
		const static int num_stacks = 3;
		size_t stack_capacity;
		int* values;
		size_t* sizes;
};

int main(int argc, char** argv)
{
	return 0;
}
