/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if (sLen < tLen) {
            return 0;
        }
        vector<unsigned int> dp(tLen, 0);
        for (int i = 0; i < sLen; ++i) {
            for (int j = tLen - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    if (j == 0) {
                        ++dp[j];
                    } else {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }
        return dp[tLen - 1];
    }

    void test() {
        assert(numDistinct("rabbbit", "rabbit") == 3);
        assert(numDistinct("babgbag", "bag") == 5);
    }
};