/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp(n * 2, 0);
        function<void(char, int, int)> addParenthesis = [&](char parenthesis, int l, int r) {
            if (l) {
                temp[l + r - 1] = parenthesis;
            }
            if (l == n && r == n) {
                result.push_back(temp);
                return;
            }
            if (l < n) {
                addParenthesis('(', l + 1, r);
            }
            if (l > r) {
                addParenthesis(')', l, r + 1);
            }
        };
        addParenthesis('(', 1, 0);
        return result;
    }

    void test() {
        assert(generateParenthesis(3) == vector<string>({"((()))",
                                                         "(()())",
                                                         "(())()",
                                                         "()(())",
                                                         "()()()"}));
    }
};