#include <vector>
namespace utilities {
	void print_numbers(std::vector<int> numbers) {
		cout << "\nNumbers:";
		for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
			cout << " " << *i;
		}
		cout << endl;
	}
}