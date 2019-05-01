/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            while (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < size; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }

    void test() {
        vector<int> nums{1, 2, 0};
        assert(firstMissingPositive(nums) == 3);
        nums = {3, 4, -1, 1};
        assert(firstMissingPositive(nums) == 2);
        nums = {7, 8, 9, 11, 12};
        assert(firstMissingPositive(nums) == 1);
    }
};