/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length(), lp = p.length(), i, j, iPoint, jPoint;
        i = j = 0;
        iPoint = jPoint = -1;
        while (i < ls) {
            if (p[j] == '*') {
                iPoint = i;
                jPoint = j++;
            } else if (s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
            } else {
                if (iPoint >= 0) {
                    i = ++iPoint;
                    j = jPoint + 1;
                } else return false;
            }
        }
        while (p[j] == '*') j++;
        return j == lp;
    }

    void test() {
        assert(!isMatch("aa", "a"));
        assert(isMatch("aa", "*"));
        assert(!isMatch("cb", "?a"));
        assert(isMatch("adceb", "a*b"));
        assert(!isMatch("acdcb", "a*c?b"));
    }
};