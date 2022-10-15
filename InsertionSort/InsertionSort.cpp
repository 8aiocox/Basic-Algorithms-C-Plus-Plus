#include "InsertionSort.h"
#include "../Utilities/Utilities.h"

class InsertionSort {
public:
	vector<int> numbers;


	void print_numbers(std::vector<int> numbers) {
		cout << "\nNumbers:";
		for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
			cout << " " << *i;
		}
		cout << endl;
	}

	vector<int> generate_random_numbers(int range, bool unique = true) {
		auto set = std::unordered_set<int>{};
		while (set.size() < range) {
			set.insert(5 + rand() % 101);
		}
		return { set.begin(), set.end() };
	}

	InsertionSort() {
		// Generate random numbers
		numbers = generate_random_numbers(10 + rand() % 20);
		utilities::print_numbers(numbers);
	}

	void run() {
		vector<int> outcome;
		bool end = false;
		// Insert the first number anyway
		outcome.push_back(*numbers.begin());
		for (vector<int>::iterator h = numbers.begin() + 1; h != numbers.end(); h++) {
			vector<int>::iterator prev = outcome.end();
			cout << " >>insert:" << *h << endl;
			if (*(prev - 1) > *h) {
				while (true) {
					if (prev == outcome.begin()) break;
					if (*(prev - 1) < *h) {
						break;
					}
					prev--;
					cout << ">>prev:" << *prev << endl;
				}
			}
			outcome.insert(prev, *h);
			utilities::print_numbers(outcome);
		}
	}
};

int main() {
	InsertionSort* insertionSort = new InsertionSort();
	insertionSort->run();
}