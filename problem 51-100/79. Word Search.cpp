/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size(), m = board[0].size(), len = word.size();
        function<bool(int, int, int)> eq = [&](int i, int j, int k) {
            if (k == len) {
                return true;
            }
            if (i < 0 || i == n || j < 0 || j == m || board[i][j] != word[k]) {
                return false;
            }
            board[i][j] |= sizeof(char);
            k++;
            bool result = eq(i - 1, j, k) || eq(i + 1, j, k) || eq(i, j - 1, k) || eq(i, j + 1, k);
            board[i][j] |= sizeof(char);
            return result;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (eq(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    void test() {
        vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                      {'S', 'F', 'C', 'S'},
                                      {'A', 'D', 'E', 'E'}};
        assert(Solution().exist(board, "ABCCED"));
        assert(Solution().exist(board, "SEE"));
        assert(!Solution().exist(board, "ABCB"));
    }
};