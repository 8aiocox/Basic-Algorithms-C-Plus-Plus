#include <vector>
#include <iostream>
#include "BinarySearch.h"
// #include "BinarySearch.h"
using namespace std;

int main() {
	srand((unsigned)time(0));
	vector<int> numbers = binarysearch::generate_random_numbers (5 + rand() % 40, true);
	// Pick random number to search for.
	int find = numbers[rand()%numbers.size()];
	find = *(numbers.end() - 1);
	cout << "\nSearching for: " << find << endl;
	vector<vector<int>> trace;
	trace.push_back(numbers);
	int index = binarysearch::binarysearch_scan(numbers, find, trace);
	cout << "\nTrace: ";
	for (vector<vector<int>>::iterator i = trace.begin(); i != trace.end(); i++) {
		utilities::print_numbers(*i);
	}
	cout << endl;
	if (index > -1) { cout << "\nNumber " << find << " is found at position " << index + 1 << endl; }
	else { cout << "\nNumber not found!" << endl; }
}