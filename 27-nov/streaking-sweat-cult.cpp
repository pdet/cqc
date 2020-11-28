#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <functional>

using namespace std;
using namespace chrono;


//! Complete the activity_notifications function below.
int activity_notifications(vector<int>& expenditure, int d) {
  int notifications = 0;
  for (size_t start_idx = 0; start_idx < expenditure.size() - d; start_idx++) {
    auto median = std::vector<int>(expenditure.begin() + start_idx, expenditure.begin() + start_idx + d);
    size_t median_index = median.size()/2;

    if (d % 2 != 0) {
      std::nth_element(median.begin(), median.begin()+ median_index, median.end());

      if(median[median_index] * 2 <= expenditure[start_idx + d]) {
        //printf("%ld\n", start_idx);
        notifications++;
      }
    } else {
      size_t median_index = median.size()/2 - 1;
      std::nth_element(median.begin(), median.begin() + median_index, median.end());
      auto first = median[median_index];
      std::nth_element(median.begin(), median.begin() + median_index + 1, median.end());
      auto second = median[median_index + 1];

      auto scaled_median = (first+second);
      //printf("%ld: scaled_median %d \n", start_idx, scaled_median);
      if( scaled_median <= expenditure[start_idx + d]) {
        notifications++;
      }
    }
    // if (start_idx % 10000 == 0) {
    //   std::cout << "." << std::endl;
    // }
  }
  //std::cout << std::endl;
  return notifications;
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

	{
    // windows size       15 25 35 45
		vector<int> input {10,20,30,40,50};
    //                        X
		int d = 2;
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
	cout << endl;
	run_benchmark("benchmark/b_1-.txt",2501);
	run_benchmark("benchmark/b_2-.txt",2663);
	run_benchmark("benchmark/b_3-.txt",2917);
	run_benchmark("benchmark/b_4-.txt",1858);
	run_benchmark("benchmark/b_5-.txt",1855);
}



int main(){
	// run_tests();
	benchmark();
}
