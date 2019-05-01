/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        int left = 0, right = height.size() - 1, left_max = height[left], right_max = height[right];
        int result = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (left_max < height[left]) {
                    left_max = height[left];
                }
                result += left_max - height[left++];
            } else {
                if (right_max < height[right]) {
                    right_max = height[right];
                }
                result += right_max - height[right--];
            }
        }
        return result;
    }

    void test() {
        vector<int> nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assert(trap(nums) == 6);
    }
};