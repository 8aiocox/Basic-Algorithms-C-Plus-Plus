#include <vector>
#include <iostream>
using namespace std;
namespace utilities {
	void print_numbers(std::vector<int> numbers) {
		cout << "\nNumbers:";
		for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
			cout << " " << *i;
		}
	}
}