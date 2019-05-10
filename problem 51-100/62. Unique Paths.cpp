/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        if (n > m) {
            swap(n, m);
        }
        n--;
        for (int i = 1; i <= n; ++i) {
            result *= m + n - i;
            result /= i;
        }
        return static_cast<int>(result);
    }

    void test() {
        assert(uniquePaths(3, 2) == 3);
        assert(uniquePaths(7, 3) == 28);
    }
};