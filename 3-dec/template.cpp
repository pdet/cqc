#include <iostream>
#include <vector>

using namespace std;

int minSubarray(vector<int>& nums, int p) {
  return -99;
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

