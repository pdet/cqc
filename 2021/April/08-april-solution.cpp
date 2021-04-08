/*

Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.


Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

Follow up: Can you achieve this in O(log n) time complexity?

*/

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int search(const vector<int>& nums, const int &target) {
  auto left = 0;
  auto right = nums.size() - 1;
  int middle;

  while (left <= right) {
    middle = (right + left) / 2;
    if (nums[middle] == target) {
      return middle;
    }

    if (nums[middle] >= nums[left]) {
      if (target < nums[middle] && target >= nums[left]) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    } else {
      if (target > nums[middle] && target <= nums[right]) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  }
  return -1;
}

int main(int argc, char **argv)
{
    {
      std::vector<int> nums = {4,5,6,7,0,1,2};
      int target = 0;
      assert(search(nums, target) == 4);
    }

    {
      std::vector<int> nums = {4,5,6,7,0,1,2};
      int target = 3;
      assert(search(nums, target) == -1);
    }

    {
      std::vector<int> nums = {1};
      int target = 0;
      assert(search(nums, target) == -1);
    }
}
