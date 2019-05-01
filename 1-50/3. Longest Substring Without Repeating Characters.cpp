/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> table(256, -1);
        int len = 0, start = 0, n = static_cast<int>(s.length());
        for (int i = 0; i < n; ++i) {
            if (table[s[i]] >= start) {
                if (len < i - start) len = i - start;
                start = table[s[i]] + 1;
            }
            table[s[i]] = i;
        }
        if (len < n - start) len = n - start;
        return len;
    }

    void test() {
        assert(lengthOfLongestSubstring("abcabcbb") == 3);
        assert(lengthOfLongestSubstring("bbbbb") == 1);
        assert(lengthOfLongestSubstring("pwwkew") == 3);
    }
};