/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto &i:s) {
            if (i == '[' || i == '(' || i == '{') {
                st.push(i);
            } else if (i == ']' || i == ')' || i == '}') {
                if (st.empty() || (st.top() == '[' && i != ']') || (st.top() == '(' && i != ')') ||
                    (st.top() == '{' && i != '}'))
                    return false;
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }

    void test() {
        assert(isValid("()"));
        assert(isValid("()[]{}"));
        assert(!isValid("(]"));
        assert(!isValid("([)]"));
        assert(isValid("{[]}"));
    }
};