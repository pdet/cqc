/* 
You have a collection of coins, and you know the values of the coins and the quantity of each type of coin in it. 
You want to know how many distinct sums you can make from non-empty groupings of these coins.

Example

For coins = [10, 50, 100] and quantity = [1, 2, 1], the output should be
possibleSums(coins, quantity) = 9.

Here are all the possible sums:

50 = 50;
10 + 50 = 60;
50 + 100 = 150;
10 + 50 + 100 = 160;
50 + 50 = 100;
10 + 50 + 50 = 110;
50 + 50 + 100 = 200;
10 + 50 + 50 + 100 = 210;
10 = 10;
100 = 100;
10 + 100 = 110.
As you can see, there are 9 distinct sums that can be created from non-empty groupings of your coins.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer coins

An array containing the values of the coins in your collection.

Guaranteed constraints:
1 ≤ coins.length ≤ 20,
1 ≤ coins[i] ≤ 104.

[input] array.integer quantity

An array containing the quantity of each type of coin in your collection. quantity[i] indicates the number of coins that have a value of coins[i].

Guaranteed constraints:
quantity.length = coins.length,
1 ≤ quantity[i] ≤ 105,
(quantity[0] + 1) * (quantity[1] + 1) * ... * (quantity[quantity.length - 1] + 1) <= 106.

[output] integer

The number of different possible sums that can be created from non-empty groupings of your coins.

try to compile with: g++ -std=c++11 2021/March/11-march.cpp 
*/

#include <vector>
#include <iostream>
#include <cassert>

int possibleSums(std::vector<int> coins, std::vector<int> quantity)
{
    // code here
    return 0;
}

int main(int argc, char **argv)
{

    std::vector<int> input1 = {10, 50, 100};
    std::vector<int> input2 = {1, 2, 1};
    assert(possibleSums(input1, input2) == 9);

    std::vector<int> input1_1 = {10, 50, 100, 500};
    std::vector<int> input2_1 = {5, 3, 2, 2};
    assert(possibleSums(input1_1, input2_1) == 122);

    std::vector<int> input1_2 = {1};
    std::vector<int> input2_2 = {5};
    assert(possibleSums(input1_2, input2_2) == 5);

    std::vector<int> input1_3 = {1, 1};
    std::vector<int> input2_3 = {2, 3};
    assert(possibleSums(input1_3, input2_3) == 5);

    std::vector<int> input1_4 = {1, 2};
    std::vector<int> input2_4 = {5000, 2};
    assert(possibleSums(input1_4, input2_4) == 50004);

    std::vector<int> input1_5 = {1, 1, 1, 1, 1};
    std::vector<int> input2_5 = {9, 19, 18, 12, 19};
    assert(possibleSums(input1_5, input2_5) == 77);

    std::vector<int> input1_6 = {};
    std::vector<int> input2_6 = {};
    assert(possibleSums(input1_6, input2_6) == 0);
}