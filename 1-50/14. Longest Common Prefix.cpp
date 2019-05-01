/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","race car","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strings) {
        if (strings.empty()) return "";
        auto prefix = strings[0];
        auto len = strings.size(), l = prefix.size();
        for (int i = 1; i < len && l != 0; ++i) {
            decltype(l) j = 0;
            while (j < l && prefix[j] == strings[i][j]) j++;
            l = j;
        }
        return prefix.substr(0, l);
    }

    void test() {
        vector<string> strings{"flower", "flow", "flight"};
        assert(longestCommonPrefix(strings) == "fl");
        strings = {"dog", "race car", "car"};
        assert(longestCommonPrefix(strings) == "");
    }
};