/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
public:
    int search(vector<int> &nums, int target) {
        auto numsSize = nums.size();
        if (numsSize == 0) {
            return -1;
        }
        int left = 0, right = numsSize - 1, pivot = (left + right) / 2, index;
        while (nums[pivot] < nums[pivot + 1] && left <= right) {
            nums[pivot] >= nums[0] ? (left = pivot + 1) : (right = pivot - 1);
            pivot = (left + right) / 2;
        }
        left = 0, right = numsSize - 1;
        if (nums[pivot] > nums[pivot + 1]) {
            target < nums[0] ? (left = pivot + 1) : (right = pivot);
        }
        index = (left + right) / 2;
        while (left <= right) {
            if (target == nums[index]) {
                break;
            } else {
                target > nums[index] ? (left = index + 1) : (right = index - 1);
            }
            index = (left + right) / 2;
        }
        return target == nums[index] ? index : -1;
    }

    void test() {
        vector<int> nums{1};
        search(nums,0);
//        vector<int> nums{4, 5, 6, 7, 0, 1, 2};
//        assert(search(nums, 0) == 4);
//        assert(search(nums, 3) == -1);
    }
};