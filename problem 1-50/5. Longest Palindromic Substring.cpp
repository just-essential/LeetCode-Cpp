/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, len = 0, n = static_cast<int>(s.length());
        for (int i = 0; i < n;) {
            int left = i - 1, right = i + 1;
            while (right < n && s[right] == s[i]) right++;
            i = right;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--, right++;
            }
            int l = right - left - 1;
            if (l > len) {
                start = left + 1;
                len = l;
            }
        }
        return s.substr(static_cast<unsigned long long int>(start), static_cast<unsigned long long int>(len));
    }

    void test() {
        assert(longestPalindrome("babad") == "bab");
        assert(longestPalindrome("cbbd") == "bb");
    }
};