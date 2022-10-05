#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

namespace insertionsort {

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

}