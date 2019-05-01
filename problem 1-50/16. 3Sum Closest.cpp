/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int first = 0, second, third, end = static_cast<int>(nums.size()) - 1, sum, closest =
                nums[0] + nums[1] + nums[2];
        while (first < end) {
            while (first > 0 && first < end && nums[first] == nums[first - 1]) first++;
            second = first + 1;
            third = end;
            while (second < third) {
                sum = nums[first] + nums[second] + nums[third];
                if (sum == target) {
                    return target;
                }
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                if (sum > target) {
                    third--;
                } else {
                    second++;
                }
            }
            first++;
        }
        return closest;
    }

    void test() {
        vector<int> nums{-1, 2, 1, -4};
        assert(threeSumClosest(nums, 1) == 2);
    }
};