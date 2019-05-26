/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if (len < 4 || len > 12) {
            return {};
        }
        vector<string> result;
        vector<string> current{{}};
        auto i = 0;
        while (i >= 0) {
            if (current.back().length() == 0 || (current.back().length() == 1 && current.back()[0] != '0') ||
                (current.back().length() == 2 && current.back() + s[i] < "256")) {
                current.back().push_back(s[i]);
            } else {
                current.emplace_back();
                current.back().push_back(s[i]);
            }
            i++;
            if (i == len) {
                if (current.size() == 4) {
                    result.emplace_back();
                    for (auto &item:current) {
                        result.back().append(item + '.');
                    }
                    result.back().pop_back();
                }
                while (current.size() >= 4) {
                    i -= current.back().length();
                    current.pop_back();
                }
                current.back().pop_back();
                i--;
                while (i >= 1 && current.back().length() == 0) {
                    current.pop_back();
                    i--;
                    current.back().pop_back();
                }
                if (current[0].empty()) break;
                current.emplace_back();
            }
        }
        return result;
    }

    void test() {
        assert(restoreIpAddresses("25525511135") == vector<string>({"255.255.111.35", "255.255.11.135"}));
    }
};