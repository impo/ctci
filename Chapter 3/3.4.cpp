/*
 * PROBLEM:
 * Implement a MyQueue class which implements a queue using two stacks.
 *
 * IMPLEMENTATION:
 * Maintain the first stack in "queue-order" with the oldest elements at
 * the bottom and the newest elements at the top.
 *
 * In order to do this, we shift the first stack to the second stack, 
 * push an element onto the now-empty first stack, and shift all the
 * other elements back to the first stack every time we add an element.
 *
 * TIME COMPLEXITY:
 * O(1) peek, O(1) pop, O(1) isEmpty, O(n) add.
 *
 * SPACE COMPLEXITY:
 * O(1) extra space.
 *
 * WHAT COULD YOU IMPROVE?
 * I could maintain all the new elements on the first stack and all the old elements
 * on the second stack. Any time I need to peek or pop, transfer the elements from
 * the new stack to the old stack. This way we get O(1) add and O(1) isEmpty, but
 * O(n) peek and O(n) pop.
 */
#include <stack>
#include <cassert>

class MyQueue
{
	public:
		void add(const int& i)
		{
			while (!first.empty())
				second.push(value_pop(first));

			first.push(i);
			
			while (!second.empty())
				first.push(value_pop(second));
		};

		void remove()
		{
			assert(!isEmpty());
			first.pop();
		};

		int peek() const
		{
			assert(!isEmpty());
			return first.top();
		};

		bool isEmpty() const
		{
			return first.empty();
		};

	private:
		std::stack<int> first;
		std::stack<int> second;
		int value_pop(std::stack<int>& s)
		{
			int tmp = s.top();
			s.pop();
			return tmp;
		};
};

int main(int argc, char** argv)
{
	return 0;
}
