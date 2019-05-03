/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int rear = nums.size() - 1, i = 0, maxStep, step;
        while (i < rear) {
            if (i + nums[i] >= rear) return true;
            if (nums[i] == 0) return false;
            maxStep = nums[i + 1] + 1;
            step = 1;
            for (int j = 2; j <= nums[i]; ++j) {
                if (nums[i + j] + j > maxStep) {
                    maxStep = nums[i + j] + j;
                    step = j;
                }
            }
            i += step;
        }
        return true;
    }

    void test() {
        vector<int> nums{2, 3, 1, 1, 4};
        assert(canJump(nums));
        nums = {3, 2, 1, 0, 4};
        assert(!canJump(nums));
    }
};