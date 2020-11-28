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


//! Complete the activity_notifications function below.
int activity_notifications(vector<int>& expenditure, int d) {
  if (expenditure.size() == 0) {
    return 0;
  }
  int notification_count = 0;
  int current_median;
  set<int> min_tree;
  set<int> max_tree;
  current_median = expenditure[0];
  for(int i = 1; i < expenditure.size(); i++) {
    auto current_value = expenditure[i];
    if (i >= d) {
      auto previous_value = expenditure[i - d];
      if (previous_value < current_median) {
        min_tree.erase(previous_value);
      } else {
        max_tree.erase(previous_value);
      }
    }
    if (current_value < current_median) {
      min_tree.insert(current_value);
    } else {
      max_tree.insert(current_value);
    }
    while (std::abs(int(min_tree.size()) - int(max_tree.size())) > 1) {
      if (min_tree.size() > max_tree.size()) {
        auto max_of_min = min_tree.rbegin();
        min_tree.erase(*max_of_min);
        max_tree.insert(current_median);
        current_median = *max_of_min;
      } else {
        auto min_of_max = max_tree.begin();
        max_tree.erase(min_of_max);
        min_tree.insert(current_median);
        current_median = *min_of_max;
      }
    }
    if (i >= d &&  current_value >= current_median * 2) {
      notification_count++;
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
	// benchmark();
}
