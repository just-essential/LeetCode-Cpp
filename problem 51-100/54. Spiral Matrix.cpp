/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int row = matrix.size() - 1, col = matrix[0].size() - 1;
        int i = 0, j = 0, k;
        while (i < row && j < col) {
            for (k = j; k < col; k++) {
                result.push_back(matrix[i][k]);
            }
            for (k = i; k < row; k++) {
                result.push_back(matrix[k][col]);
            }
            for (k = col; k > j; k--) {
                result.push_back(matrix[row][k]);
            }
            for (k = row; k > i; k--) {
                result.push_back(matrix[k][j]);
            }
            i++, j++;
            row--, col--;
        }
        if (i == row) {
            for (k = j; k <= col; k++) {
                result.push_back(matrix[i][k]);
            }
        } else if (j == col) {
            for (k = i; k <= row; k++) {
                result.push_back(matrix[k][j]);
            }
        }
        return result;
    }

    void test() {
        vector<vector<int>> matrix = {{1, 2, 3},
                                      {4, 5, 6},
                                      {7, 8, 9}};
        assert(spiralOrder(matrix) == vector<int>({1, 2, 3, 6, 9, 8, 7, 4, 5}));
        matrix = {{1, 2,  3,  4},
                  {5, 6,  7,  8},
                  {9, 10, 11, 12}};
        assert(spiralOrder(matrix) == vector<int>({1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));
    }
};