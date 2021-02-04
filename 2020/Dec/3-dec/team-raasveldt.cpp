#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int minSubarray(vector<int>& nums, int p) {
  int64_t total_sum = 0;

  for(auto entry : nums) {
    total_sum += entry;
  }
  if (total_sum % p == 0) {
    return 0;
  }
  if (total_sum < p) {
    return -1;
  }
  for(size_t current_size = 1; current_size < nums.size(); current_size++) {
    int64_t sum_difference = 0;
    size_t k;
    for(k = 0; k < current_size; k++) {
      sum_difference += nums[k]; 
    }
    for(; k < nums.size(); k++) {
      if ((total_sum - sum_difference) % p == 0) {
        return current_size;
      }
      sum_difference -= nums[k - current_size];
      sum_difference += nums[k];
    }
    if ((total_sum - sum_difference) % p == 0) {
      return current_size;
    }
  }
  return -1;
}

void test() {
  {
    vector<int> nums = {3,1,4,2};
    int p = 6;
    int answer = 1;

    int output = minSubarray(nums, p);
    if (output != answer) {
      cout << "Wrong output for test 1. Expected " << answer << ", got " << output << endl;
    }
  }
  
  {
    vector<int> nums = {6,3,5,2};
    int p = 9;
    int answer = 2;

    int output = minSubarray(nums, p);
    if (output != answer) {
      cout << "Wrong output for test 2. Expected " << answer << ", got " << output << endl;
    }
  }

  {
    vector<int> nums = {1,2,3};
    int p = 3;
    int answer = 0;

    int output = minSubarray(nums, p);
    if (output != answer) {
      cout << "Wrong output for test 3. Expected " << answer << ", got " << output << endl;
    }
  }

  {
    vector<int> nums = {1,2,3};
    int p = 7;
    int answer = -1;

    int output = minSubarray(nums, p);
    if (output != answer) {
      cout << "Wrong output for test 4. Expected " << answer << ", got " << output << endl;
    }
  }

  {
    vector<int> nums = {1000000000,1000000000,1000000000};
    int p = 3;
    int answer = 0;

    int output = minSubarray(nums, p);
    if (output != answer) {
      cout << "Wrong output for test 5. Expected " << answer << ", got " << output << endl;
    }
  }
}

int main() {
  test();
}
