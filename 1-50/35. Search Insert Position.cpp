/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            target < nums[mid] ? (right = mid - 1) : (left = mid + 1);
        }
        return left;
    }

    void test() {
        vector<int> nums{1, 3, 5, 6};
        assert(searchInsert(nums, 5) == 2);
        assert(searchInsert(nums, 2) == 1);
        assert(searchInsert(nums, 7) == 4);
        assert(searchInsert(nums, 0) == 0);
    }
};