/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        vector<int> temp;
        function<void(int, int)> dfs = [&](int curr, int target) {
            if (target == 0) {
                result.push_back(temp);
            } else {
                for (int i = curr + 1; i < size; ++i) {
                    if (target < candidates[i]) {
                        break;
                    }
                    temp.push_back(candidates[i]);
                    dfs(i, target - candidates[i]);
                    temp.pop_back();
                    while (i + 1 < size && candidates[i + 1] == candidates[i]) {
                        i++;
                    }
                }
            }
        };
        dfs(-1, target);
        return result;
    }

    void test() {
        vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
        assert(combinationSum2(candidates, 8) == vector<vector<int>>({{1, 1, 6},
                                                                      {1, 2, 5},
                                                                      {1, 7},
                                                                      {2, 6}}));
        candidates = {2, 5, 2, 1, 2};
        assert(combinationSum2(candidates, 5) == vector<vector<int>>({{1, 2, 2},
                                                                      {5}}));
    }
};