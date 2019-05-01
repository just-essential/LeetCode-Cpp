/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strings) {
        string sign, key;
        vector<string> signs;
        vector<vector<string>> result;
        int i, j, lineNum;
        for (const auto &str : strings) {
            sign = str;
            sort(sign.begin(), sign.end());
            signs.push_back(sign);
        }   //sign
//        for (i = 1; i < strings.size(); ++i) {
//            sign = signs[i];
//            key = strings[i];
//            j = i - 1;
//            while (j >= 0 && signs[j].compare(sign) > 0) {
//                signs[j + 1] = signs[j];
//                strings[j + 1] = strings[j];
//                j--;
//            }
//            signs[j + 1] = sign;
//            strings[j + 1] = key;
//        }   //sort
//        result.emplace_back();
//        result[0].push_back(strings[0]);
//        lineNum = 0;
//        for (i = 1; i < strings.size(); i++) {
//            if (signs[i] != signs[i - 1]) {
//                lineNum++;
//                result.emplace_back();
//            }
//            result[lineNum].push_back(strings[i]);
//        }   //squash
        map<string, vector<int>> table;
        vector<int> indexes;
        lineNum = 0;
        for (i = 0; i < signs.size(); i++) {
            table[signs[i]].push_back(i);
        }
        for (auto &group: table) {
            indexes = group.second;
            result.emplace_back();
            for (i = 0; i < indexes.size(); i++) {
                result[lineNum].push_back(strings[indexes[i]]);
            }
            lineNum++;
        }
        return result;
    }

    void test() {
        vector<string> strings{"eat", "tea", "tan", "ate", "nat", "bat"};
        assert(groupAnagrams(strings) == vector<vector<string>>({{"bat"},
                                                                 {"eat", "tea", "ate"},
                                                                 {"tan", "nat"}}));
    }
};