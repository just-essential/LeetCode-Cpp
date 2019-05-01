/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        vector<int> temp;
        function<void(int, int)> dfs = [&](int curr, int sum) {
            if (sum == target) {
                result.push_back(temp);
            } else if (sum < target) {
                for (int i = curr; i < size; ++i) {
                    if (sum + candidates[i] > target) {
                        break;
                    }
                    temp.push_back(candidates[i]);
                    dfs(i, sum + candidates[i]);
                    temp.pop_back();
                }
            }
        };
        dfs(0, 0);
        return result;
    }

    void test() {
        vector<int> candidates{2, 3, 6, 7};
        assert(combinationSum(candidates, 7) == vector<vector<int>>({{2, 2, 3},
                                                                     {7}}));
        candidates = {2, 3, 5};
        assert(combinationSum(candidates, 8) == vector<vector<int>>({{2, 2, 2, 2},
                                                                     {2, 3, 3},
                                                                     {3, 5}}));
    }
};