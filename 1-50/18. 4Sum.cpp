/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int first = 0, second, third, fourth, end = static_cast<int>(nums.size()) - 1, sum;
        vector<vector<int>> result;
        for (first = 0; first < end; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            for (fourth = end; first < fourth - 2; fourth--) {
                if (fourth < end && nums[fourth] == nums[fourth + 1]) continue;
                second = first + 1;
                third = fourth - 1;
                while (second < third) {
                    sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) {
                        result.push_back(vector<int>({nums[first], nums[second], nums[third], nums[fourth]}));
                        do {
                            second++;
                        } while (nums[second] == nums[second - 1] && second < third);
                        do {
                            third--;
                        } while (nums[third] == nums[third + 1] && second < third);
                    } else if (sum > target) {
                        third--;
                    } else {
                        second++;
                    }
                }
            }
        }
        return result;
    }

    void test() {
        vector<int> nums{1, 0, -1, 0, -2, 2};
        assert(fourSum(nums, 0) == vector<vector<int>>({{-2, -1, 1, 2},
                                                        {-2, 0,  0, 2},
                                                        {-1, 0,  0, 1}}));
    }
};