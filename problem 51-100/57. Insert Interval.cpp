/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        vector<vector<int>> result;
        for (auto &interval:intervals) {
            if (interval[0] > newInterval[0]) {
                break;
            }
            result.push_back(interval);
        }
        int flag = result.size(), size = intervals.size();
        if (flag == 0 || newInterval[0] > result.back()[1]) {
            result.push_back(newInterval);
        } else if (result.back()[1] < newInterval[1]) {
            result.back()[1] = newInterval[1];
        }
        while (flag < size) {
            if (intervals[flag][0] <= newInterval[1]) {
                if (intervals[flag][1] > newInterval[1]) {
                    result.back()[1] = intervals[flag][1];
                }
            } else {
                result.push_back(intervals[flag]);
            }
            flag++;
        }
        return result;
    }

    void test() {
        vector<vector<int>> intervals{{1, 3},
                                      {6, 9}};
        vector<int> newInterval{2, 5};
        assert(insert(intervals, newInterval) == vector<vector<int>>({{1, 5},
                                                                      {6, 9}}));
        intervals = {{1,  2},
                     {3,  5},
                     {6,  7},
                     {8,  10},
                     {12, 16}};
        newInterval = {4, 8};
        assert(insert(intervals, newInterval) == vector<vector<int>>({{1,  2},
                                                                      {3,  10},
                                                                      {12, 16}}));
    }
};