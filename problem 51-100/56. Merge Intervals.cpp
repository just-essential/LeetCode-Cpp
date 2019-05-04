
/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return {};
        }
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        result.push_back(intervals[0]);
        for (auto &interval:intervals) {
            auto &back = result.back().back();
            if (back < interval.front()) {
                result.push_back(interval);
            } else if (back < interval.back()) {
                back = interval.back();
            }
        }
        return result;
    }

    void test() {
        vector<vector<int>> intervals{{1,  3},
                                      {2,  6},
                                      {8,  10},
                                      {15, 18}};
        assert(merge(intervals) == vector<vector<int>>({{1,  6},
                                                        {8,  10},
                                                        {15, 18}}));
        intervals = {{1, 4},
                     {4, 5}};
        assert(merge(intervals) == vector<vector<int>>({{1, 5}}));
    }
};
// old definition
/*
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end < intervals[i].start) {
                result.push_back(intervals[i]);
            } else if (result.back().end < intervals[i].end) {
                result.back().end = intervals[i].end;
            }
        }
        return result;
    }
};
*/
