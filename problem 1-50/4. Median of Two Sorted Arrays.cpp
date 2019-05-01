/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = static_cast<int>(nums1.size()), n = static_cast<int>(nums2.size());
        int i_min = 0, i_max = m, half_len = (m + n + 1) / 2;
        int i = 0, j = 0;
        while (i_min <= i_max) {
            i = (i_min + i_max) / 2;
            j = half_len - i;
            if (i < m && nums2[j - 1] > nums1[i]) {
                i_min = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                i_max = i - 1;
            } else {
                break;
            }
        }
        int max_left = i != 0 && (j == 0 || nums1[i - 1] > nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
        if ((m + n) % 2 == 1) return max_left;
        int min_right = i != m && (j == n || nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
        return (max_left + min_right) / 2.0;
    }

    void test() {
        vector<int> nums1, nums2;
        nums1 = {1, 3};
        nums2 = {2};
        assert(findMedianSortedArrays(nums1, nums2) == 2.0);
        nums1 = {1, 2};
        nums2 = {3, 4};
        assert(findMedianSortedArrays(nums1, nums2) == 2.5);
    }
};