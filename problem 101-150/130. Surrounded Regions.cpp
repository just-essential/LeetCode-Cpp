/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size(), m = n ? board.front().size() : 0;
        if (n < 3 || m < 3) return;
        function<void(int, int)> lambda;
        lambda = [&](int i, int j) {
            if (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O') {
                board[i][j] = '.';
                lambda(i - 1, j), lambda(i + 1, j), lambda(i, j - 1), lambda(i, j + 1);
            }
        };
        for (int i = 0; i < n; ++i) {
            lambda(i, 0), lambda(i, m - 1);
        }
        for (int i = 1; i < m - 1; ++i) {
            lambda(0, i), lambda(n - 1, i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void test() {
        vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                      {'X', 'O', 'O', 'X'},
                                      {'X', 'X', 'O', 'X'},
                                      {'X', 'O', 'X', 'X'}};
        solve(board);
        assert(board == vector<vector<char>>({{'X', 'X', 'X', 'X'},
                                              {'X', 'X', 'X', 'X'},
                                              {'X', 'X', 'X', 'X'},
                                              {'X', 'O', 'X', 'X'}}));
    }
};