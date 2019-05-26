/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result{{}};
        sort(nums.begin(), nums.end());
        int n = nums.size(), count, preN;
        for (int i = 0; i < n; i += count) {
            count = 1;
            while (count + i < n && nums[count + i] == nums[i]) count++;
            preN = result.size();
            for (int j = 0; j < preN; ++j) {
                vector<int> temp = result[j];
                for (int k = 0; k < count; ++k) {
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }

    void test() {
        vector<int> vector1 = {1, 2, 2};
        assert(subsetsWithDup(vector1) == vector<vector<int>>({{},
                                                               {1},
                                                               {2},
                                                               {2, 2},
                                                               {1, 2},
                                                               {1, 2, 2}}));
    }
};