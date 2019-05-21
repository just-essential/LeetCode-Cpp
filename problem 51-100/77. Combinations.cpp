/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n < k) return result;
        vector<int> current(k, 1);
        int i = 1;
        while (i >= 0) {
            current[i]++;
            if (current[i] > n) {
                i--;
            } else if (i == k - 1) {
                result.push_back(current);
            } else {
                i++;
                current[i] = current[i - 1];
            }
        }
        return result;
    }

    void test() {
        assert(combine(4, 2) == vector<vector<int>>({{1, 2},
                                                     {1, 3},
                                                     {1, 4},
                                                     {2, 3},
                                                     {2, 4},
                                                     {3, 4}}));
    }
};