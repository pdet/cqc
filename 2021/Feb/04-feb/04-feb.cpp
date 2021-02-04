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

using namespace std;

int rob(vector<int>& nums) {
        
}

int main(){

	//! Matheus cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
	vector<int> test1 = {2,3,2}
	assert(rob(test1) == 3);

	//! Diego robs house 1 (money = 1) and then robs house 3 (money = 3).
	vector<int> test2 = {1,2,3,1}
	assert(rob(test2) == 4);

	//! As just an honorary brazilian, Mark sucks at robbing and jumps in an empty house
	vector<int> test3 = {0}
	assert(rob(test3) == 0);
}

