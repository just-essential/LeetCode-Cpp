/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int l1 = static_cast<int>(haystack.length()), l2 = static_cast<int>(needle.length()), range = l1 - l2 + 1;
        bool ok;
        int result = -1;
        for (int i = 0; i < range; ++i) {
            if (haystack[i] == needle[0]) {
                ok = true;
                for (int j = 1; j < l2; ++j) {
                    if (haystack[i + j] == needle[j]) {
                        continue;
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }

    void test() {
        assert(strStr("hello", "ll") == 2);
        assert(strStr("aaaaa", "bba") == -1);
    }
};