/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) {
            return {};
        }
        vector<vector<int>> result(numRows);
        vector<int> row{1};
        result[0] = row;
        for (int i = 1; i < numRows; ++i) {
            row.push_back(1);
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
            result[i] = row;
        }
        return result;
    }

    void test() {
        assert(generate(5) == vector<vector<int>>({{1},
                                                   {1, 1},
                                                   {1, 2, 1},
                                                   {1, 3, 3, 1},
                                                   {1, 4, 6, 4, 1}}));
    }
};