/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int table['z' + 1] = {0};
        // count;
        for (char ch : t) {
            table[ch]++;
        }
        // init window
        int mismatched = t.length();
        int left, right;
        left = right = 0;
        for (auto ch : s) {
            if (mismatched == 0) break;
            if (table[ch]-- > 0) mismatched--;
            right++;
        }
        if (mismatched) return "";
        while (table[s[left]] < 0)
            table[s[left++]]++;
        int min_len = right - left, min_begin = left;
        // move window
        int len = s.length();
        while (right < len) {
            while (right < len && s[right] != s[left]) {
                table[s[right++]]--;
            }
            if (right == len) break;
            table[s[right++]]--;
            while (table[s[left]] < 0)
                table[s[left++]]++;
            if (right - left < min_len) {
                min_len = right - left;
                min_begin = left;
            }
        }
        return s.substr(min_begin, min_len);
    }
    void test() {
        assert(Solution().minWindow("ADOBECODEBANC", "ABC") == "BANC");
    }
};