// Defines the entry point for the bubble sort algorithms.
//

#include "BubbleSort.h"
#include "../Utilities/Utilities.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	vector<int> numbers = bubblesort::generate_random_numberss(5 + rand() % 10, true);
	utilities::print_numbers(numbers);
	int swaps = 0;
	do {
		swaps = bubblesort::bubble_sort_one_scan(numbers);
		utilities::print_numbers(numbers);
	} while (swaps>0);
	// cout << "Hello CMake." << endl;
	return 0;
}
