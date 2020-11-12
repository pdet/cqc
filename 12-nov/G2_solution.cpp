// First missing positive

// Array of integers (negative or positive)


// [1, -3, 2, -4, 3, -5]

// O(n) time
// O(n) space

// O(n) time
// O(1) space

#include <vector>
#include <stdio.h>
#include <assert.h>

using namespace std;

int find_first_missing_positive_attempt1(vector<int> &array) {
	vector<bool> storage(array.size(), false);
	for(auto i = 0; i < array.size(); i++) {
		auto value = array[i];
		if (value > 0 && value < array.size() - 1) {
			storage[value - 1] = true;
		}
	}
	for(auto i = 0; i < array.size(); i++) {
		if (!storage[i]) {
			return i + 1;
		}
	}
	return array.size() + 1;
}

int find_first_missing_positive(vector<int> &array) {
	for(auto i = 0; i < array.size(); i++) {
		auto value = array[i];
		if (value > 0 && value < array.size() - 1 && i + 1 != value) {
			std::swap(array[i], array[value - 1]);
			i--;
		}
	}
	for(auto i = 0; i < array.size(); i++) {
		if (array[i] != i + 1) {
			return i + 1;
		}
	}
	return array.size() + 1;
}

int main() {
	vector<int> array1 { 3, 1, 2, 5, 982389724 };
	vector<int> array2 { 10, 8, 6, 4, 2, 9, 7, 3, 1 };
	vector<int> array3 { 1, -3, 2, -4, 3, -5};
	vector<int> array4 { 97893485, 985743853, -593859, 9583725, 948948239};
	vector<int> array5 { 1, 2, 3, 4, 5 };
	vector<int> array6 { };
	vector<int> array7 { 3, 94398, 2, 1, 982389724 };
	vector<int> test1 {1,2,0};
	assert(find_first_missing_positive(test1) == 3);

	//! Second Test
	vector<int> test2 {3,4,-1,1};
	assert(find_first_missing_positive(test2) == 2);

	//! Third Test
	vector<int> test3 {7,8,9,11,12};
	assert(find_first_missing_positive(test3) == 1);


	// vector<int> array1 { 1, 2, 3, 982389724, 5 };

	printf("Array 1, first missing positive: %d\n", find_first_missing_positive(array1));
	printf("Array 2, first missing positive: %d\n", find_first_missing_positive(array2));
	printf("Array 3, first missing positive: %d\n", find_first_missing_positive(array3));
	printf("Array 4, first missing positive: %d\n", find_first_missing_positive(array4));
	printf("Array 5, first missing positive: %d\n", find_first_missing_positive(array5));
	printf("Array 6, first missing positive: %d\n", find_first_missing_positive(array6));
	printf("Array 7, first missing positive: %d\n", find_first_missing_positive(array7));
}