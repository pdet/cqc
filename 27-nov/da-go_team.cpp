#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
using namespace chrono;

struct MedianTree {
	MedianTree(int initial_median, int d) : current_median(initial_median), is_even(d % 2 == 0) {}

	int GetMedianTimesTwo() {
		if (is_even) {
			// d is even, need to interpolate
			// we have set it up so the min_tree is bigger than the max_tree
			// (aka the biggest value in the min tree holds the second part of the median)
			assert(min_tree.size() > max_tree.size());
			auto min_max = *min_tree.rbegin();
			return current_median + min_max;
		} else {
			// d is uneven, just return median times two
			return current_median * 2;
		}
	}
	void AddEntryInternal(int entry) {
		if (entry < current_median) {
			min_tree.insert(entry);
		} else {
			max_tree.insert(entry);
		}
	}

	void ReplaceEntry(int prev_value, int entry) {
		if (prev_value == current_median) {
			// remove the current median and replace it with the minimum value of the max tree
			auto min_of_max = max_tree.begin();
			current_median = *min_of_max;
			max_tree.erase(min_of_max);
		} else if (prev_value < current_median) {
			assert(min_tree.find(prev_value) != min_tree.end());
			min_tree.erase(min_tree.find(prev_value));
		} else {
			assert(max_tree.find(prev_value) != max_tree.end());
			max_tree.erase(max_tree.find(prev_value));
		}
		AddEntryInternal(entry);
		Rebalance();
	}
	void AddEntry(int entry) {
		AddEntryInternal(entry);
		Rebalance();
	}
	void Rebalance() {
		// check to see if the trees are unbalanced
		while (min_tree.size() > max_tree.size() + 1) {
			// min tree has 2 or more entries than max tree
			// set the highest entry of the min tree as the new median
			// insert the current median into the max tree
			auto max_of_min = min_tree.rbegin();
			max_tree.insert(current_median);
			current_median = *max_of_min;
			min_tree.erase(min_tree.find(*max_of_min));
		}
		while (max_tree.size() > min_tree.size()) {
			// max tree has 2 or more entries than in tree
			// set the lowest entry of the max tree as the new median
			// insert the current median into the min tree
			auto min_of_max = max_tree.begin();
			min_tree.insert(current_median);
			current_median = *min_of_max;
			max_tree.erase(min_of_max);
		}
	}

	multiset<int> min_tree;
	multiset<int> max_tree;
	int current_median;
	bool is_even;
};

//! Complete the activity_notifications function below.
int activity_notifications(vector<int>& expenditure, int d) {
	if (expenditure.size() == 0) {
		return 0;
	}
	int notification_count = 0;
	MedianTree median_tree(expenditure[0], d);
	for(int i = 1; i < expenditure.size(); i++) {
		auto current_value = expenditure[i];
		if (i >= d) {
			auto comparison_value = median_tree.GetMedianTimesTwo();
			if (current_value >= comparison_value) {
				notification_count++;
			}
			auto previous_value = expenditure[i - d];
			median_tree.ReplaceEntry(previous_value, current_value);
		} else {
			median_tree.AddEntry(current_value);
		}
	}
	return notification_count;
}

//! Add new tests
void run_tests(){
	{
		vector<int> input {2,3,4,2,3,6,8,5,4};
		int d = 5;
		assert(activity_notifications(input,d) == 2);
	}

	{
		vector<int> input {1,2,3,4,4};
		int d = 4;
		assert(activity_notifications(input,d) == 0);
	}

	{
		vector<int> input {10,20,30,40,50};
		int d = 3;
		assert(activity_notifications(input,d) == 1);
	}

}

void read_file(vector<int>& values, int&d, string file_path){
	fstream myfile(file_path, ios_base::in);
	int a;
	myfile >> d;
	myfile >> d;
	while (myfile >> a){
		values.push_back(a);
	}
}

void run_benchmark(string file_path, int expected_result){
	std::vector<int> expenditure;
	int d{};
	read_file(expenditure,d,file_path);
	auto start_timer = system_clock::now();
	int result = activity_notifications(expenditure,d);
	cout << "Benchmark " << file_path << ": "
	<< duration<double>(system_clock::now() - start_timer).count() << endl;
	if (result != expected_result){
		cout << "Benchmark " << file_path << " outputs the wrong result";
	}
}



void benchmark(){
	run_benchmark("benchmark/b_1.txt",633);
	run_benchmark("benchmark/b_2.txt",770);
	run_benchmark("benchmark/b_3.txt",1026);
	run_benchmark("benchmark/b_4.txt",492);
	run_benchmark("benchmark/b_5.txt",926);
}



int main(){
	run_tests();
	benchmark();
}