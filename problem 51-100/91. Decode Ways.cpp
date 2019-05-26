/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        vector<int> table(n);
        table[0] = 1;
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
            table[1]++;
        }
        if (s[1] > '0') {
            table[1]++;
        } else if (table[1] == 0) return 0;
        for (int i = 2; i < n; ++i) {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                table[i] += table[i - 2];
            }
            if (s[i] > '0') {
                table[i] += table[i - 1];
            } else if (table[i] == 0) {
                return 0;
            }
        }
        return table[n - 1];
    }

    void test() {
        assert(numDecodings("12") == 2);
        assert(numDecodings("226") == 3);
    }
};