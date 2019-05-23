/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int i, j, left, right, temp, result = 0;
        vector<int> lefts(col, 0), rights(col, col), heights(col, 0);
        for (i = 0; i < row; i++) {
            left = 0, right = col;
            for (j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                    lefts[j] = left > lefts[j] ? left : lefts[j];
                } else {
                    heights[j] = 0;
                    left = j + 1;
                    lefts[j] = 0;
                }
            }
            for (j = col - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') rights[j] = right < rights[j] ? right : rights[j];
                else {
                    right = j;
                    rights[j] = col;
                }
            }
            for (j = 0; j < col; j++) {
                if (result < (temp = (rights[j] - lefts[j]) * heights[j])) {
                    result = temp;
                }
            }
        }
        return result;
    }

    void test() {
        vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}};
        assert(maximalRectangle(matrix) == 6);
    }
};