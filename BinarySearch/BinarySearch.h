#include "../Utilities/Utilities.h"
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <thread>
using namespace std;

namespace binarysearch {
	vector<int> generate_random_numbers(int range, bool unique = true) {
		auto set = std::unordered_set<int>{};
		while (set.size() < range) {
			set.insert(5 + rand() % 101);
		}
		vector<int> numbers = { set.begin(), set.end() };
		sort(numbers.begin(), numbers.end());
		return numbers;
	}

	
	int binarysearch_scan (vector<int> numbers, int find, vector<vector<int>> & trace) {
		int from = 0;
		int end = numbers.size();
		while (true) {
			// std::this_thread::sleep_for(7s);
			int mid = from+(end - from) / 2;
			if (mid < 0) { break; }
			if (numbers[mid] == find) { return mid; }
			if (find > numbers[mid]) { from = mid + 1;}
			if (find < numbers[mid]) { end = mid-1;}
			vector<int> remaining(numbers.begin()+from, numbers.begin()+end);
			if (remaining.size()>0) { trace.push_back(remaining); }
		}
		return -1;
	}
}