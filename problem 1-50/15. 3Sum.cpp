/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int first = 0, second, third, end = static_cast<int>(nums.size()) - 1, sum;
        vector<vector<int>> result;
        while (first < end) {
            while (first > 0 && first < end && nums[first] == nums[first - 1]) first++;
            second = first + 1;
            third = end;
            while (second < third) {
                sum = nums[first] + nums[second] + nums[third];
                if (sum == 0) {
                    if (result.empty() || nums[first] != result.back()[0] || nums[second] != result.back()[1]) {
                        vector<int> temp{nums[first], nums[second], nums[third]};
                        result.push_back(temp);
                    }
                    third--;
                    second++;
                } else if (sum > 0) {
                    third--;
                } else {
                    second++;
                }
            }
            first++;
        }
        return result;
    }

    void test() {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        assert(threeSum(nums) == vector<vector<int>>({{-1, -1, 2},
                                                      {-1, 0,  1}}));
    }
};