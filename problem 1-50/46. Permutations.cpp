/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        int rear = nums.size() - 1;
        int temp;
        function<void(vector<int>, int)> permuteBegin;
        permuteBegin = [&](vector<int> temps, int begin) {
            if (begin == rear) {
                result.push_back(temps);
            } else {
                permuteBegin(temps, begin + 1);
                for (int i = begin + 1; i <= rear; ++i) {
                    temp = temps[i];
                    temps[i] = temps[begin];
                    temps[begin] = temp;
                    permuteBegin(temps, begin + 1);
                }
            }
        };
        permuteBegin(nums, 0);
        return result;
    }

    void test() {
        vector<int> nums{1, 2, 3};
        assert(permute(nums) == vector<vector<int>>({{1, 2, 3},
                                                     {1, 3, 2},
                                                     {2, 1, 3},
                                                     {2, 3, 1},
                                                     {3, 1, 2},
                                                     {3, 2, 1}}));
    }
};