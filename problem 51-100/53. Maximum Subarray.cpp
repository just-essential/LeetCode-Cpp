/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size(), sum, maxSum;
        maxSum = sum = nums[0];
        if (sum < 0) {
            sum = 0;
        }
        for (int i = 1; i < n; ++i) {
            sum += nums[i];
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }

    void test() {
        vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        assert(maxSubArray(nums) == 6);
    }
};