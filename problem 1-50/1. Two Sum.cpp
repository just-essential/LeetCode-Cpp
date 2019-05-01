/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> table;
        int n = static_cast<int>(nums.size());
        int distance;
        vector<int> result(2);
        for (int i = 0; i < n; ++i) {
            distance = target - nums[i];
            if (table.find(distance) != table.end()) {
                result[0] = table[distance];
                result[1] = i;
                break;
            }
            table[nums[i]] = i;
        }
        return result;
    }

    void test() {
        vector<int> nums{2, 7, 11, 15};
        assert(twoSum(nums, 9) == vector<int>({0, 1}));
    }
};