#include <assert.h>
#include <vector>

using namespace std;

// https://leetcode.com/problems/battleships-in-a-board/
int countBattleships(vector<vector<char>>& board) {
  return 0;
}

int main() {
  vector<vector<char>> board1 = {{'X','.','.','X'},
                                 {'.','.','.','X'},
                                 {'.','.','.','X'}};
  assert(countBattleships(board1) == 2);

  vector<vector<char>> board2 = {{'X'}};
  assert(countBattleships(board2) == 1);

  vector<vector<char>> board3 = {{'.'}};
  assert(countBattleships(board3) == 0);

  vector<vector<char>> board4 = {{'X', 'X', 'X'}};
  assert(countBattleships(board4) == 1);

  vector<vector<char>> board5 = {{'X', '.', 'X'}};
  assert(countBattleships(board5) == 2);

  vector<vector<char>> board6 = {{'X','.','.','X'},
                                 {'.','X','.','X'},
                                 {'.','X','.','X'}};
  assert(countBattleships(board6) == 3);

  vector<vector<char>> board7 = {{'X','.','.','X'},
                                 {'.','X','.','X'},
                                 {'X','.','X','.'},
                                 {'X','.','.','X'}};
  assert(countBattleships(board7) == 6);
}

