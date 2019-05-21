/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size(), all = 1 << n, i, j, k;
        vector<vector<int>> result(all, vector<int>());
        for (i = 0; i < n; i++) {
            for (j = 1 << (i + 1); j <= all; j += 1 << (i + 1)) {
                for (k = j - (1 << i); k < j; k++) {
                    result[k].push_back(nums[i]);
                }
            }
        }
        return result;
    }

    void test() {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> result = {{},
                                      {1},
                                      {2},
                                      {1, 2},
                                      {3},
                                      {1, 3},
                                      {2, 3},
                                      {1, 2, 3}};
        assert(subsets(nums) == result);
    }
};