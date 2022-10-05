#include "InsertionSort.h"

int main() {
	unsigned int t = 0;
	cout << "t is: " << --t << endl;
	// Generate random numbers
	vector<int> numbers = insertionsort::generate_random_numbers(10+rand()%20);
	insertionsort::print_numbers(numbers);
	vector<int> outcome;
	bool end = false;
	// Insert the first number anyway
	outcome.push_back(*numbers.begin());
	for (vector<int>::iterator h = numbers.begin()+1; h != numbers.end(); h++) {
		vector<int>::iterator prev = outcome.end();
		cout << " >>insert:" << *h << endl;
		if (*(prev-1)>*h) {
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
		insertionsort::print_numbers(outcome);
	}

}