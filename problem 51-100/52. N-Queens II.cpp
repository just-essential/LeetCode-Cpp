/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> board(n, string(n, '.'));
        function<bool(int, int)> isValid;
        isValid = [&](int row, int col) -> bool {
            int i, j;
            for (i = 0; i < row; i++) {
                if (board[i][col] == 'Q') return false;
            }
            for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }
            for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }
            return true;
        };
        function<void(int)> setQueen;
        setQueen = [&](int row) {
            if (row == n) {
                result++;
            } else {
                for (int i = 0; i < n; ++i) {
                    if (isValid(row, i)) {
                        board[row][i] = 'Q';
                        setQueen(row + 1);
                        board[row][i] = '.';
                    }
                }
            }
        };
        setQueen(0);
        return result;
    }

    void test() {
        assert(totalNQueens(4) == 2);
    }
};