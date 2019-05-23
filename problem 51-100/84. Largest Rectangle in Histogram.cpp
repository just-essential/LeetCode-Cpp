/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        if (!len) return 0;
        vector<int> lessFromLeft(len), lessFromRight(len);
        lessFromLeft[0] = -1;
        lessFromRight[len - 1] = len;
        int i, j;
        for (i = 1; i < len; i++) {
            j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                j = lessFromLeft[j];
            }
            lessFromLeft[i] = j;
        }
        for (i = len - 2; i >= 0; i--) {
            j = i + 1;
            while (j < len && heights[j] >= heights[i]) {
                j = lessFromRight[j];
            }
            lessFromRight[i] = j;
        }
        int result = 0, temp;
        for (i = 0; i < len; i++) {
            temp = (lessFromRight[i] - lessFromLeft[i] - 1) * heights[i];
            if (temp > result) result = temp;
        }
        return result;
    }

    void test() {
        vector<int> heights = {2, 1, 5, 6, 2, 3};
        assert(largestRectangleArea(heights) == 10);
    }
};