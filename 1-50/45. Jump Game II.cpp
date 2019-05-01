/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/
class Solution {
public:
    int jump(vector<int> &nums) {
        int rear = nums.size() - 1, i, j, count, maxStep, pos;
        for (i = count = 0; i < rear; i = pos) {
            count++;
            if (i + nums[i] >= rear) {
                break;
            }
            maxStep = nums[i + 1] + 1;
            pos = i + 1;
            for (j = 2; j <= nums[i]; ++j) {
                if (nums[i + j] + j > maxStep) {
                    maxStep = nums[i + j] + j;
                    pos = i + j;
                }
            }
        }
        return count;
    }

    void test() {
        vector<int> nums{2, 3, 1, 1, 4};
        assert(jump(nums) == 2);
    }
};