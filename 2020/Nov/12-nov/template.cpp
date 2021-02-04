#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {

}

int main(){
	//! First Test
	vector<int> test1 {1,2,0};
	assert(firstMissingPositive(test1) == 3);

	//! Second Test
	vector<int> test2 {3,4,-1,1};
	assert(firstMissingPositive(test2) == 2);

	//! Third Test
	vector<int> test3 {7,8,9,11,12};
	assert(firstMissingPositive(test3) == 1);
}