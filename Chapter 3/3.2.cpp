/*
 * PROBLEM:
 * How would you design a stack which, in addition to push and pop, has a function min
 * which returns the minimum element? Push, pop, and min should all operate in O(1) time.
 *
 * IMPLEMENTATION:
 * Keep a min stack that tracks the minimum element:
 *
 * Every time an element is pushed,
 * push that element to the min stack if it is less than or equal to the top of the
 * min stack.
 *
 * Whenever you pop an element, if that element is equal to the top of the
 * min stack, pop the min stack too.
 *
 * TIME COMPLEXITY:
 * O(1) for all methods assuming static allocation; Otherwise amortized O(1).
 *
 * SPACE COMPLEXITY:
 * O(n). If we add each element in descending order, every element of all
 * will be stored in min.
 *
 * WHAT COULD YOU IMPROVE?
 * N/A, this is the same optimal solution as the book. Perhaps you could optimize
 * allocation to avoid cache misses based on your use case?
 */
#include <stack>
#include <iostream>

class MinStack {
	public:
		int top() const {
			return all.top();
		};

		int min() const {
			return minimum.top();
		};

		void push(const int& i) {
			if (minimum.empty() || min() >= i)
				minimum.push(i);
			all.push(i);
		};

		void pop() {
			if (top() == min())
				minimum.pop();
			all.pop();
		};

		bool empty() {
			return (all.empty() && minimum.empty());
		};

	private:
		std::stack<int> all;
		std::stack<int> minimum;
};

void print_stack(MinStack& s)
{
	std::stack<int> tmp;
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		tmp.push(s.top());
		s.pop();
	}
	std::cout << std::endl;
	while (!tmp.empty())
	{
		s.push(tmp.top());
		tmp.pop();
	}
}

int main(int argc, char** argv)
{
	MinStack s;
	s.push(7);
	s.push(6);
	s.push(8);
	s.push(5);
	s.push(9);
	s.push(4);
	s.push(10);
	s.push(3);

	while (!s.empty())
	{
		print_stack(s);
		std::cout << "MIN IS " << s.min() << std::endl;
		s.pop();
	}
}
