#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/**
  Problem:
    https://leetcode.com/problems/minimum-jumps-to-reach-home/

  Objective:
    A certain bug's home is on the x-axis at position x.
    Help them get there from position 0.

  The bug jumps according to the following rules:
    1. It can jump exactly a positions forward (to the right).
    2. It can jump exactly b positions backward (to the left).
    3. It cannot jump backward twice in a row.
    4. It cannot jump to any forbidden positions.
    5. The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

  Explanation:
    Given an array of integers "forbidden", where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers "a", "b", and "x", return the minimum number of jumps needed for the bug to reach its home.
    If there is no possible sequence of jumps that lands the bug on position x, return -1.

  Constraints:
    1. 1 <= forbidden.length <= 1000
    2. 1 <= a, b, forbidden[i] <= 2000
    3. 0 <= x <= 2000
    4. All the elements in forbidden are distinct.
    5. Position x is not forbidden.
*/

int minimumJumps(vector<int> forbidden, int a, int b, int x) {
        
}

int main() {
  assert(minimumJumps({14,4,18,1,15}, 3, 15, 9) == 3);
  assert(minimumJumps({8,3,16,6,12,20}, 15, 13, 11) == -1);
  assert(minimumJumps({1,6,2,14,5,17,4}, 16, 9, 7) == 2);
  assert(minimumJumps({18,13,3,9,8,14}, 3, 8, 6) == -1);
  assert(minimumJumps({5,2,10,12,18}, 8, 6, 16) == 2);
  assert(minimumJumps({4,16,3,2,13,7,9}, 11, 6, 6) == -1);
  assert(minimumJumps({128,178,147,165,63,11,150,20,158,144,136}, 61, 170, 135) == 6);
  assert(minimumJumps({}, 42, 1337, 0) == 0);
}

