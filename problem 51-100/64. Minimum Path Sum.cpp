/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        int i, j;
        for (i = 1; i < col; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (i = 1; i < row; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (i = 1; i < row; i++) {
            for (j = 1; j < col; j++) {
                grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
            }
        }
        return grid[row - 1][col - 1];
    }

    void test() {
        vector<vector<int>> grid{{1, 3, 1},
                                 {1, 5, 1},
                                 {4, 2, 1}};
        assert(minPathSum(grid) == 7);
    }
};