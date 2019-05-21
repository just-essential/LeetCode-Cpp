/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
class Solution {
public:
    void sortColors(vector<int> &nums) {
        // two-pass
//        for (int i = 0, zero = 0, two = nums.size() - 1; i <= two; i++) {
//            int temp = nums[i];
//            if (temp == 0) {
//                nums[i] = nums[zero];
//                nums[zero++] = temp;
//            } else if (temp == 2) {
//                nums[i--] = nums[two];
//                nums[two--] = temp;
//            }
//        }
        // one-pass
        int i = 0, j = 0;
        for (auto &num:nums) {
            int v = num;
            num = 2;
            if (v < 2) {
                nums[j++] = 1;
            }
            if (v == 0) {
                nums[i++] = 0;
            }
        }
    }

    void test() {
        vector<int> nums = {2, 0, 2, 1, 1, 0};
        sortColors(nums);
        assert(nums == vector<int>({0, 0, 1, 1, 2, 2}));
    }
};