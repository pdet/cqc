#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

double get_median(vector<int> &count, int pos, bool odd){
    int cur_pos = 0;
    bool finished = false;
    double median;
  for (size_t i = 0; i < count.size();i++){
        cur_pos+= count[i];

      if (cur_pos >pos){
          if (odd){
              return i;
          }
          else if (!finished){
              finished = true;
              if (cur_pos - pos > 1){
                  return i;
              }
              median = i;
          }
          else{
              median+=i;
              return median/2;
          }
      }

    } 
    return median; 
}

//! Complete the activity_notifications function below.
int activity_notifications(vector<int>& expenditure, int d) {
    int notif = 0;
    vector<int> count (201);

    for (int i = 0; i < d;i++){
        count[expenditure[i]]++;
    }
    size_t i = d - 1;
    do{
        i++;
        double median;
        if (d%2 == 0){
            median = get_median(count,d/2 -1,false);
        }
        else{
            median = get_median(count,d/2,true);
        }
        if (expenditure[i] >= 2* median){
            notif++;
        }
        count[expenditure[i-d]]--;
        count[expenditure[i]]++;
    }while (i < expenditure.size()-1);
    
    return notif;
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
