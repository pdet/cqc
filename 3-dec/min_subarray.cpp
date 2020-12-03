#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;
// prefix_sum % p equals to r = sum(arr) % p
// 
int minSubarray(vector<int>& nums, int p) {
  long sum{0};
  auto r = std::accumulate(nums.begin(), nums.end(), 0) % p;
  if (r == 0)
    return 0;
  int ans = nums.size();
  std::unordered_map<long, int> map;
  for (int i = 0; i < nums.size(); i++) {
    sum = (sum + nums[i]) % p;
    auto res = map.find((sum + p - r) % p);
    if (res != map.end()) {
      ans = std::min(i - res->second, ans);
    }
    map[sum] = i;
  }
  if (ans == nums.size())
    return -1;
  return ans;
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
//    vector<int> nums = {1,1,1};
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

