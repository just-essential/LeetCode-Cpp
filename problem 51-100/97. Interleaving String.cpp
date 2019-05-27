/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
        int i, j;
        dp[0][0] = true;
        for (j = 1; j <= l2; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (i = 1; i <= l1; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
            for (j = 1; j <= l2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[l1][l2];
    }

    void test() {
        assert(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
        assert(!isInterleave("aabcc", "dbbca", "aadbbcbccc"));
    }
};