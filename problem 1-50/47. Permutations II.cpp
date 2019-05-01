/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }

    void test() {
        vector<int> nums{1, 1, 2};
        assert(permuteUnique(nums) == vector<vector<int>>({{1, 1, 2},
                                                          {1, 2, 1},
                                                          {2, 1, 1}}));
    }
};