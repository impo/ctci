/*
 * PROBLEM:
 * An animal shelter, which holds only dogs and cats, operates on a strictly "first
 * in, first out" basis. People must adopt either the "oldest" (based on arrival
 * time) of all animals at the shelter, or they can select whether they would
 * prefer a dog or a cat (and will receive the oldest animal of that type). They
 * cannot select which specific animal they would like. Create the data structures to
 * maintain this system and implement operations such as enqueue, dequeueAny,
 * dequeueDog, and dequeueCat. You may use the built-in LinkedList data structure.
 *
 * IMPLEMENTATION:
 * Use the STL queue structure to store a queue of dogs and a separate queue of cats.
 *
 * Each animal is stored with the Animal struct, which dictates whether or not the
 * animal is a dog and keeps track of arrival order for animals.
 *
 * When you enqueue, check the type of the animal and add it to the appropriate
 * queue.
 *
 * When you dequeue_any, compare the timestamps of the tops of the two queues and
 * pick the Animal with the lesser timestamp.
 *
 * When you dequeue_dog or dequeue_cat, just pop and return the top of the respective
 * queue.
 *
 * WHAT COULD YOU IMPROVE?
 * I could add helper functions to pop a queue and return its value at the same time.
 * This way I could avoid repeating myself.
 *
 * Furthermore, I can create a class hierarchy with Animal on top and Cat and Dog
 * inheriting from Animal. This way I can simplify my code with polymorphism.
 */
#include <cstddef>
#include <queue>

struct Animal {
	bool is_dog;
	size_t arrival_time;
};

class Shelter
{
	private:
		std::queue<Animal> dogs;
		std::queue<Animal> cats;
	public:
		void enqueue(const Animal& a)
		{
			if (a.is_dog)
				dogs.push(a);
			else
				cats.push(a);
		};

		Animal dequeue_any()
		{
			if (dogs.empty())
			{
				Animal answer = cats.front();
				cats.pop();
				return answer;
			}
			else if (cats.empty())
			{
				Animal answer = dogs.front();
				dogs.pop();
				return answer;
			}
			else
			{
				if (dogs.front().arrival_time < cats.front().arrival_time)
				{
					Animal answer = dogs.front();
					dogs.pop();
					return answer;
				}
				else
				{
					Animal answer = cats.front();
					cats.pop();
					return answer;
				}
			}
		};

		Animal dequeue_dog()
		{
			Animal answer = dogs.front();
			dogs.pop();
			return answer;
		};

		Animal dequeue_cat()
		{
			Animal answer = cats.front();
			cats.pop();
			return answer;
		};
};

int main(int argc, char** argv)
{
	return 0;
}
