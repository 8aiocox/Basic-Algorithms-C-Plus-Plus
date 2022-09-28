#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>

#include <chrono>
#include <thread>
using namespace std;

namespace bubblesort {
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

	int bubble_sort_one_scan(vector<int> &numbers) {
		std::this_thread::sleep_for(7s);
		int swaps = 0;
		vector<int>::iterator prev = numbers.begin();
		for (vector<int>::iterator next = numbers.begin()+1; next != numbers.end(); prev=next++) {
			int first = *prev;
			int second = *next;
			cout << first << "<>" << second << endl;
			if (first>second) {
				*next = first;
				*prev = second;
				swaps++;
			}
		}
		return swaps;
	}

	void bubble_sort_numbers(vector<int> &numbers) {
		bool swapped = false;
		vector<int>::iterator next = numbers.begin() + 1;
		while (true) {
			if (next == numbers.end()) {
				// End reached
				if (swapped) {
					swapped = false;
					next = numbers.begin() + 1;
					continue;
				}
				// No more swaps possible.
				break;
			}
			// Previous number
			int first = *(next - 1);
			int second = *next;
			if (second<first) {
				// Set previous number
				*(next - 1) = second;
				*next = first;
				swapped = true;
			}
			next++;
		}
	}
}