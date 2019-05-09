/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int number, i, j;
        number = 1;
        i = 0;
        n--;
        while (i << 1 < n) {
            for (j = i; j < n - i; j++) {
                result[i][j] = number++;
            }
            for (j = i; j < n - i; j++) {
                result[j][n - i] = number++;
            }
            for (j = n - i; j > i; j--) {
                result[n - i][j] = number++;
            }
            for (j = n - i; j > i; j--) {
                result[j][i] = number++;
            }
            i++;
        }
        if (i << 1 == n) {
            result[i][i] = number;
        }
        return result;
    }

    void test() {
        assert(generateMatrix(3) == vector<vector<int>>({{1, 2, 3},
                                                         {8, 9, 4},
                                                         {7, 6, 5}}));
    }
};