/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result{-1, -1};
        int last = nums.size() - 1;
        if (last < 0) {
            return result;
        }
        int left = 0, right = last, mid = (left + right) / 2;
        while (left <= right) {
            if (target == nums[mid]) {
                break;
            } else {
                target > nums[mid] ? (left = mid + 1) : (right = mid - 1);
            }
            mid = (left + right) / 2;
        }
        if (target == nums[mid]) {
            left = right = mid;
            while (left > 0 && nums[left - 1] == target) left--;
            while (right < last && nums[right + 1] == target) right++;
            result[0] = left, result[1] = right;
        }
        return result;
    }

    void test() {
        vector<int> nums{5, 7, 7, 8, 8, 10};
        assert(searchRange(nums, 8) == vector<int>({3, 4}));
        assert(searchRange(nums, 6) == vector<int>({-1, -1}));
    }
};