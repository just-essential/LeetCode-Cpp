/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int result = 0, i = 0;
        stack.push(-1);
        for (auto c:s) {
            if (c == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    result = max(result, i - stack.top());
                }
            }
            i++;
        }
        return result;
    }

    void test() {
        string s("(()");
        assert(longestValidParentheses(s) == 2);
        s = ")()())";
        assert(longestValidParentheses(s) == 4);
    }
};