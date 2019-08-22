/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
//    int longestConsecutive(vector<int> &nums) {
//        unordered_set<int> set{nums.begin(), nums.end()};
//        int result = 0;
//        for (int n:nums) {
//            if (set.find(n - 1) == set.end()) {
//                int next = n + 1;
//                while (set.find(next) != set.end()) {
//                    next++;
//                }
//                result = max(result, next - n);
//            }
//        }
//        return result;
//    }

    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set{nums.begin(), nums.end()};
        int result = 0;
        for (int n:nums) {
            if (set.find(n) != set.end()) {
                set.erase(n);
                int pre = n - 1, next = n + 1;
                while (set.find(pre) != set.end()) {
                    set.erase(pre--);
                }
                while (set.find(next) != set.end()) {
                    set.erase(next++);
                }
                result = max(result, next - pre - 1);
            }
        }
        return result;
    }

    void test() {
        vector<int> input{100, 4, 200, 1, 3, 2};
        assert(longestConsecutive(input) == 4);
    }
};