/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            i--;
            result++;
        }
        return result;
    }

    void test() {
        assert(lengthOfLastWord("Hello World") == 5);
    }
};