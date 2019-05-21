/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = (int) matrix.size(), cols = (int) matrix[0].size();
        if (rows == 0 || cols == 0 || matrix[0][0] > target || matrix[rows - 1][cols - 1] < target)
            return false;
        int l, r, row, col;
        l = 0, r = rows - 1;
        while (l <= r) {
            row = (l + r) / 2;
            if (matrix[row][0] <= target) l = row + 1;
            else r = row - 1;
        }
        row = l - 1;
        l = 0, r = cols - 1;
        while (l <= r) {
            col = (l + r) / 2;
            if (matrix[row][col] <= target) l = col + 1;
            else r = col - 1;
        }
        return matrix[row][l - 1] == target;
    }

    void test() {
        vector<vector<int>> matrix = {{1,  3,  5,  7},
                                      {10, 11, 16, 20},
                                      {23, 30, 34, 50}};
        assert(searchMatrix(matrix, 3));
        assert(!searchMatrix(matrix, 13));
    }
};