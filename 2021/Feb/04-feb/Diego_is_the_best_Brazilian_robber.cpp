//! You are a professional brazilian planning to rob houses along a street. Each house has a certain amount of money stashed. 
//! All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
//! Meanwhile, adjacent houses have a security system connected,
//!   and it will automatically contact the police if two adjacent houses were broken into on the same night.

//! Given a list of non-negative integers nums representing the amount of money of each house,
//!  return the maximum amount of money you can rob tonight without alerting the police.

//! Constraints:
//! 1 <= nums.length <= 100
//! 0 <= nums[i] <= 1000
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

size_t max_two(std::vector<int>& nums, size_t left, size_t right) {
  size_t max_a{0}, max_b{0}, max_c{0};//f(n-2), f(n-1), f(n)
  for (size_t i = left; i <= right; ++i){
      max_c = std::max(max_a + nums[i], max_b);
      max_a  = max_b;
      max_b = max_c;
  }
  return max_b;
}

// int rob_helper(vector<int>& nums, size_t count, size_t offset) {
//   if (offset >= count) {
//     return 0;
//   }
  
//   int pick;
//   if (offset == 0) {
//     pick = nums[offset] + rob_helper(nums, count - 1, offset + 2);
//   } else {
//     pick = nums[offset] + rob_helper(nums, count, offset + 2);
//   }
//   int skip = rob_helper(nums, count, offset + 1);
//   return std::max(pick, skip);
// }

int rob(vector<int>& nums) {
  // return rob_helper(nums, nums.size(), 0);
  if (nums.size() <= 1) {
    return std::accumulate(nums.begin(), nums.end(), 0);
  }
  int consider_first = max_two(nums, 0, nums.size()-2);
  int skip_first = max_two(nums, 1, nums.size()-1);
  return std::max(consider_first, skip_first);
}

int main(){

	//! Matheus cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
	vector<int> test1 = {2,3,2};
	assert(rob(test1) == 3);

	//! Diego robs house 1 (money = 1) and then robs house 3 (money = 3).
	vector<int> test2 = {1,2,3,1};
	assert(rob(test2) == 4);

	//! As just an honorary brazilian, Mark sucks at robbing and jumps in an empty house
	vector<int> test3 = {0};
	assert(rob(test3) == 0);

	vector<int> test4 = {1, 1, 10, 1, 10};
	assert(rob(test4) == 20);

}

