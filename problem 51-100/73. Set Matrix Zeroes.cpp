/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int row = matrix.size(), col = matrix[0].size(), i, j;
        // sign
        bool first_row, first_col;
        first_row = first_col = false;
        for (i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                first_col = true;
                break;
            }
        }
        for (j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                first_row = true;
                break;
            }
        }
        for (i = 1; i < row; i++) {
            if (matrix[i][0]) {
                for (j = 1; j < col; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        break;
                    }
                }
            }
        }
        for (j = 1; j < col; j++) {
            if (matrix[0][j]) {
                for (i = 1; i < row; i++) {
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                        break;
                    }
                }
            }
        }
        for (i = 1; i < row; i++) {
            for (j = 1; j < col; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (first_col) {
            for (i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
        if (first_row) {
            for (j = 0; j < col; j++)
                matrix[0][j] = 0;
        }
    }

    void test() {
        vector<vector<int>> matrix = {{1, 1, 1},
                                      {1, 0, 1},
                                      {1, 1, 1}};
        setZeroes(matrix);
        assert(matrix == vector<vector<int>>({{1, 0, 1},
                                              {0, 0, 0},
                                              {1, 0, 1}}));
        matrix = {{0, 1, 2, 0},
                  {3, 4, 5, 2},
                  {1, 3, 1, 5}};
        setZeroes(matrix);
        assert(matrix == vector<vector<int>>({{0, 0, 0, 0},
                                              {0, 4, 5, 0},
                                              {0, 3, 1, 0}}));
    }
};