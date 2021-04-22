#include <assert.h>
#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/battleships-in-a-board/
int countBattleships(vector<vector<char>>& board) {
  int count = 0;
  
  const size_t dim1 = board.size();
  const size_t dim2 = board[0].size();
  for (size_t i = 0; i < dim1; i++) {
    for (size_t j = 0; j < dim2; j++) {
      if (board[i][j] == 'X') {
        // we found a ship
        count++;

        if(j < (dim2 - 1) && board[i][j+1] == 'X') {
          // horizontal ship
          for (; j < dim2; j++) {
            if (board[i][j] != 'X') {
              break;
            }
          }
        } else if (i > 0 && board[i - 1][j] == 'X') {
          // vertical ship
          count--;
        }
      }
    }
  }
  return count;
}

int main() {
  vector<vector<char>> board1 = {{'X','.','.','X'},
                                 {'.','X','.','X'},
                                 {'.','X','.','X'}};
  assert(countBattleships(board1) == 3);

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

