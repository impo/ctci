/*
 * PROBLEM:
 * Given a binary search tree with distinct elements, print all possible arrays
 * that could have led to this tree.
 *
 * IMPLEMENTATION:
 * Recursively weave the left and right subtrees of the tree together.
 *
 * TIME COMPLEXITY:
 * ???
 *
 * SPACE COMPLEXITY:
 * ???
 *
 * NOTES:
 * I "translated" this solution from the solution guide, and I still have a difficult
 * time understanding it. I understand the concept behind the weaving operation itself,
 * but I still have a hard time comprehending how the algorithm for weaving works.
 *
 * Furthermore, I have a difficult time understanding the concept or the process
 * behind all_sequences. Hopefully reviewing the code several times will help.
 */
#include <list>
#include <vector>

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int data = -1;
};

/* Weave lists together in all possible ways. This algorithm works by removing
 * the head from one list, recursing, and then doing the same thing with the
 * other list. */
void weave_lists(std::list<int>& first, std::list<int>& second,
		std::vector<std::list<int>>& results, std::list<int>& prefix)
{
	/* One list is empty. Add remainder to [a cloned] prefix and store result. */
	if (first.empty() || second.empty())
	{
		std::list<int> result = prefix;
		result.insert(result.end(), first.begin(), first.end());
		result.insert(result.end(), second.begin(), second.end());
		results.push_back(result);
		return;
	}

	/* Recurse with head of first added to the prefix. Removing the head
	 * will damage first, so we'll need to put it back where we found it
	 * afterwards. */
	int head_first = first.front();
	first.pop_front();
	prefix.push_back(head_first);
	weave_lists(first, second, results, prefix);
	prefix.pop_back();
	first.push_front(head_first);

	/* Do the same thing with second, damaging and then restoring the list. */
	int head_second = second.front();
	second.pop_front();
	prefix.push_back(head_second);
	weave_lists(first, second, results, prefix);
	prefix.pop_back();
	second.push_front(head_second);
}

std::vector<std::list<int>> all_sequences(Node* node)
{
	std::vector<std::list<int>> result;
	if (node == nullptr)
	{
		result.push_back(std::list<int>());
		return result;
	}

	std::list<int> prefix;
	prefix.push_back(node->data);

	/* Recurse on left and right subtrees. */
	std::vector<std::list<int>> left_seq = all_sequences(node->left);
	std::vector<std::list<int>> right_seq = all_sequences(node->right);

	/* Weave together each list from the left and right sides. */
	for (std::list<int>& left : left_seq)
	{
		for (std::list<int>& right : right_seq)
		{
			std::vector<std::list<int>> weaved;
			weave_lists(left, right, weaved, prefix);
			result.insert(result.end(), weaved.begin(), weaved.end());
		}
	}
	return result;
}

int main(int argc, char** argv)
{
	return 0;
}
