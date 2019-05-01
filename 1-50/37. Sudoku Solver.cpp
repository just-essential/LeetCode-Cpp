/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        int rows[9] = {0}, columns[9] = {0}, subBoxes[9]{0}, numBoard[81] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i] |= 1 << num;
                    columns[j] |= 1 << num;
                    subBoxes[i / 3 * 3 + j / 3] |= 1 << num;
                    numBoard[i * 9 + j] = num;
                }
            }
        }
        function<bool(int)> setVal;
        setVal = [&](int pos) {
            while (pos < 81 && numBoard[pos]) {
                pos++;
            }
            if (pos == 81) {
                return true;
            }
            int row = pos / 9, column = pos % 9;
            int n = (row / 3) * 3 + (column / 3);
            int bits = rows[row] | columns[column] | subBoxes[n];
            for (int num = 1; num <= 9; ++num) {
                if ((1 << num & bits) == 0) {
                    rows[row] |= 1 << num;
                    columns[column] |= 1 << num;
                    subBoxes[n] |= 1 << num;
                    numBoard[pos] = num;
                    if (setVal(pos + 1)) {
                        return true;
                    }
                    rows[row] -= 1 << num;
                    columns[column] -= 1 << num;
                    subBoxes[n] -= 1 << num;
                    numBoard[pos] = 0;
                }
            }
            return false;
        };
        setVal(0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = numBoard[i * 9 + j] + '0';

            }
        }
    }

    void test() {
        vector<vector<char>> board{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
                output{
                {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
        solveSudoku(board);
        assert(board == output);
    }
};