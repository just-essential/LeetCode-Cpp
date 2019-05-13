/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#define MIN(x, y) (x < y ? x : y)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length(), i, j;
        int dp[len1 + 1][len2 + 1];
        for (i = 0; i <= len2; i++) {
            dp[0][i] = i;
        }
        for (i = 1; i <= len1; i++) {
            dp[i][0] = i;
            for (j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = MIN(dp[i - 1][j - 1], MIN(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[len1][len2];
    }

    void test() {
        assert(minDistance("horse", "ros") == 3);
        assert(minDistance("intention", "execution") == 5);
    }
};