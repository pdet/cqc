#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

//! Complete the activity_notifications function below.
int activity_notifications(vector<int>& expenditure, int d) {
  int notifications = 0;
  const int half_d = d >> 1;
  const int size = expenditure.size();
  
  if (d&1) {
    for (int i = d; i < size ; i++) {
      int smallerorequal = 0;
      const int cur_val = expenditure[i];
      for (int j = i - d; j < i; j++) {
        smallerorequal += (expenditure[j] << 1 <= cur_val);
      }
      notifications += (smallerorequal > half_d);
    }
  } else {
    for (int i = d; i < size ; i++) {
      int smallerorequal = 0;
      const int cur_val = expenditure[i];
      for (int j = i - d; j < i; j++) {
        smallerorequal += (expenditure[j] << 1 <= cur_val);
      }
      notifications += (smallerorequal > half_d);
      if (smallerorequal == half_d) {
        int maxsmaller[2] = {0,0};
        int minlarger [2] = {222,222};
        for (int j = i - d; j < i; j++) {
          const int val = expenditure[j];
          const int seq = (val << 1 <= cur_val);
          maxsmaller[ seq & (val > maxsmaller[1])] = val;
          minlarger [!seq & (val < minlarger [1])] = val;
        }
        notifications += (maxsmaller[1] + minlarger[1] <= cur_val);
      }
    }
  }

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
		vector<int> input {1,2,3,4,5};
		int d = 4;
		assert(activity_notifications(input,d) == 1);
	}

	{
		vector<int> input {1,2,4,5,5};
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
		cout << "Benchmark " << file_path << " outputs the wrong result: " << result << " != " << expected_result << endl;
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
