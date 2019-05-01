/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table{{'2', "abc"},
                                          {'3', "def"},
                                          {'4', "ghi"},
                                          {'5', "jkl"},
                                          {'6', "mno"},
                                          {'7', "pqrs"},
                                          {'8', "tuv"},
                                          {'9', "wxyz"}};
        vector<string> result;
        for (auto c : digits) {
            if (result.empty()) {
                for (auto &i:table[c]) {
                    result.emplace_back();
                    result.back().push_back(i);
                }
            } else {
                decltype(result) temp;
                for (auto &i:table[c]) {
                    for (auto item:result) {
                        item.push_back(i);
                        temp.push_back(item);
                    }
                }
                result = temp;
            }
        }
        return result;
    }

    void test() {
        auto result = letterCombinations("23");
        sort(result.begin(), result.end());
        assert(result == vector<string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    }
};