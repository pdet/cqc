#include <vector>
#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace chrono;

int pedro(vector<int> nums) {
    
    bool one_present = false;
    for(int i = 0; i < nums.size(); i ++){
        if (nums[i] == 1){
            one_present = true;
        }
        else if (nums[i] < 1 || nums[i] > nums.size()){
            nums[i] = 1;
        }
    }
    if(!one_present){
        return 1;
    }
    for(int i = 0; i < nums.size(); i ++){
        int idx = nums[i] > 0 ? nums[i]-1 : nums[i]*-1 -1;
        if (nums[idx] > 0){
           nums[idx] *= -1; 
        }
        
    }
    for(int i = 1; i < nums.size(); i ++){
        if (nums[i] > 0){
            return i+1;
        }
    }
    
    return nums.size()+1;
}

int group_one(vector<int> nums) {
  bool have1 = false;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) {
      nums[i] = 0;
    } else if (nums[i] == 1) {
      have1 = true;
    }
  }
  if (!have1) {
    return 1;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      continue;
    }
    int idx = abs(nums[i]) - 1;
    if (idx >= nums.size()) {
      continue;
    }
    if (nums[idx] == 0 || idx == 0) {
      nums[idx] = -1;
    } else {
      nums[idx] *= -1;
    }
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] >= 0) {
      return i + 1;
    }
  }
  return nums.size() + 1;
}

int group_two(vector<int> array) {
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

void benchmark(vector<int> &array){
    vector<int> copy = array;
    auto start_timer = system_clock::now();
    int a_1 = pedro(copy);
    cout << "Pedro: "  << duration<double>(system_clock::now() - start_timer).count() << endl;
    
    copy = array;
    start_timer = system_clock::now();
    int a_2 = group_one(array);
    cout << "Group 1: "  << duration<double>(system_clock::now() - start_timer).count() << endl;
    
    copy = array;
    start_timer = system_clock::now();
    int a_3 = group_two(array);
    cout << "Group 2: " << duration<double>(system_clock::now() - start_timer).count() << endl;

    if (a_1 != a_2 || a_2 != a_3){
        cerr << "Pedro : " << a_1 << endl;
        cerr << "Group 1 : " << a_2 << endl;
        cerr << "Group 2 : " << a_3 << endl;

        cerr << "Function returning wrong result" << endl;
    }
}

int main(){
    std::mt19937 g(0);
    {
        cout << "Array with 10ˆ8 missing last element" << endl;
        vector <int> vec;
        for (int i = 0; i < 100000000; i ++){
            vec.push_back(i);
        }
        shuffle(vec.begin(), vec.end(), g);


        benchmark(vec);
    }

    {
        cout << "Array with 10ˆ8 missing mid element" << endl;
        vector <int> vec;
        for (int i = 0; i <= 100000000; i ++){
            if (i != 100000000/2){
                vec.push_back(i);
            }
        }
        shuffle(vec.begin(), vec.end(), g);
        benchmark(vec);
    }

    {
        cout << "Array with 10ˆ8 missing first element" << endl;
        vector <int> vec;
        for (int i = 2; i < 100000002; i ++){
            vec.push_back(i);
        }
        shuffle(vec.begin(), vec.end(), g);
        benchmark(vec);
    }

}